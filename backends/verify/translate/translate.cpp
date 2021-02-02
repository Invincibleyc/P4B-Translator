#include "translate.h"
#include <sstream>

Translator::Translator(std::ostream &out) : out(out){
    // init main procedure
    cstring mainProcedureDeclaration;
    mainProcedure = BoogieProcedure("mainProcedure");
    mainProcedure.addDeclaration("procedure mainProcedure()\n");
    mainProcedure.addStatement("    call clear_forward();\n");
    mainProcedure.addSucc("clear_forward");
    addPred("clear_forward", "mainProcedure");
    mainProcedure.addStatement("    call clear_drop();\n");
    mainProcedure.addSucc("clear_drop");
    addPred("clear_drop", "mainProcedure");
    mainProcedure.addStatement("    call clear_valid();\n");
    mainProcedure.addSucc("clear_valid");
    addPred("clear_valid", "mainProcedure");
    mainProcedure.addStatement("    call clear_emit();\n");
    mainProcedure.addSucc("clear_emit");
    addPred("clear_emit", "mainProcedure");
    mainProcedure.addStatement("    call init.stack.index();\n");
    mainProcedure.addSucc("init.stack.index");
    addPred("init.stack.index", "mainProcedure");
    mainProcedure.setImplemented();

    // procedures = std::vector<BoogieProcedure>();

    // declare necessary types and files
    declaration = cstring("type Ref;\n");
    // declaration += "var Heap:HeapType;\n";
    // addGlobalVariables("Heap");
    declaration += "type HeaderStack = [int]Ref;\n";
    declaration += "var last:[HeaderStack]Ref;\n";
    addGlobalVariables("last");
    declaration += "var forward:bool;\n";
    addGlobalVariables("forward");
    declaration += "var isValid:[Ref]bool;\n";
    addGlobalVariables("isValid");
    declaration += "var emit:[Ref]bool;\n";
    addGlobalVariables("emit");
    declaration += "var stack.index:[HeaderStack]int;\n";
    addGlobalVariables("stack.index");
    declaration += "var size:[HeaderStack]int;\n";
    addGlobalVariables("size");
    declaration += "var drop:bool;\n";
    addGlobalVariables("drop");

    headers = std::map<cstring, const IR::Type_Header*>();
    structs = std::map<cstring, const IR::Type_Struct*>();
    globalVariables = std::set<cstring>();

    addNecessaryProcedures();
}

void Translator::addNecessaryProcedures(){
    BoogieProcedure clearForward = BoogieProcedure("clear_forward");
    clearForward.addDeclaration("procedure clear_forward();\n");
    clearForward.addDeclaration("    ensures forward==false;\n");
    clearForward.addModifiedGlobalVariables("forward");
    addProcedure(clearForward);

    BoogieProcedure clearDrop = BoogieProcedure("clear_drop");
    clearDrop.addDeclaration("procedure clear_drop();\n");
    clearDrop.addDeclaration("    ensures drop==false;\n");
    clearDrop.addModifiedGlobalVariables("drop");
    addProcedure(clearDrop);

    BoogieProcedure clearValid = BoogieProcedure("clear_valid");
    clearValid.addDeclaration("procedure clear_valid();\n");
    clearValid.addDeclaration("    ensures (forall header:Ref:: isValid[header]==false);\n");
    clearValid.addModifiedGlobalVariables("isValid");
    addProcedure(clearValid);

    BoogieProcedure clearEmit = BoogieProcedure("clear_emit");
    clearEmit.addDeclaration("procedure clear_emit();\n");
    clearEmit.addDeclaration("    ensures (forall header:Ref:: emit[header]==false);\n");
    clearEmit.addModifiedGlobalVariables("emit");
    addProcedure(clearEmit);

    BoogieProcedure initStackIndex = BoogieProcedure("init.stack.index");
    initStackIndex.addDeclaration("procedure init.stack.index();\n");
    initStackIndex.addDeclaration("    ensures (forall s:HeaderStack::stack.index[s]==0);\n");
    initStackIndex.addModifiedGlobalVariables("stack.index");
    addProcedure(initStackIndex);

    BoogieProcedure extract = BoogieProcedure("packet_in.extract");
    extract.addDeclaration("procedure packet_in.extract(header:Ref);\n");
    extract.addDeclaration("    ensures (isValid[header] == true);\n");
    extract.addModifiedGlobalVariables("isValid");
    addProcedure(extract);

    BoogieProcedure setValid = BoogieProcedure("setValid");
    setValid.addDeclaration("procedure setValid(header:Ref);\n");
    setValid.addDeclaration("    ensures (isValid[header] == true);\n");
    setValid.addModifiedGlobalVariables("isValid");
    addProcedure(setValid);

    BoogieProcedure setInvalid = BoogieProcedure("setInvalid");
    setInvalid.addDeclaration("procedure setInvalid(header:Ref);\n");
    setInvalid.addDeclaration("    ensures (isValid[header] == false);\n");
    setInvalid.addModifiedGlobalVariables("isValid");
    addProcedure(setInvalid);

    BoogieProcedure accept = BoogieProcedure("accept");
    accept.addDeclaration("procedure {:inline 1} accept()\n");
    accept.setImplemented();
    addProcedure(accept);

    BoogieProcedure reject = BoogieProcedure("reject");
    reject.addDeclaration("procedure reject();\n");
    reject.addDeclaration("    ensures drop==true;\n");
    reject.addModifiedGlobalVariables("drop");
    addProcedure(reject);

    BoogieProcedure mark_to_drop = BoogieProcedure("mark_to_drop");
    mark_to_drop.addDeclaration("procedure mark_to_drop();\n");
    mark_to_drop.addDeclaration("    ensures drop==true;\n");
    mark_to_drop.addModifiedGlobalVariables("drop");
    addProcedure(mark_to_drop);
}

void Translator::addProcedure(BoogieProcedure procedure){
    // procedures.push_back(&procedure);
    procedures[procedure.getName()] = procedure;
}

void Translator::addDeclaration(cstring decl){
    declaration += decl;
}

void Translator::addFunction(cstring op, cstring opbuiltin, cstring typeName, cstring returnType){
    cstring functionName = op+"."+typeName;
    cstring res = "\nfunction {:bvbuiltin \""+opbuiltin+"\"} "+functionName;
    res += "(left:"+typeName+", right:"+typeName+") returns("+returnType+");\n";
    addDeclaration(res);
}

void Translator::analyzeProgram(const IR::P4Program *program){
    for(auto obj:program->objects){
        if (auto typeHeader = obj->to<IR::Type_Header>()) {
            headers[typeHeader->name.toString()] = typeHeader;
        }
        else if (auto typeStruct = obj->to<IR::Type_Struct>()) {
            structs[typeStruct->name.toString()] = typeStruct;
        }
        else if (auto p4Control = obj->to<IR::P4Control>()){
            for(auto controlLocal:p4Control->controlLocals){
                if (auto p4Action = controlLocal->to<IR::P4Action>()){
                    actions[p4Action->name.toString()] = p4Action;
                }
            }
        }
    }
}

void Translator::incIndent(){ indent++; }
void Translator::decIndent(){ if(indent>0) indent--; }
cstring Translator::getIndent(){
    cstring res("");
    for(int i = 0; i < indent; i++) res += "    ";
    return res;
}

void Translator::addGlobalVariables(cstring variable){
    globalVariables.insert(variable);
}

bool Translator::isGlobalVariable(cstring variable){
    return globalVariables.find(variable)!=globalVariables.end();
}

void Translator::updateModifiedVariables(cstring variable){
    currentProcedure->addModifiedGlobalVariables(variable);
}

void Translator::addPred(cstring proc, cstring predProc){
    // if(pred[proc]==nullptr)
    //     pred[proc] = std::vector<cstring>(0);
    pred[proc].push_back(predProc);
}

void Translator::writeToFile(){
    addProcedure(mainProcedure);
    std::queue<BoogieProcedure*> queue;
    // queue.push(&mainProcedure);
    for (std::map<cstring, BoogieProcedure>::iterator iter=procedures.begin();
        iter!=procedures.end(); iter++){
        queue.push(&iter->second);
    }
    while(!queue.empty()){
        BoogieProcedure* procedure = queue.front();
        int szBefore = procedure->getModifiesSize();
        for(cstring succ:procedure->succ){
            for (std::set<cstring>::iterator iter=procedures[succ].modifies.begin();
                iter!=procedures[succ].modifies.end(); iter++){
                procedure->addModifiedGlobalVariables(*iter);
            }
        }
        int szAfter = procedure->getModifiesSize();
        if(szBefore!=szAfter){
            for(cstring predProc:pred[procedure->getName()]){
                queue.push(&procedures[predProc]);
            }
        }
        queue.pop();
    }

    out << declaration;
    // out << "\n";
    // out << mainProcedure.toString();
    // std::cout << mainProcedure.getName() << std::endl;
    // std::cout << "Succ:" << std::endl;
    // for(cstring succ:mainProcedure.succ){
    //     std::cout << "  " << succ << std::endl;
    // }
    // for(BoogieProcedure procedure:procedures){
    //     out << "\n";
    //     out << procedure.toString();
    // }
    std::map<cstring, BoogieProcedure>::iterator iter;
    for (iter=procedures.begin(); iter!=procedures.end(); iter++){
        if(iter->first != deparser){
            // std::cout << iter->first << std::endl;
            // std::cout << "Succ:" << std::endl;
            // for(cstring succ:iter->second.succ){
            //     std::cout << "  " << succ << std::endl;
            // }
            // std::cout << std::endl;
            out << "\n";
            out << iter->second.toString();
        }
    }
}

void Translator::translate(const IR::Node *node){
    if (auto typeStruct = node->to<IR::Type_Struct>()) {
        translate(typeStruct);
    }
    else if (auto typeError = node->to<IR::Type_Error>()) {
        translate(typeError);
    }
    else if (auto typeExtern = node->to<IR::Type_Extern>()) {
        translate(typeExtern);
    }
    else if (auto typeEnum = node->to<IR::Type_Enum>()) {
        translate(typeEnum);
    }
    else if (auto typeParser = node->to<IR::Type_Parser>()) {
        translate(typeParser);
    }
    else if (auto typeControl = node->to<IR::Type_Control>()) {
        translate(typeControl);
    }
    else if (auto typePackage = node->to<IR::Type_Package>()) {
        translate(typePackage);
    }
    else if (auto typeHeader = node->to<IR::Type_Header>()) {
        translate(typeHeader);
    }
    else if (auto p4Parser = node->to<IR::P4Parser>()) {
        translate(p4Parser);
    }
    else if (auto p4Control = node->to<IR::P4Control>()) {
        translate(p4Control);
    }
    else if (auto method = node->to<IR::Method>()) {
        translate(method);
    }
    else if (auto instance = node->to<IR::Declaration_Instance>()) {
        translate(instance);
    }
    else{
        std::cout << node->node_type_name() << std::endl;
        // translate(obj);
    }
}

void Translator::translate(const IR::Node *node, cstring arg){
    std::cout << node->node_type_name() << std::endl;
}

cstring Translator::translate(const IR::StatOrDecl *statOrDecl){
    if (auto stat = statOrDecl->to<IR::Statement>()) {
        return translate(stat);
    }
    else if (auto decl = statOrDecl->to<IR::Declaration>()) {
        return translate(decl);
    }
    return "";
}

cstring Translator::translate(const IR::Statement *stat){
    if (auto methodCall = stat->to<IR::MethodCallStatement>()){
        return translate(methodCall);
    }
    else if (auto ifStatement = stat->to<IR::IfStatement>()){
        return translate(ifStatement);
    }
    else if (auto blockStatement = stat->to<IR::BlockStatement>()){
        return translate(blockStatement);
    }
    else if (auto assignmentStatement = stat->to<IR::AssignmentStatement>()){
        return translate(assignmentStatement);
    }
    return "";
}

cstring Translator::translate(const IR::ExitStatement *exitStatement){ return ""; }
cstring Translator::translate(const IR::ReturnStatement *returnStatement){ return ""; }
cstring Translator::translate(const IR::EmptyStatement *emptyStatement){ return ""; }

cstring Translator::translate(const IR::AssignmentStatement *assignmentStatement){
    cstring res = "";
    cstring left = translate(assignmentStatement->left);
    updateModifiedVariables(left);
    res = getIndent()+left+" := "
        +translate(assignmentStatement->right)+";\n";
    if(left=="standard_metadata.egress_spec"){
        res += getIndent()+"forward := true;\n";
        currentProcedure->addModifiedGlobalVariables("forward");
    }

    return res;
}

cstring Translator::translate(const IR::IfStatement *ifStatement){
    cstring res = "";
    res += getIndent()+"if(";
    res += translate(ifStatement->condition);
    res += "){\n";
    incIndent();
    res += translate(ifStatement->ifTrue);
    decIndent();
    res += getIndent()+"}\n";
    if(ifStatement->ifFalse!=nullptr){
        res += getIndent()+"else{\n";
        incIndent();
        res += translate(ifStatement->ifFalse);
        decIndent();
        res += getIndent()+"}\n";
    }
    return res;
}

cstring Translator::translate(const IR::BlockStatement *blockStatement){
    cstring res = "";
    for(auto statOrDecl:blockStatement->components){
        res += translate(statOrDecl);
    }
    return res;
}

cstring Translator::translate(const IR::MethodCallStatement *methodCallStatement){
    cstring expr = translate(methodCallStatement->methodCall);
    if(expr.find("verify_checksum") != nullptr){
        return getIndent()+"// verify_checksum\n";
    }
    else if(expr.find("update_checksum") != nullptr){
        return getIndent()+"// update_checksum\n";
    }
    return getIndent()+"call "+expr+";\n";
}

cstring Translator::translate(const IR::SwitchStatement *switchStatement){
    return "";
}

// Expression
cstring Translator::translate(const IR::Expression *expression){
    if (auto methodCall = expression->to<IR::MethodCallStatement>()){
        return translate(methodCall);
    }
    else if (auto member = expression->to<IR::Member>()){
        return translate(member);
    }
    else if (auto pathExpression = expression->to<IR::PathExpression>()){
        return translate(pathExpression);
    }
    else if (auto selectExpression = expression->to<IR::SelectExpression>()){
        return translate(selectExpression);
    }
    else if (auto methodCallExpression = expression->to<IR::MethodCallExpression>()){
        return translate(methodCallExpression);
    }
    else if (auto opBinary = expression->to<IR::Operation_Binary>()){
        return translate(opBinary);
    }
    else if (auto constant = expression->to<IR::Constant>()){
        return translate(constant);
    }
    else if (auto constructorCallExpression = expression->to<IR::ConstructorCallExpression>()){
        return translate(constructorCallExpression);
    }
    return "";
}

cstring Translator::translate(const IR::MethodCallExpression *methodCallExpression){
    cstring res = "";
    cstring method = translate(methodCallExpression->method);

    std::string s = method.c_str();
    std::string::size_type idx = s.find("isValid");
    if(idx != std::string::npos){
        int i = idx;
        return "isValid["+s.substr(0, idx-1)+"]";
        // std::cout << s.substr(0, idx-1) << std::endl;
        // std::cout << "find... " << i << std::endl;
    }
    // if(method.find("isValid") != nullptr){
    //     std::string s = method.c_str();
    //     std::cout << "find... " << s.find("isValid") << std::endl;
    // }

    currentProcedure->addSucc(method);
    addPred(method, currentProcedure->getName());

    res += method+"(";
    int cnt = methodCallExpression->arguments->size();
    for(auto arg:*methodCallExpression->arguments){
        res += translate(arg);
        cnt--;
        if(cnt != 0)
            res += ", ";
    }
    res += ")";
    // TODO: succ
    return res;
}

cstring Translator::translate(const IR::Member *member){
    // std::cout << "member: " << member->member.toString() << std::endl;
    if(member->member.toString()=="extract")
        return "packet_in.extract";
    return translate(member->expr)+"."+member->member.toString();
}

cstring Translator::translate(const IR::PathExpression *pathExpression){
    return translate(pathExpression->path);
}

cstring Translator::translate(const IR::Path *path){
    return path->name.toString();
}

cstring Translator::translate(const IR::Declaration *decl){
    if (auto p4Action = decl->to<IR::P4Action>()){
        translate(p4Action);
    }
    else if (auto p4Table = decl->to<IR::P4Table>()){
        translate(p4Table);
    }
    return "";
}

cstring Translator::translate(const IR::SelectExpression *selectExpression){
    cstring res = "";
    int cnt = selectExpression->selectCases.size();
    for(auto selectCase:selectExpression->selectCases){
        if (auto defaultExpression = selectCase->keyset->to<IR::DefaultExpression>()){
            cstring nextState = translate(selectCase->state);
            res += getIndent()+"else{\n";
            incIndent();
            res += getIndent()+"call "+nextState+"();\n";
            currentProcedure->addSucc(nextState);
            addPred(nextState, currentProcedure->getName());
            decIndent();
            res += getIndent()+"}\n";
        }
        else{
            cstring nextState = translate(selectCase->state);
            if(cnt == selectExpression->selectCases.size())
                res += getIndent()+"if(";
            else
                res += getIndent()+"else if(";

            int sz = selectExpression->select->components.size();
            int cnt2 = 0;
            for(auto expr:selectExpression->select->components){
                res += translate(expr);
                res += " == ";
                if(auto constant = selectCase->keyset->to<IR::Constant>()){
                    std::stringstream ss;
                    ss << constant->value;
                    res += ss.str()+translate(constant->type);
                }
                cnt2++;
                // TODO: Mask
                if(cnt2 < sz)
                    res += " && ";
            }
            res += "){\n";
            incIndent();
            res += getIndent()+"call "+nextState+"();\n";
            currentProcedure->addSucc(nextState);
            addPred(nextState, currentProcedure->getName());
            decIndent();
            res += getIndent()+"}\n";
        }
        cnt--;
    }
    return res;
}

cstring Translator::translate(const IR::Argument *argument){
    return translate(argument->expression);
}

cstring Translator::translate(const IR::Constant *constant){
    std::stringstream ss;
    ss << constant->value;
    return ss.str()+translate(constant->type);
}

cstring Translator::translate(const IR::ConstructorCallExpression *constructorCallExpression){
    return translate(constructorCallExpression->constructedType);
}

// Type
cstring Translator::translate(const IR::Type *type){
    if (auto typeBits = type->to<IR::Type_Bits>()){
        return translate(typeBits);
    }
    else if (auto typeBoolean = type->to<IR::Type_Boolean>()){
        return translate(typeBoolean);
    }
    else if (auto typeSpecialized = type->to<IR::Type_Specialized>()){
        return translate(typeSpecialized);
    }
    else if (auto typeName = type->to<IR::Type_Name>()){
        return translate(typeName);
    }
    return "";
}

cstring Translator::translate(const IR::Type_Bits *typeBits){
    std::stringstream ss;
    ss << "bv" << typeBits->size;
    return ss.str();
}

cstring Translator::translate(const IR::Type_Boolean *typeBoolean){
    return "bool";
}

cstring Translator::translate(const IR::Type_Specialized *typeSpecialized){
    return typeSpecialized->baseType->toString();
}

cstring Translator::translate(const IR::Type_Name *typeName){
    return translate(typeName->path);
}

cstring Translator::translate(const IR::Operation_Binary *opBinary){
    cstring typeName = translate(opBinary->left->type);
    cstring returnType = translate(opBinary->type);
    if (auto shl = opBinary->to<IR::Shl>()) {
        addFunction("shl", "bvshl", typeName, returnType);
        return "shl."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto shr = opBinary->to<IR::Shr>()) {
        addFunction("shr", "bvlshr", typeName, returnType);
        return "shr."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto mul = opBinary->to<IR::Mul>()) {
        addFunction("mul", "bvmul", typeName, returnType);
        return "mul."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto add = opBinary->to<IR::Add>()) {
        addFunction("add", "bvadd", typeName, returnType);
        return "add."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto addSat = opBinary->to<IR::AddSat>()) {
        addFunction("add", "bvadd", typeName, returnType);
        return "add."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto sub = opBinary->to<IR::Sub>()) {
        addFunction("sub", "bvsub", typeName, returnType);
        return "sub."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto subSat = opBinary->to<IR::SubSat>()) {
        addFunction("sub", "bvsub", typeName, returnType);
        return "sub."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto bAnd = opBinary->to<IR::BAnd>()) {
        addFunction("band", "bvand", typeName, returnType);
        return "band."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto bOr = opBinary->to<IR::BOr>()) {
        addFunction("bor", "bvor", typeName, returnType);
        return "bor."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto bXor = opBinary->to<IR::BXor>()) {
        addFunction("bxor", "bvxor", typeName, returnType);
        return "bxor."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto geq = opBinary->to<IR::Geq>()) {
        addFunction("bsge", "bvsge", typeName, returnType);
        return "bsge."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto leq = opBinary->to<IR::Leq>()) {
        addFunction("bsle", "bvsle", typeName, returnType);
        return "bsle."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto grt = opBinary->to<IR::Grt>()) {
        addFunction("bugt", "bvugt", typeName, returnType);
        return "bugt."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto lss = opBinary->to<IR::Lss>()) {
        addFunction("bult", "bvult", typeName, returnType);
        return "bult."+typeName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
    }
    else if (auto arrayIndex = opBinary->to<IR::ArrayIndex>()) {
        return "";
    }
    else
        return "("+translate(opBinary->left)+") "+opBinary->getStringOp()+" ("+translate(opBinary->right)+")";
}

void Translator::translate(const IR::P4Program *program){
    analyzeProgram(program);
    // std::cout << "translate P4Program" << std::endl;
    // Add main program

    // Translate objects
    for(auto obj:program->objects){
        translate(obj);
    }
}

void Translator::translate(const IR::Type_Error *typeError){
    // std::cout << "translate Type_Error" << std::endl;
}

void Translator::translate(const IR::Type_Extern *typeExtern){
    // std::cout << "translate Type_Extern" << std::endl;
}

void Translator::translate(const IR::Type_Enum *typeEnum){
    // std::cout << "translate Type_Enum" << std::endl;
}

void Translator::translate(const IR::Declaration_Instance *instance){
    cstring typeName = translate(instance->type);
    cstring name = instance->name.toString();
    std::cout << typeName << std::endl;
    std::cout << name << std::endl;
    if(typeName=="V1Switch"){
        BoogieProcedure main = BoogieProcedure(name);
        main.addDeclaration("procedure {:inline 1} "+name+"()\n");
        incIndent();
        int cnt = instance->arguments->size();
        for(auto argument:*instance->arguments){
            cnt--;
            if(cnt != 0){
                cstring procName = translate(argument->expression);
                main.addStatement(getIndent()+"call "+procName+"();\n");
                main.addSucc(procName);
                addPred(procName, name);
            }
            else
                deparser = translate(argument->expression);
        }
        decIndent();
        // add children
        addProcedure(main);
        mainProcedure.addStatement("    call "+name+"();\n");
        mainProcedure.addSucc(name);
        addPred(name, mainProcedure.getName());
    }
}

void Translator::translate(const IR::Type_Struct *typeStruct){
    cstring structName = typeStruct->name.toString();
    addDeclaration("\n// Struct "+structName+"\n");
    if(structName=="headers"){
        for(const IR::StructField* field:typeStruct->fields){
            translate(field, "hdr");
        }
    }
    else if(structName=="metadata"){
        for(const IR::StructField* field:typeStruct->fields){
            translate(field, "meta");
        }
    }
    else if(structName=="standard_metadata_t"){
        for(const IR::StructField* field:typeStruct->fields){
            translate(field, "standard_metadata");
        }
    }
}

void Translator::translate(const IR::Type_Struct *typeStruct, cstring arg){
    for(const IR::StructField* field:typeStruct->fields){
        translate(field, arg);
    }
}

void Translator::translate(const IR::StructField *field){
    // std::cout << "translate StructField" << std::endl;
}

void Translator::translate(const IR::StructField *field, cstring arg){
    if(field->type->node_type_name() == "Type_Name"){
        cstring fieldName = field->type->toString();
        std::map<cstring, const IR::Type_Header*>::iterator iter1 = headers.find(fieldName);
        std::map<cstring, const IR::Type_Struct*>::iterator iter2 = structs.find(fieldName);
        if(iter1!=headers.end()){
            translate(iter1->second, arg+"."+field->name);
        }
        else if(iter2!=structs.end()){
            translate(iter2->second, arg+"."+field->name);
        }
        // else: typeDef

        // std::cout << "finding " << fieldName << std::endl;
        // std::cout << (headers.find(fieldName)!=headers.end()) << std::endl;
        // std::cout << (structs.find(fieldName)!=structs.end()) << std::endl;
    }
    else if(field->type->node_type_name() == "Type_Bits"){
        auto typeBits = field->type->to<IR::Type_Bits>();
        addDeclaration("var "+arg+"."+field->name+":bv"+std::to_string(typeBits->size)+";\n");
        addGlobalVariables(arg+"."+field->name);
    }
    else if(field->type->node_type_name() == "Type_Stack"){

    }
}

void Translator::translate(const IR::Type_Header *typeHeader){
    // for(const IR::StructField* field:typeHeader->fields){
    //     translate(field);
    // }
    // std::cout << "translate typeHeader" << std::endl;
}

void Translator::translate(const IR::Type_Header *typeHeader, cstring arg){
    addDeclaration("\n// Header "+typeHeader->name.toString()+"\n");
    addDeclaration("var "+arg+":Ref;\n");
    addGlobalVariables(arg);
    for(const IR::StructField* field:typeHeader->fields){
        translate(field, arg);
    }
}

void Translator::translate(const IR::Type_Parser *typeParser){
    // std::cout << "translate Parser" << std::endl;
}

void Translator::translate(const IR::Type_Control *typeControl){
    // std::cout << "translate Control" << std::endl;
}

void Translator::translate(const IR::Type_Package *typePackage){
    // std::cout << "translate package" << std::endl;
}

void Translator::translate(const IR::P4Parser *p4Parser){
    cstring parserName = p4Parser->name.toString();
    BoogieProcedure parser = BoogieProcedure(parserName);
    parser.addDeclaration("\n// Parser "+parserName+"\n");
    parser.addDeclaration("procedure {:inline 1} "+parserName+"()\n");
    parser.addStatement("    call start();\n");
    parser.addSucc("start");
    addPred("start", parserName);
    addProcedure(parser);
    for(auto state:p4Parser->states){
        translate(state);
    }
    // TODO: parser local variables
}

void Translator::translate(const IR::ParserState *parserState){
    cstring stateName = parserState->name.toString();
    if(stateName=="accept" || stateName=="reject")
        return;
    BoogieProcedure state = BoogieProcedure(stateName);
    currentProcedure = &state;
    state.addDeclaration("\n//Parser State "+stateName+"\n");
    state.addDeclaration("procedure {:inline 1} "+stateName+"()\n");
    incIndent();
    for(auto statOrDecl:parserState->components){
        state.addStatement(translate(statOrDecl));
    }
    if(parserState->selectExpression!=nullptr){
        if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
            cstring nextState = translate(pathExpression);
            state.addStatement(getIndent()+"call "+nextState+"();\n");
            state.addSucc(nextState);
            addPred(nextState, stateName);
        }
        else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
            state.addStatement(translate(parserState->selectExpression));
        }
    }
    // TODO: add succ
    decIndent();
    addProcedure(state);
}

void Translator::translate(const IR::P4Control *p4Control){
    cstring controlName = p4Control->name.toString();
    BoogieProcedure control = BoogieProcedure(controlName);
    currentProcedure = &control;
    control.addDeclaration("\n// Control "+controlName+"\n");
    control.addDeclaration("procedure {:inline 1} "+controlName+"()\n");
    incIndent();
    for(auto statOrDecl:p4Control->body->components){
        control.addStatement(translate(statOrDecl));
    }
    decIndent();
    addProcedure(control);
    for(auto controlLocal:p4Control->controlLocals){
        translate(controlLocal);
    }
}

void Translator::translate(const IR::Method *method){
    // std::cout << "translate method" << std::endl;
}

void Translator::translate(const IR::P4Action *p4Action){
    cstring actionName = p4Action->name.toString();
    BoogieProcedure action = BoogieProcedure(actionName);
    currentProcedure = &action;
    action.addDeclaration("\n// Action "+actionName+"\n");
    action.addDeclaration("procedure {:inline 1} "+actionName+"(");
    int cnt = p4Action->parameters->parameters.size();
    for(auto parameter:p4Action->parameters->parameters){
        action.addDeclaration(translate(parameter));
        cnt--;
        if(cnt != 0)
            action.addDeclaration(", ");
    }
    action.addDeclaration(")\n");
    incIndent();
    action.addStatement(translate(p4Action->body));
    decIndent();
    addProcedure(action);
}

void Translator::translate(const IR::P4Table *p4Table){
    cstring name = p4Table->name.toString();
    cstring tableName = name+".apply";
    BoogieProcedure table = BoogieProcedure(tableName);
    table.addDeclaration("\n// Table "+name+"\n");
    table.addDeclaration("procedure {:inline 1} "+tableName+"()\n");
    addDeclaration("\n// Table "+name+" Actionlist Declaration\n");
    addDeclaration("type "+name+".action;\n");
    incIndent();
    for(auto property:p4Table->properties->properties){
        if (auto actionList = property->value->to<IR::ActionList>()) {
            // add local variables
            for(auto actionElement:actionList->actionList){
                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                    cstring actionName = translate(actionCallExpr->method);
                    const IR::P4Action* action = actions[actionName];
                    for(auto parameter:action->parameters->parameters){
                        table.addStatement("    var "+actionName+"."+translate(parameter)+";\n");
                    }
                }
            }
            // TODO: add keys
            // add action call statements
            int cnt = actionList->actionList.size();
            for(auto actionElement:actionList->actionList){
                if(cnt == actionList->actionList.size())
                    table.addStatement(getIndent()+"if(");
                else
                    table.addStatement(getIndent()+"else if(");
                cnt--;
                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                    cstring actionName = translate(actionCallExpr->method);
                    table.addStatement(name+".action_run == "+name+".action."+actionName+"){\n");
                    incIndent();
                    const IR::P4Action* action = actions[actionName];
                    table.addStatement(getIndent()+"call "+actionName+"(");
                    table.addSucc(actionName);
                    addPred(actionName, tableName);
                    int cnt2 = action->parameters->parameters.size();
                    for(auto parameter:action->parameters->parameters){
                        cnt2--;
                        table.addStatement(actionName+"."+parameter->name.toString());
                        if(cnt2 != 0)
                            table.addStatement(", ");
                    }
                    table.addStatement(");\n");
                    decIndent();
                }
                table.addStatement(getIndent()+"}\n");
            }
            // add action declaration
            translate(actionList, name+".action");
        }
    }
    addDeclaration("var "+name+".action_run : "+name+".action;\n");
    addGlobalVariables(name+".action_run");
    decIndent();
    addProcedure(table);
}

cstring Translator::translate(const IR::Parameter *parameter){
    return parameter->name.toString()+":"+translate(parameter->type);
}

void Translator::translate(const IR::ActionList *actionList, cstring arg){
    cstring limitName = arg+"_run.limit";
    BoogieProcedure limit = BoogieProcedure(limitName);
    limit.addModifiedGlobalVariables(arg+"_run");
    limit.addDeclaration("\nprocedure "+limitName+"();\n");
    limit.addDeclaration("    ensures(");
    int cnt = actionList->actionList.size();
    for(auto actionElement:actionList->actionList){
        cnt--;
        if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
            cstring actionName = translate(actionCallExpr->method);
            addDeclaration("const unique "+arg+"."+actionName+" : "+arg+";\n");
            limit.addDeclaration(arg+"_run=="+arg+"."+actionName);
        }
        if(cnt > 0){
            limit.addDeclaration(" || ");
        }
    }
    limit.addDeclaration(");\n");
    addProcedure(limit);
    mainProcedure.addFrontStatement("    call "+limitName+"();\n");
    mainProcedure.addSucc(limitName);
    addPred(limitName, mainProcedure.getName());
    //TODO: add children
}