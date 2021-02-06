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
    // globalVariables = std::set<cstring>();

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
    cstring functionName = op+".";
    if(returnType!="bool")
        functionName += returnType;
    else
        functionName += typeName;
    if(functions.find(functionName)==functions.end()){
        functions.insert(functionName);
        cstring res = "\nfunction {:bvbuiltin \""+opbuiltin+"\"} "+functionName;
        if(returnType!="bool")
            res += "(left:"+returnType+", right:"+returnType+") returns("+returnType+");\n";
        else
            res += "(left:"+typeName+", right:"+typeName+") returns("+returnType+");\n";
        addDeclaration(res);
    }
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
                    actions[translate(p4Action->name)] = p4Action;
                }
            }
        }
    }
}

cstring Translator::translate(IR::ID id){
    return id.name;
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
        for (std::set<cstring>::iterator iter2=iter->second.modifies.begin();
            iter2!=iter->second.modifies.end();){
            if(!isGlobalVariable(*iter2))
                iter->second.modifies.erase(iter2++);
            else
                ++iter2;
        }
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
            // out << "\n";
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
    if(auto slice = assignmentStatement->left->to<IR::Slice>()){
        cstring res = "";
        cstring left = translate(slice->e0);
        updateModifiedVariables(left);
        res += getIndent()+left;
        if(auto typeBits = slice->e0->type->to<IR::Type_Bits>()){
            int size, l, r;
            size = typeBits->size;
            std::stringstream ss;
            ss << translate(slice->e1);
            ss >> l;
            std::stringstream ss2;
            ss2 << translate(slice->e2);
            ss2 >> r;
            res += " := ";
            l++;
            if(l < size)
                res += left+"["+std::to_string(size)+":"+std::to_string(l)+"]++";
            res += translate(assignmentStatement->right);
            if(r > 0)
                res += "++"+left+"["+std::to_string(r)+":0]";
            res += ";\n";
            return res;
        }
        return "";
    }
    cstring res = "";
    cstring left = translate(assignmentStatement->left);
    cstring right = translate(assignmentStatement->right);
    if(right=="havoc"){
        updateModifiedVariables(left);
        return getIndent()+"havoc "+left+";\n";
    }
    // if(left.find("[") != nullptr){
    //     std::string s = left.c_str();
    //     std::string::size_type idx = s.find("[");
    //     if(idx != std::string::npos){
    //         int i = idx;
    //         updateModifiedVariables(left.substr(0, idx));
    //     }
    // }
    // else
        updateModifiedVariables(left);
    res = getIndent()+left+" := "
        +right+";\n";
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
    else if(expr.find("clone3(") != nullptr){
        return getIndent()+"// clone\n";
    }
    else if(expr.find("hash(") != nullptr){
        return getIndent()+"// hash\n";
    }
    else if(expr.find("digest(") != nullptr){
        return getIndent()+"// digest\n";
    }
    else if(expr.find(".count(") != nullptr){
        return getIndent()+"// count\n";
    }
    else if(expr.find(".write(") != nullptr){
        return getIndent()+"// write\n";
    }
    else if(expr.find(".read(") != nullptr){
        return getIndent()+"// read\n";
    }
    else if(expr.find("random(") != nullptr){
        return getIndent()+"// random\n";
    }
    else if(expr.find(".push_front(") != nullptr){
        return getIndent()+"// push_front\n";
    }
    else if(expr.find(".pop_front(") != nullptr){
        return getIndent()+"// pop_front\n";
    }
    else if(expr.find(".execute_meter(") != nullptr){
        return getIndent()+"// execute_meter\n";
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
    else if (auto slice = expression->to<IR::Slice>()){
        return translate(slice);
    }
    else if (auto opBinary = expression->to<IR::Operation_Unary>()){
        return translate(opBinary);
    }
    return "";
}

cstring Translator::translate(const IR::MethodCallExpression *methodCallExpression){
    cstring res = "";
    cstring method = translate(methodCallExpression->method);

    if(method=="lookahead")
        return "havoc";

    if(method=="mark_to_drop"){
        updateModifiedVariables("drop");
        return "mark_to_drop()";
    }

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
    if(method.find("setValid(") != nullptr || method.find("setInvalid(")){
        updateModifiedVariables("isValid");
        return method;
    }

    if(methodCallExpression->arguments->size()>0){
        cstring argument = translate((*methodCallExpression->arguments)[0]);
        std::string s = argument.c_str();
        std::string::size_type idx = s.find("next");
        if(idx != std::string::npos){
            int i = idx;
            cstring succ = "packet_in.extract.headers.";
            succ += s.substr(4, idx-5)+".next";
            res = succ+"("+s.substr(0, idx-1)+")";
            currentProcedure->addSucc(succ);
            addPred(succ, currentProcedure->getName());
            // std::cout << s.substr(0, idx-1) << std::endl;
            // std::cout << "find... " << i << std::endl;
            // return "isValid["+s.substr(0, idx-1)+"]";
            return res;
        }
    }

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
    return res;
}

cstring Translator::translate(const IR::Member *member){
    // std::cout << "member: " << member->member.toString() << std::endl;
    if(member->member.toString()=="extract")
        return "packet_in.extract";
    if(member->member.toString()=="lookahead")
        return "lookahead";
    if(member->member.toString()=="setValid")
        return "setValid("+translate(member->expr)+")";
    if(member->member.toString()=="setInvalid")
        return "setInvalid("+translate(member->expr)+")";
    if(auto arrayIndex = member->expr->to<IR::ArrayIndex>()){
        return translate(arrayIndex->left)+"."+translate(arrayIndex->right)+"."+member->member.toString();
    }
    return translate(member->expr)+"."+member->member.toString();
}

cstring Translator::translate(const IR::PathExpression *pathExpression){
    return translate(pathExpression->path);
}

cstring Translator::translate(const IR::Path *path){
    return translate(path->name);
}

cstring Translator::translate(const IR::Declaration *decl){
    if (auto p4Action = decl->to<IR::P4Action>()){
        translate(p4Action);
    }
    else if (auto p4Table = decl->to<IR::P4Table>()){
        translate(p4Table);
    }
    else if (auto declVar = decl->to<IR::Declaration_Variable>()){
        return translate(declVar);
    }
    return "";
}

cstring Translator::translate(const IR::Declaration_Variable *declVar){
    cstring res = "";
    res += getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n";
    return res;
}

cstring Translator::translate(const IR::SelectExpression *selectExpression, cstring localDeclArg){
    cstring res = "";
    bool flag = false;
    int cnt = selectExpression->selectCases.size();
    for(auto selectCase:selectExpression->selectCases){
        if (auto defaultExpression = selectCase->keyset->to<IR::DefaultExpression>()){
            if(flag)
                continue;
            flag = true;
            cstring nextState = translate(selectCase->state);
            res += getIndent()+"else{\n";
            incIndent();
            res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
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
                if(auto constant = selectCase->keyset->to<IR::Constant>()){
                    res += translate(expr);
                    res += " == ";
                    std::stringstream ss;
                    ss << constant->value;
                    res += ss.str()+translate(constant->type);
                }
                else if(auto mask = selectCase->keyset->to<IR::Mask>()){
                    cstring functionName = translate(mask);
                    res += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
                    res += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
                }
                else if(auto listExpression = selectCase->keyset->to<IR::ListExpression>()){
                    if(auto mask = listExpression->components.at(cnt2)->to<IR::Mask>()){
                        cstring functionName = translate(mask);
                        res += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
                        res += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
                    }
                    else{
                        res += translate(expr)+" == ";
                        res += translate(listExpression->components.at(cnt2));
                    }
                }
                cnt2++;
                if(cnt2 < sz)
                    res += " && ";
            }
            res += "){\n";
            incIndent();
            res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
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

cstring Translator::translate(const IR::Cast *cast){
    if (auto destType = cast->destType->to<IR::Type_Bits>()){
        int dstSize = destType->size, srcSize = -1;
        cstring expr = translate(cast->expr);
        if(auto srcType = cast->expr->type->to<IR::Type_Bits>()){
            srcSize = srcType->size;
        }
        else if(auto srcType = cast->expr->type->to<IR::Type_Unknown>()){
            if(currentProcedure->parameters.find(expr)!=
                currentProcedure->parameters.end()){
                srcSize = currentProcedure->parameters[expr];
            }
        }
        if(srcSize!=-1){
            if(dstSize < srcSize) {
                return expr+"["+std::to_string(dstSize)+":0]";
            }
            else if(dstSize > srcSize){
                return "0bv"+std::to_string(dstSize-srcSize)+"++"+expr;
            }
            else{
                return expr;
            }
        }
    }
    return "";
}

cstring Translator::translate(const IR::Slice *slice){
    cstring res = "";
    res += translate(slice->e0);
    int start;
    std::stringstream ss;
    ss << translate(slice->e1);
    ss >> start;
    res += "["+std::to_string(start+1);
    res += ":"+translate(slice->e2)+"]";
    return res;
}

cstring Translator::translate(const IR::LNot *lnot){
    return "!("+translate(lnot->expr)+")";
}

cstring Translator::translate(const IR::Mask *mask){
    cstring res = "";
    if (auto typeSet = mask->type->to<IR::Type_Set>()){
        if (auto typeBits = typeSet->elementType->to<IR::Type_Bits>()){
            cstring returnType = translate(typeBits);
            cstring functionName = "band."+returnType;
            addFunction("band", "bvand", returnType, returnType);
            return functionName;
        }
    }
    return res;
}

cstring Translator::translate(const IR::ArrayIndex *arrayIndex){
    cstring res = "";
    res += translate(arrayIndex->left);
    res += "["+translate(arrayIndex->right)+"]";
    return res;
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

cstring Translator::translate(const IR::Type_Stack *typeStack, cstring arg){
    const IR::Type_Header* typeHeader = headers[translate(typeStack->elementType)];
    if(typeHeader!=nullptr && stacks.find(arg)==stacks.end()){
        stacks.insert(arg);
        translate(typeHeader, arg+".last");
        if (auto constant = typeStack->size->to<IR::Constant>()) {
            int size = 0;
            std::stringstream ss;
            ss << constant->value;
            ss >> size;
            for(int i = 0; i < size; i++){
                translate(typeHeader, arg+"."+std::to_string(i));
            }
        }
        cstring procName = "packet_in.extract.headers.";
        procName += arg.substr(4)+".next";
        if(procedures.find(procName)==procedures.end()){
            BoogieProcedure extractStack = BoogieProcedure(procName);
            extractStack.addDeclaration("procedure {:inline 1} "+procName+"(stack:HeaderStack)\n");
            extractStack.addModifiedGlobalVariables("stack.index");
            extractStack.addModifiedGlobalVariables("isValid");
            incIndent();
            extractStack.addStatement(getIndent()+"isValid[stack[stack.index[stack]]] := true;\n");
            extractStack.addStatement(getIndent()+"stack.index[stack] := stack.index[stack]+1;\n");
            decIndent();
            addProcedure(extractStack);
        }
    }
    return "";
}

cstring Translator::translate(const IR::Operation_Binary *opBinary){
    cstring typeName = translate(opBinary->left->type);
    cstring returnType = translate(opBinary->type);
    if (auto shl = opBinary->to<IR::Shl>()) {
        addFunction("shl", "bvshl", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "shl."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto shr = opBinary->to<IR::Shr>()) {
        addFunction("shr", "bvlshr", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "shr."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto mul = opBinary->to<IR::Mul>()) {
        addFunction("mul", "bvmul", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "mul."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto add = opBinary->to<IR::Add>()) {
        addFunction("add", "bvadd", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "add."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto addSat = opBinary->to<IR::AddSat>()) {
        addFunction("add", "bvadd", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "add."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto sub = opBinary->to<IR::Sub>()) {
        addFunction("sub", "bvsub", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "sub."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto subSat = opBinary->to<IR::SubSat>()) {
        addFunction("sub", "bvsub", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "sub."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto bAnd = opBinary->to<IR::BAnd>()) {
        addFunction("band", "bvand", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "band."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto bOr = opBinary->to<IR::BOr>()) {
        addFunction("bor", "bvor", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bor."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto bXor = opBinary->to<IR::BXor>()) {
        addFunction("bxor", "bvxor", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bxor."+returnType+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto geq = opBinary->to<IR::Geq>()) {
        addFunction("bsge", "bvsge", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bsge."+typeName+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto leq = opBinary->to<IR::Leq>()) {
        addFunction("bsle", "bvsle", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bsle."+typeName+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto grt = opBinary->to<IR::Grt>()) {
        addFunction("bugt", "bvugt", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bugt."+typeName+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto lss = opBinary->to<IR::Lss>()) {
        addFunction("bult", "bvult", typeName, returnType);
        cstring right = translate(opBinary->right);
        if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            right += returnType;
        return "bult."+typeName+"("+translate(opBinary->left)+", "+right+")";
    }
    else if (auto arrayIndex = opBinary->to<IR::ArrayIndex>()) {
        return translate(arrayIndex);
    }
    else if (auto mask = opBinary->to<IR::Mask>()) {
        return translate(mask);
    }
    else
        return "("+translate(opBinary->left)+") "+opBinary->getStringOp()+" ("+translate(opBinary->right)+")";
}

cstring Translator::translate(const IR::Operation_Unary *opUnary){
    if (auto cast = opUnary->to<IR::Cast>()){
        return translate(cast);
    }
    else if (auto member = opUnary->to<IR::Member>()){
        return translate(member);
    }
    else if (auto lnot = opUnary->to<IR::LNot>()){
        return translate(lnot);
    }
    return "";
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
        addDeclaration("const "+arg+"."+field->name+":HeaderStack;\n");
        if (auto typeStack = field->type->to<IR::Type_Stack>()){
            translate(typeStack, arg+"."+field->name);
        }
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
    incIndent();
    cstring localDecl = "";
    cstring localDeclArg = "";
    int cnt = p4Parser->parserLocals.size();
    for(auto parserLocal:p4Parser->parserLocals){
        cnt--;
        parser.addStatement(translate(parserLocal));
        if (auto declVar = parserLocal->to<IR::Declaration_Variable>()) {
            cstring name = translate(declVar->name);
            cstring type = translate(declVar->type);
            addDeclaration("var "+name+":"+type+";\n");
            addGlobalVariables(name);
            localDecl += name+":"+type;
            localDeclArg += translate(declVar->name);
        }
        if(cnt > 0){
            localDecl += ", ";
            localDeclArg += ", ";
        }
    }
    // parser.addStatement("    call start("+localDeclArg+");\n");
    parser.addStatement("    call start();\n");
    decIndent();
    parser.addSucc("start");
    addPred("start", parserName);
    addProcedure(parser);
    for(auto state:p4Parser->states){
        translate(state);
        // translate(state, localDecl, localDeclArg);
    }

    // add accept & reject
    BoogieProcedure accept = BoogieProcedure("accept");
    // accept.addDeclaration("procedure {:inline 1} accept("+localDecl+")\n");
    accept.addDeclaration("procedure {:inline 1} accept()\n");
    accept.setImplemented();
    addProcedure(accept);

    BoogieProcedure reject = BoogieProcedure("reject");
    // reject.addDeclaration("procedure reject("+localDecl+");\n");
    reject.addDeclaration("procedure reject();\n");
    reject.addDeclaration("    ensures drop==true;\n");
    reject.addModifiedGlobalVariables("drop");
    addProcedure(reject);
    // TODO: parser local variables
}

void Translator::translate(const IR::ParserState *parserState, cstring localDecl, cstring localDeclArg){
    cstring stateName = parserState->name.toString();
    if(stateName=="accept" || stateName=="reject")
        return;
    BoogieProcedure state = BoogieProcedure(stateName);
    state.isParserState = true;
    currentProcedure = &state;
    state.addDeclaration("\n//Parser State "+stateName+"\n");
    state.addDeclaration("procedure {:inline 1} "+stateName+"("+localDecl+")\n");
    incIndent();
    for(auto statOrDecl:parserState->components){
        state.addStatement(translate(statOrDecl));
    }
    if(parserState->selectExpression!=nullptr){
        if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
            cstring nextState = translate(pathExpression);
            state.addStatement(getIndent()+"call "+nextState+"("+localDeclArg+");\n");
            state.addSucc(nextState);
            addPred(nextState, stateName);
        }
        else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
            state.addStatement(translate(selectExpression, localDeclArg));
        }
    }
    // TODO: add succ
    decIndent();
    addProcedure(state);
}

void Translator::translate(const IR::P4Control *p4Control){
    cstring controlName = p4Control->name.toString();
    BoogieProcedure control = BoogieProcedure(controlName);
    control.setImplemented();
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
    cstring actionName = translate(p4Action->name);
    BoogieProcedure action = BoogieProcedure(actionName);
    currentProcedure = &action;
    action.addDeclaration("\n// Action "+actionName+"\n");
    action.addDeclaration("procedure {:inline 1} "+actionName+"(");
    int cnt = p4Action->parameters->parameters.size();
    for(auto parameter:p4Action->parameters->parameters){
        action.addDeclaration(translate(parameter, "action"));
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
    cstring name = translate(p4Table->name);
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
                        table.addStatement(actionName+"."+translate(parameter->name));
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

cstring Translator::translate(const IR::Parameter *parameter, cstring arg){
    cstring name = translate(parameter->name);
    cstring type = translate(parameter->type);
    if(arg == "action"){
        if(auto typeBits = parameter->type->to<IR::Type_Bits>()){
            currentProcedure->parameters[name] = typeBits->size;
        }
    }
    return name+":"+type;
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