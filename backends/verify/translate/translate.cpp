#include "translate.h"
#include <sstream>

Translator::Translator(std::ostream &out, P4VerifyOptions &options, BMV2CmdsAnalyzer* bMV2CmdsAnalyzer) 
    : out(out), options(options), bMV2CmdsAnalyzer(bMV2CmdsAnalyzer){
    // init main procedure
    cstring mainProcedureDeclaration;
    mainProcedure = BoogieProcedure("mainProcedure");
    mainProcedure.addDeclaration("procedure mainProcedure()\n");
    // mainProcedure.addStatement("    call clear_forward();\n");
    // mainProcedure.addSucc("clear_forward");
    // addPred("clear_forward", "mainProcedure");
    // mainProcedure.addStatement("    call clear_drop();\n");
    // mainProcedure.addSucc("clear_drop");
    // addPred("clear_drop", "mainProcedure");
    // mainProcedure.addStatement("    call clear_valid();\n");
    // mainProcedure.addSucc("clear_valid");
    // addPred("clear_valid", "mainProcedure");
    // mainProcedure.addStatement("    call clear_emit();\n");
    // mainProcedure.addSucc("clear_emit");
    // addPred("clear_emit", "mainProcedure");

    // mainProcedure.addStatement("    call init.stack.index();\n");
    // mainProcedure.addSucc("init.stack.index");
    // addPred("init.stack.index", "mainProcedure");

    mainProcedure.setImplemented();

    if(options.ultimateAutomizer){
        BoogieProcedure ultimate = BoogieProcedure("ULTIMATE.start");
        ultimate.addDeclaration("procedure ULTIMATE.start()\n");
        ultimate.addStatement("    call mainProcedure();\n");
        ultimate.addSucc("mainProcedure");
        addPred("mainProcedure", "ULTIMATE.start");
        ultimate.setImplemented();
        addProcedure(ultimate);

    // function {:inline true} power_2_51() : int{power_2_50()*power_2_1()}
    }

    havocProcedure = BoogieProcedure("havocProcedure");
    havocProcedure.addDeclaration("procedure {:inline 1} havocProcedure()\n");
    havocProcedure.setImplemented();

    // procedures = std::vector<BoogieProcedure>();

    // declare necessary types and files
    declaration = cstring("type Ref;\n");
    if(options.ultimateAutomizer)
        declaration += cstring("type error=int;\n");
    else
        declaration += cstring("type error=bv1;\n");
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

    havocProcedure.addStatement("    drop := false;\n");
    havocProcedure.addModifiedGlobalVariables("drop");
    havocProcedure.addStatement("    forward := false;\n");
    havocProcedure.addModifiedGlobalVariables("forward");

    headers = std::map<cstring, const IR::Type_Header*>();
    structs = std::map<cstring, const IR::Type_Struct*>();
    tables = std::map<cstring, const IR::P4Table*>();
    instances = std::vector<const IR::Declaration_Instance*>();
    typeDefs = std::map<cstring, int>();
    // globalVariables = std::set<cstring>();

    maxBitvectorSize = -1;

    addNecessaryProcedures();

    ltlTranslator = new P4LTLTranslator(this);
}

BoogieProcedure Translator::getMainProcedure(){
    return mainProcedure;
}

void Translator::addNecessaryProcedures(){
    // BoogieProcedure clearForward = BoogieProcedure("clear_forward");
    // clearForward.addDeclaration("procedure clear_forward();\n");
    // clearForward.addDeclaration("    ensures forward==false;\n");
    // clearForward.addModifiedGlobalVariables("forward");
    // addProcedure(clearForward);

    // BoogieProcedure clearDrop = BoogieProcedure("clear_drop");
    // clearDrop.addDeclaration("procedure clear_drop();\n");
    // clearDrop.addDeclaration("    ensures drop==false;\n");
    // clearDrop.addModifiedGlobalVariables("drop");
    // addProcedure(clearDrop);

    // BoogieProcedure clearValid = BoogieProcedure("clear_valid");
    // clearValid.addDeclaration("procedure clear_valid();\n");
    // clearValid.addDeclaration("    ensures (forall header:Ref:: isValid[header]==false);\n");
    // clearValid.addModifiedGlobalVariables("isValid");
    // addProcedure(clearValid);

    // BoogieProcedure clearEmit = BoogieProcedure("clear_emit");
    // clearEmit.addDeclaration("procedure clear_emit();\n");
    // clearEmit.addDeclaration("    ensures (forall header:Ref:: emit[header]==false);\n");
    // clearEmit.addModifiedGlobalVariables("emit");
    // addProcedure(clearEmit);

    // BoogieProcedure initStackIndex = BoogieProcedure("init.stack.index");
    // initStackIndex.addDeclaration("procedure init.stack.index();\n");
    // initStackIndex.addDeclaration("    ensures (forall s:HeaderStack::stack.index[s]==0);\n");
    // initStackIndex.addModifiedGlobalVariables("stack.index");
    // addProcedure(initStackIndex);

    // BoogieProcedure extract = BoogieProcedure("packet_in.extract");
    // extract.addDeclaration("procedure {:inline 1} packet_in.extract(header:Ref)\n");
    // incIndent();
    // extract.addStatement(getIndent()+"isValid[header] := true;\n");
    // decIndent();
    // extract.addDeclaration("procedure packet_in.extract(header:Ref);\n");
    // extract.addDeclaration("    ensures (isValid[header] == true);\n");
    // extract.addModifiedGlobalVariables("isValid");
    // addProcedure(extract);

    BoogieProcedure setValid = BoogieProcedure("setValid");
    setValid.addDeclaration("procedure {:inline 1} setValid(header:Ref);\n");
    // setValid.addDeclaration("procedure setValid(header:Ref);\n");
    // setValid.addDeclaration("    ensures (isValid[header] == true);\n");
    // setValid.addModifiedGlobalVariables("isValid");
    addProcedure(setValid);

    BoogieProcedure setInvalid = BoogieProcedure("setInvalid");
    setInvalid.addDeclaration("procedure {:inline 1} setInvalid(header:Ref);\n");
    // setInvalid.addDeclaration("procedure setInvalid(header:Ref);\n");
    setInvalid.addDeclaration("    ensures (isValid[header] == false);\n");
    setInvalid.addModifiedGlobalVariables("isValid");
    addProcedure(setInvalid);

    BoogieProcedure mark_to_drop = BoogieProcedure("mark_to_drop");
    mark_to_drop.addDeclaration("procedure mark_to_drop();\n");
    mark_to_drop.addDeclaration("    ensures drop==true;\n");
    mark_to_drop.addModifiedGlobalVariables("drop");
    addProcedure(mark_to_drop);

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

}

void Translator::addProcedure(BoogieProcedure procedure){
    if(procedures.find(procedure.getName()) != procedures.end())
        return;
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

void Translator::addFunction(cstring funcName, cstring func){
    if(functions.find(funcName)==functions.end()){
        functions.insert(funcName);
        addDeclaration(func);
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
                else if(auto p4Table = controlLocal->to<IR::P4Table>()){
                    tables[translate(p4Table->name)] = p4Table;
                }
            }
        }
        else if (auto instance = obj->to<IR::Declaration_Instance>()){
            instances.push_back(instance);
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

void Translator::incSwitchStatementCount(){ switchStatementCount++; }
cstring Translator::getSwitchStatementCount(){
    std::stringstream ss;
    ss << switchStatementCount;
    return ss.str();
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

P4LTL::AstNode* Translator::getP4LTLSpec(cstring key){
    return p4ltlSpec[key];
}

void Translator::setP4LTLSpec(cstring key, P4LTL::AstNode* root){
    p4ltlSpec[key] = root;
}

void Translator::setP4LTLFreeVars(cstring decl){
    ltlTranslator->createFreeVariables(decl);
}

void Translator::updateMaxBitvectorSize(int size){
    maxBitvectorSize = (maxBitvectorSize > size) ? maxBitvectorSize : size;
}

void Translator::updateMaxBitvectorSize(const IR::Type_Bits *typeBits){
    updateMaxBitvectorSize(typeBits->size);
}

void Translator::updateVariableSize(cstring name, int n){
    // std::cout << "update size: " << name << " " << n << std::endl;
    sizes[name] = n;
}

int Translator::getSize(cstring name){
    if(sizes.find(name) != sizes.end()) return sizes[name];
    else return -1;
}

void Translator::addUAFunctions(){
    declaration += "function {:inline true} power_2_0() : int{1}\n";
    declaration += "function {:inline true} power_2_1() : int{2}\n";
    declaration += "function {:inline true} power_2_2() : int{4}\n";
    declaration += "function {:inline true} power_2_3() : int{8}\n";
    declaration += "function {:inline true} power_2_4() : int{16}\n";
    declaration += "function {:inline true} power_2_5() : int{32}\n";
    declaration += "function {:inline true} power_2_6() : int{64}\n";
    declaration += "function {:inline true} power_2_7() : int{128}\n";
    declaration += "function {:inline true} power_2_8() : int{256}\n";
    declaration += "function {:inline true} power_2_9() : int{512}\n";
    declaration += "function {:inline true} power_2_10() : int{1024}\n";

    declaration += "function {:inline true} power_2_11() : int{2048}\n";
    declaration += "function {:inline true} power_2_12() : int{4096}\n";
    declaration += "function {:inline true} power_2_13() : int{8192}\n";
    declaration += "function {:inline true} power_2_14() : int{16384}\n";
    declaration += "function {:inline true} power_2_15() : int{32768}\n";
    declaration += "function {:inline true} power_2_16() : int{65536}\n";
    declaration += "function {:inline true} power_2_17() : int{131072}\n";
    declaration += "function {:inline true} power_2_18() : int{262144}\n";
    declaration += "function {:inline true} power_2_19() : int{524288}\n";
    declaration += "function {:inline true} power_2_20() : int{1048576}\n";

    declaration += "function {:inline true} power_2_21() : int{2097152}\n";
    declaration += "function {:inline true} power_2_22() : int{4194304}\n";
    declaration += "function {:inline true} power_2_23() : int{8388608}\n";
    declaration += "function {:inline true} power_2_24() : int{16777216}\n";
    declaration += "function {:inline true} power_2_25() : int{33554432}\n";
    declaration += "function {:inline true} power_2_26() : int{67108864}\n";
    declaration += "function {:inline true} power_2_27() : int{134217728}\n";
    declaration += "function {:inline true} power_2_28() : int{268435456}\n";
    declaration += "function {:inline true} power_2_29() : int{536870912}\n";
    declaration += "function {:inline true} power_2_30() : int{1073741824}\n";

    declaration += "function {:inline true} power_2_31() : int{2147483648}\n";
    declaration += "function {:inline true} power_2_32() : int{4294967296}\n";
    declaration += "function {:inline true} power_2_33() : int{8589934592}\n";
    declaration += "function {:inline true} power_2_34() : int{17179869184}\n";
    declaration += "function {:inline true} power_2_35() : int{34359738368}\n";
    declaration += "function {:inline true} power_2_36() : int{68719476736}\n";
    declaration += "function {:inline true} power_2_37() : int{137438953472}\n";
    declaration += "function {:inline true} power_2_38() : int{274877906944}\n";
    declaration += "function {:inline true} power_2_39() : int{549755813888}\n";
    declaration += "function {:inline true} power_2_40() : int{1099511627776}\n";

    declaration += "function {:inline true} power_2_41() : int{2199023255552}\n";
    declaration += "function {:inline true} power_2_42() : int{4398046511104}\n";
    declaration += "function {:inline true} power_2_43() : int{8796093022208}\n";
    declaration += "function {:inline true} power_2_44() : int{17592186044416}\n";
    declaration += "function {:inline true} power_2_45() : int{35184372088832}\n";
    declaration += "function {:inline true} power_2_46() : int{70368744177664}\n";
    declaration += "function {:inline true} power_2_47() : int{140737488355328}\n";
    declaration += "function {:inline true} power_2_48() : int{281474976710656}\n";
    declaration += "function {:inline true} power_2_49() : int{562949953421312}\n";
    declaration += "function {:inline true} power_2_50() : int{1125899906842624}\n";

    if(maxBitvectorSize > 50){
        int tmp = -1;
        for(int i = 51; i <= maxBitvectorSize; i++){
            declaration += "function {:inline true} power_2_"+toString(i)+" () : int{";
            tmp = i;
            while(tmp > 50){
                declaration += "power_2_50()";
                tmp -= 50;
                if(tmp > 0) declaration += "*";
            }
            if(tmp > 0) declaration += "power_2_"+toString(tmp)+"() ";
            declaration += "}\n";
        }
    }

    declaration += "function {:inline true} band(left:int, right:int) : int{((left+right)-(left+right)\%2)/2}\n";
    // declaration += "function band(left:int, right:int) : int{if(left>0 && right>0) then 1 else 0}\n";
    declaration += "function {:inline true} bxor(left:int, right:int) : int{(left+right)\%2}\n";
    // declaration += "function bxor(left:int, right:int) : int{if((left==0&&right>0) || (left>0&&right==0)) then 1 else 0}\n";
    declaration += "function {:inline true} bor(left:int, right:int) : int{(left+right)\%2+((left+right)-((left+right)\%2))/2}\n";
    // declaration += "function bor(left:int, right:int) : int{if(left>0 || right>0) then 1 else 0}\n";
    declaration += "function {:inline true} bnot(num:int) : int{1-num\%2}\n";
    // declaration += "function bnot(num:int) : int{if(num == 0) then 1 else 0}\n";
    
}

void Translator::writeToFile(){
    if(options.p4ltlSpec){
        for(cstring str:P4LTL_KEYS){
            if(p4ltlSpec.find(str) != p4ltlSpec.end()){
                cstring cont = ltlTranslator->translateP4LTL(p4ltlSpec[str]);
                std::cout << str << std::endl << " " << cont << std::endl;
                out << str << " " << cont << "\n";
            }
        }
        out << "\n";
        for(auto item:ltlTranslator->getFreeVariables()){
            if(isGlobalVariable(item.first)){
                std::cout << "ERROR: "+item.first+" is a global variable. Please change the name.\n";
                std::abort();
            }
            addGlobalVariables(item.second);
            // havocProcedure.addStatement("    havoc "+item.second+";\n");
            // havocProcedure.addModifiedGlobalVariables(item.second);
        }
        for(cstring variable:ltlTranslator->getVariables()){
            addGlobalVariables(variable);
            mainProcedure.addModifiedGlobalVariables(variable);
        }
        BoogieProcedure* main;
        if(procedures.find("main") != procedures.end()){
            main = &procedures["main"];
            for(cstring stmt:ltlTranslator->getStatements()){
                main->addStatement("    "+stmt);
            }
            for(cstring variable:ltlTranslator->getVariables()){
                main->addModifiedGlobalVariables(variable);
            }
        }
        else{
            cstring call = mainProcedure.lastStatement();
            mainProcedure.removeLastStatement();
            mainProcedure.addStatement("    while(true){\n");
            mainProcedure.addStatement(call);
            for(cstring stmt:ltlTranslator->getStatements()){
                mainProcedure.addStatement("        "+stmt);
            }
            mainProcedure.addStatement("    }\n");
        }
        
        for(cstring declaration:ltlTranslator->getDeclarations()){
            addDeclaration(declaration);
        }
    }


    if(options.ultimateAutomizer && !options.bitBlasting){
        addUAFunctions();
    }

    addProcedure(mainProcedure);
    addProcedure(havocProcedure);
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

cstring Translator::toString(int val){
    std::stringstream ss;
    ss << val;
    return ss.str();
}

cstring Translator::toString(const big_int& val){
    std::stringstream ss;
    ss << val;
    return ss.str();
}

cstring Translator::getTempPrefix(){
    return TempVariable::getPrefix();
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
    else if (auto typeTypedef = node->to<IR::Type_Typedef>()) {
        translate(typeTypedef);
    }
    else{
        // std::cout << node->node_type_name() << std::endl;
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
        // if(decl->toString().find("hasReturned")) return "";
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
    else if (auto switchStatement = stat->to<IR::SwitchStatement>()){
        return translate(switchStatement);
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
        res += getIndent()+left + " := ";
        if(auto typeBits = slice->e0->type->to<IR::Type_Bits>()){
            updateMaxBitvectorSize(typeBits);

            int size, l, r;
            size = typeBits->size;
            std::stringstream ss;
            ss << translate(slice->e1);
            ss >> l;
            std::stringstream ss2;
            ss2 << translate(slice->e2);
            ss2 >> r;
            l++;
            if(options.ultimateAutomizer){
                // P4: left[e1:e2] = right
                // Boogie: left = left[size:e1+1]++right++left[e2:0]
                // UA: left = (left - left % power_2_e1+1()) + right * power_2_e2() 
                //            + left % power_2_e2()
                res += left + "-" + left + "\%power_2_" + toString(l) + "() + "
                        + translate(assignmentStatement->right) + " * power_2_" + toString(r) + "() + "
                        + left + " \% power_2_" + toString(r) + "()";
                // if(l == size) left - left % power_2_l() == 0
                // if(r == 0) left % power_2_0() == 0
            }
            else{
                if(l < size)
                    res += left+"["+std::to_string(size)+":"+std::to_string(l)+"]++";
                res += translate(assignmentStatement->right);
                if(r > 0)
                    res += "++"+left+"["+std::to_string(r)+":0]";
            }
            res += ";\n";
            currentProcedure->addStatement(res);
            return "";
        }
        return "";
    }
    cstring res = "";
    cstring left = translate(assignmentStatement->left);
    cstring right = translate(assignmentStatement->right);
    if(right=="havoc"){
        updateModifiedVariables(left);
        currentProcedure->addStatement(getIndent()+"havoc "+left+";\n");
        return "";
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
    if(options.bitBlasting && assignmentStatement->left->type->to<IR::Type_Bits>()){
        auto typeBits = assignmentStatement->left->type->to<IR::Type_Bits>();
        int size = typeBits->size;
        for(int i = 0; i < size; i++){
            updateModifiedVariables(connect(left, i));
            currentProcedure->addStatement(getIndent()+connect(left, i)+" := "+
                connect(right, i)+";\n");
        }
        if(left=="standard_metadata.egress_spec"){
            for(int i = 0; i < EGRESS_SPEC_SIZE; i++){
                currentProcedure->addStatement(getIndent()+connect("standard_metadata.egress_port", i)+
                    " := "+connect(right, i)+";\n");
                currentProcedure->addModifiedGlobalVariables(connect("standard_metadata.egress_port", i));
            }
            res += getIndent()+"forward := true;\n";
            currentProcedure->addModifiedGlobalVariables("forward");
        }
    }
    else{
        updateModifiedVariables(left);
        res = getIndent()+left+" := "
            +right+";\n";
        if(left=="standard_metadata.egress_spec"){
            res += getIndent()+"standard_metadata.egress_port := " + right+";\n";
            res += getIndent()+"forward := true;\n";
            currentProcedure->addModifiedGlobalVariables("standard_metadata.egress_port");
            currentProcedure->addModifiedGlobalVariables("forward");
        }
        currentProcedure->addStatement(res);
    }
    return "";
}

cstring Translator::translate(const IR::IfStatement *ifStatement){
    cstring res = "";
    cstring condition = "";
    condition += getIndent()+"if(";
    condition += translate(ifStatement->condition);
    condition += "){\n";
    currentProcedure->addStatement(condition);
    res += condition;
    incIndent();
    res += translate(ifStatement->ifTrue);
    decIndent();
    currentProcedure->addStatement(getIndent()+"}\n");
    // res += getIndent()+"}\n";
    if(ifStatement->ifFalse!=nullptr){
        currentProcedure->addStatement(getIndent()+"else{\n");
        res += getIndent()+"else{\n";
        incIndent();
        res += translate(ifStatement->ifFalse);
        decIndent();
        currentProcedure->addStatement(getIndent()+"}\n");
        res += getIndent()+"}\n";
    }
    return "";
}

cstring Translator::translate(const IR::BlockStatement *blockStatement){
    cstring res = "";
    for(auto statOrDecl:blockStatement->components){
        currentProcedure->addStatement(translate(statOrDecl));
        // res += translate(statOrDecl);
    }
    return res;
}

cstring Translator::translate(const IR::MethodCallStatement *methodCallStatement){
    cstring expr = translate(methodCallStatement->methodCall->method);
    if(expr.find("verify_checksum") != nullptr){
        return getIndent()+"// verify_checksum\n";
    }
    else if(expr.find("update_checksum") != nullptr){
        return getIndent()+"// update_checksum\n";
    }
    else if(expr.find("clone3") != nullptr){
        return getIndent()+"// clone\n";
    }
    // else if(expr.find("hash") != nullptr){
    else if(expr=="hash"){
        currentProcedure->addStatement(getIndent()+"// hash\n");
        cstring expr2 = translate(methodCallStatement->methodCall);
        currentProcedure->addStatement(getIndent()+expr2);
        // currentProcedure->addStatement(getIndent()+expr2+";\n");
        return "";
    }
    else if(expr.find("digest") != nullptr){
        return getIndent()+"// digest\n";
    }
    else if(expr.find(".count") != nullptr){
        return getIndent()+"// count\n";
    }
    else if(expr.find(".write") != nullptr){
        currentProcedure->addStatement(getIndent()+"// write\n");
        cstring expr2 = translate(methodCallStatement->methodCall);
        currentProcedure->addStatement(getIndent()+"call "+expr2+";\n");
        return "";
    }
    else if(expr.find(".read") != nullptr){
        currentProcedure->addStatement(getIndent()+"// read\n");
        cstring expr2 = translate(methodCallStatement->methodCall);
        currentProcedure->addStatement(getIndent()+expr2+";\n");
        return "";
    }
    else if(expr.find("random") != nullptr){
        return getIndent()+"// random\n";
    }
    else if(expr.find(".push_front") != nullptr){
        return getIndent()+"// push_front\n";
    }
    else if(expr.find(".pop_front") != nullptr){
        return getIndent()+"// pop_front\n";
    }
    else if(expr.find(".execute_meter") != nullptr){
        return getIndent()+"// execute_meter\n";
    }
    else if(expr.find("resubmit") != nullptr){
        return getIndent()+"// resubmit\n";
    }
    else if(expr.find("truncate") != nullptr){
        return getIndent()+"// truncate\n";
    }
    else if(expr.find("recirculate") != nullptr){
        return getIndent()+"// recirculate\n";
    }
    else if(expr == "verify"){
        currentProcedure->addStatement(getIndent()+"// verify\n");
        cstring expr2 = translate(methodCallStatement->methodCall);
        currentProcedure->addStatement(getIndent()+expr2+";\n");
        return "";
    }
    cstring expr2 = translate(methodCallStatement->methodCall);
    if(expr2.find(";\n")){
        currentProcedure->addStatement(getIndent()+expr2);
    }
    else if(expr2 != ""){
        currentProcedure->addStatement(getIndent()+"call "+expr2+";\n");
    }
    return "";
}

cstring Translator::translate(const IR::SwitchStatement *switchStatement){
    cstring res = "";
    cstring expr = translate(switchStatement->expression);
    if(auto actionEnum = switchStatement->expression->type->to<IR::Type_ActionEnum>()){
        /* 
            use goto statements
        */
        if(options.gotoOrIf){
            incSwitchStatementCount();
            cstring switchLabel = "Switch$"+getSwitchStatementCount()+"$";

            cstring tableName;
            std::string s = expr.c_str();
            std::string::size_type idx = s.find(".apply()");
            if(idx != std::string::npos){
                int i = idx;
                tableName = s.substr(0, idx);
            }
            // get the corresponding table
            const IR::P4Table* p4Table = tables[tableName];

            

            /* 
                - add goto statement
                - local variables
            */
            cstring gotoStmt = getIndent()+"goto ";
            bool firstAction = true;

            // Add local variables (action parameters) declaration
            for(auto property:p4Table->properties->properties){
                if (auto actionList = property->value->to<IR::ActionList>()) {
                    // add local variables
                    for(auto actionElement:actionList->actionList){
                        if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                            cstring actionName = translate(actionCallExpr->method);
                            const IR::P4Action* action = actions[actionName];
                            for(auto parameter:action->parameters->parameters){
                                cstring parameter_str = actionName+"."+translate(parameter);
                                if(!currentProcedure->hasLocalVariables(parameter_str)){
                                    currentProcedure->addFrontStatement("    var "+parameter_str+";\n");
                                    currentProcedure->addLocalVariables(parameter_str);
                                }
                            }
                            // goto statement
                            if(!firstAction)
                                gotoStmt += ", ";
                            else
                                firstAction = false;
                            gotoStmt += switchLabel+tableName+"$"+actionName;
                        }
                    }
                }
            }
            // Add goto Statement
            gotoStmt += ";\n";
            currentProcedure->addStatement(gotoStmt);

            /* For default case 
                 Record actions that handled by other cases
                 Other actions are handled by the default case (if exists)
            */
            std::set<cstring> handledActions;
            for(auto switchCase:switchStatement->cases){
                if (auto defaultExpression = switchCase->label->to<IR::DefaultExpression>()){}
                else{
                    // get the corresponding action
                    cstring actionName = translate(switchCase->label);
                    handledActions.insert(actionName);
                }
            }        

            int caseCnt = -1;
            for(auto switchCase:switchStatement->cases){
                caseCnt += 1;
                // get the action's name
                // cstring actionName = translate(switchCase->label);

                /*
                    Add parameters
                    Add table entry & exit
                    Add action invocation
                    Add table labels
                    case fall Through
                    without default? (the compiler always adds a default case)
                */

                // Fall Through
                int fallThrough = caseCnt;
                while(fallThrough < switchStatement->cases.size() &&
                    switchStatement->cases[fallThrough]->statement == nullptr){
                    fallThrough++;
                }

                if (auto defaultExpression = switchCase->label->to<IR::DefaultExpression>()){
                    // all alternative actions should be considered
                    for(auto property:p4Table->properties->properties){
                        if (auto actionList = property->value->to<IR::ActionList>()) {
                            for(auto actionElement:actionList->actionList){
                                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                                    cstring actionName = translate(actionCallExpr->method);
                                    if(handledActions.find(actionName)==handledActions.end()){
                                        const IR::P4Action* action = actions[actionName];

                                        // Add label for actions
                                        currentProcedure->addStatement("\n"+getIndent()+switchLabel
                                            +tableName+"$"+actionName+":\n");

                                        incIndent();

                                        // Table entry
                                        // currentProcedure->addStatement(getIndent()+"call "+tableName+".apply_table_entry();\n");
                                        // Specify action_run
                                        currentProcedure->addStatement(getIndent()+"assume "+tableName+
                                            ".action_run == "+tableName+".action."+actionName+";\n");
                                        // currentProcedure->addStatement(getIndent()+tableName+
                                        //     ".action_run := "+tableName+".action."+actionName+";\n");
                                        currentProcedure->addModifiedGlobalVariables(tableName+".action_run");
                                        // Add Parameters
                                        cstring actionCall = "";
                                        actionCall += getIndent()+"call "+actionName+"(";
                                        currentProcedure->addSucc(actionName);
                                        addPred(actionName, currentProcedure->getName());
                                        int cnt = action->parameters->parameters.size();
                                        for(auto parameter:action->parameters->parameters){
                                            cnt--;
                                            actionCall += actionName+"."+translate(parameter->name);
                                            if(cnt != 0)
                                                actionCall += ", ";
                                        }
                                        actionCall += ");\n";

                                        currentProcedure->addStatement(actionCall);
                                        // Table exit
                                        // currentProcedure->addStatement(getIndent()+"call "+tableName+".apply_table_exit();\n");
                                        if(fallThrough < switchStatement->cases.size())
                                            translate(switchStatement->cases[fallThrough]->statement);
                                        currentProcedure->addStatement(getIndent()+"goto "+switchLabel
                                            +tableName+"$Continue;\n");
                                        decIndent();
                                    }
                                }
                            }
                        }
                    }
                }
                else{
                    cstring actionName = translate(switchCase->label);
                    const IR::P4Action* action = actions[actionName];

                    // Add label for actions
                    currentProcedure->addStatement("\n"+getIndent()+switchLabel
                        +tableName+"$"+actionName+":\n");

                    incIndent();

                    // Table entry
                    // currentProcedure->addStatement(getIndent()+"call "+tableName+".apply_table_entry();\n");
                    // Specify action_run
                    currentProcedure->addStatement(getIndent()+"assume "+tableName+
                                            ".action_run == "+".action."+actionName+";\n");
                    currentProcedure->addModifiedGlobalVariables(tableName+".action_run");

                    // Add Parameters
                    cstring actionCall = "";
                    actionCall += getIndent()+"call "+actionName+"(";
                    currentProcedure->addSucc(actionName);
                    addPred(actionName, currentProcedure->getName());
                    int cnt = action->parameters->parameters.size();
                    for(auto parameter:action->parameters->parameters){
                        cnt--;
                        actionCall += actionName+"."+translate(parameter->name);
                        if(cnt != 0)
                            actionCall += ", ";
                    }
                    actionCall += ");\n";
                    currentProcedure->addStatement(actionCall);

                    // Table exit
                    // currentProcedure->addStatement(getIndent()+"call "+tableName+".apply_table_exit();\n");
                    
                    
                    if(fallThrough < switchStatement->cases.size())
                        translate(switchStatement->cases[fallThrough]->statement);

                    currentProcedure->addStatement(getIndent()+"goto "+switchLabel
                        +tableName+"$Continue;\n");
                    decIndent();
                }
            }

            // Add continue label
            currentProcedure->addStatement("\n"+getIndent()+switchLabel
                +tableName+"$Continue:\n");
        }
        else{
            cstring tableName;
            std::string s = expr.c_str();
            std::string::size_type idx = s.find(".apply()");
            if(idx != std::string::npos){
                int i = idx;
                tableName = s.substr(0, idx);
            }
            // get the corresponding table
            const IR::P4Table* p4Table = tables[tableName];
            currentProcedure->addStatement(getIndent()+tableName+".apply();\n");
            bool firstAction = true;

            bool fallThrough = false;
            bool caseCnt = 0;
            for(auto switchCase:switchStatement->cases){
                caseCnt++;
                if (auto defaultExpression = switchCase->label->to<IR::DefaultExpression>()){}
                else{
                    // no fall through
                    if(!fallThrough){
                        if(firstAction){
                            currentProcedure->addStatement(getIndent()+"if(");
                            firstAction = false;
                        }
                        else{
                            currentProcedure->addStatement(getIndent()+"else if(");
                        }
                    }
                    else
                        currentProcedure->addStatement(" || ");
                    
                    // get the corresponding action
                    cstring actionName = translate(switchCase->label);
                    currentProcedure->addStatement(tableName+".action_run == "+actionName);
                    if(switchCase->statement != nullptr){
                        fallThrough = false;
                        currentProcedure->addStatement("){\n");
                        incIndent();
                        currentProcedure->addStatement(translate(switchCase->statement));
                        decIndent();
                        currentProcedure->addStatement(getIndent()+"}\n");
                    }
                    else{
                        fallThrough = true;
                        if(caseCnt == switchStatement->cases.size()){
                            currentProcedure->addStatement("){\n");
                            currentProcedure->addStatement(getIndent()+"}\n");
                        }
                    }
                }
            }
        }
    }

    // TODO consider ordinary switch expression (value)
    // testcase: testdata/p4_16_samples/switch-expression.p4
    currentProcedure->addStatement(res);
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
    // else if (auto selectExpression = expression->to<IR::SelectExpression>()){
    //     return translate(selectExpression);
    // }
    else if (auto methodCallExpression = expression->to<IR::MethodCallExpression>()){
        return translate(methodCallExpression);
    }
    else if (auto opBinary = expression->to<IR::Operation_Binary>()){
        return translate(opBinary);
    }
    else if (auto constant = expression->to<IR::Constant>()){
        return translate(constant);
    }
    else if (auto boolLiteral = expression->to<IR::BoolLiteral>()){
        return translate(boolLiteral);
    }
    else if (auto constructorCallExpression = expression->to<IR::ConstructorCallExpression>()){
        return translate(constructorCallExpression);
    }
    else if (auto slice = expression->to<IR::Slice>()){
        return translate(slice);
    }
    else if (auto opUnary = expression->to<IR::Operation_Unary>()){
        return translate(opUnary);
    }
    else if (auto defaultExpression = expression->to<IR::DefaultExpression>()){
        return "default";
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

    if(method.find("packet_in.extract")){
        cstring arg = "";
        for(auto argument:*methodCallExpression->arguments){
            arg = translate(argument);
            break;
        }
        if(arg.find(".next")) return "";
        res = arg+".valid := true;\n";
        currentProcedure->addModifiedGlobalVariables(arg+".valid");
        return res;
    }

    // Register read (BMV2)
    if(method.find(".read")){
        // method = methodCallExpression->method->toString();
        std::string::size_type idx = ((std::string)method.c_str()).find(".read");
        cstring reg = ((std::string)method.c_str()).substr(0, idx);  // register
        if(!isGlobalVariable(reg)){
            method = methodCallExpression->method->toString();
            idx = ((std::string)method.c_str()).find(".read");
            reg = ((std::string)method.c_str()).substr(0, idx);
        }

        cstring arg0 = translate((*methodCallExpression->arguments)[0]);  // return addr

        currentProcedure->addModifiedGlobalVariables(arg0);
        cstring arg1 = translate((*methodCallExpression->arguments)[1]);  // index
        res += arg0 + " := " + method + "(";
        res += reg + ", " + arg1 + ")";
        return res;
    }

    if(method.find(".write")){
        std::string::size_type idx = ((std::string)method.c_str()).find(".write");
        cstring reg = ((std::string)method.c_str()).substr(0, idx);  // register
        if(!isGlobalVariable(reg)){
            method = methodCallExpression->method->toString();
        }
    }

    if(method=="hash"){
        // hash(result, hashAlgorithm, from, tuple, to)
        // std::string::size_type idx = ((std::string)method.c_str()).find(".read");
        cstring arg0 = translate((*methodCallExpression->arguments)[0]);  // return addr
        cstring typeName = translate((*methodCallExpression->arguments)[0]->expression->type);

        // cstring arg1 = translate((*methodCallExpression->arguments)[1]);  // index
        cstring arg2 = translate((*methodCallExpression->arguments)[2]);
        // cstring arg3 = translate((*methodCallExpression->arguments)[3]);
        cstring arg4 = translate((*methodCallExpression->arguments)[4]);

        if(options.ultimateAutomizer){
            // eg: bsge.bv8(left:int, right:int) : bool{left >= right}
            cstring funcName = "bsge."+typeName;
            cstring function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{"
                + "left >= right" + "}\n";
            addFunction(funcName, function);
        }
        else
            addFunction("bsge", "bvsge", typeName, "bool");
        // cstring right = translate(opBinary->right);
        // if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>())
            // right += returnType;
        // return "bsge."+typeName+"("+translate(opBinary->left)+", "+right+")";

        res += "havoc "+arg0+";\n";
        // res += getIndent()+"assume(bsge."+typeName+"("+arg0+", "+arg2+
            // ") && bsge."+typeName+"("+arg4+", "+arg0+"));\n";
        res += getIndent()+"assume(("+arg0+" >= "+arg2+
            ") && "+"("+arg4+" >= "+arg0+"));\n";
        currentProcedure->addModifiedGlobalVariables(arg0);
        return res;
    }

    if(method=="verify"){
        cstring arg = translate((*methodCallExpression->arguments)[0]);
        res += "assert("+arg+")";
        return res;
    }

    std::string s = method.c_str();
    std::string::size_type idx = s.find("isValid");
    if(idx != std::string::npos){
        int i = idx;
        if(options.addValidityAssertion){
            cstring assertStmt = "assert(isValid["+s.substr(0, idx-1)+"]);";
            while(currentProcedure->lastStatement().find(assertStmt)!= nullptr){
                currentProcedure->removeLastStatement();
            }
        }
        if(options.addValidityAssertion){
            cstring assertStmt = "assert(false);";
            while(currentProcedure->lastStatement().find(assertStmt)!= nullptr){
                currentProcedure->removeLastStatement();
            }
        }
        return s.substr(0, idx-1)+".valid";
        // return "isValid["+s.substr(0, idx-1)+"]";
        // std::cout << s.substr(0, idx-1) << std::endl;
        // std::cout << "find... " << i << std::endl;
    }
    // if(method.find("isValid") != nullptr){
    //     std::string s = method.c_str();
    //     std::cout << "find... " << s.find("isValid") << std::endl;
    // }
    if(method.find("setValid(") != nullptr || method.find("setInvalid(")){
        if(options.addValidityAssertion){
            if(currentProcedure->lastStatement().find("assert(")!= nullptr){
                currentProcedure->removeLastStatement();
            }
        }  
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
        
        // packet_in.extract with multiple parameters (only consider the first param)
        if(method.find("extract") != nullptr){
            break;
        }

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
    // TODO: NoAction should not be considered
    if(member->member.toString()=="hit"){
        cstring expr = translate(member->expr);
        std::string s = expr.c_str();
        std::string::size_type idx = s.find(".apply()");
        if(idx != std::string::npos){
            int i = idx;
            cstring tableName = s.substr(0, idx);
            currentProcedure->addStatement(getIndent()+"call "+tableName+".apply();\n");
            currentProcedure->addSucc(tableName+".apply");
            // IR::P4Table* p4Table = tables[tableName];
            return tableName+".hit";
        }
        // std::cout << translate(member->expr).find(".apply()") << std::endl;
        // std::cout << translate(member->expr) << std::endl;
        // std::cout << member << std::endl;
    }

    // For header stack
    if(auto arrayIndex = member->expr->to<IR::ArrayIndex>()){
        if(options.addBoundAssertion){
            if(auto typeStack = arrayIndex->left->type->to<IR::Type_Stack>()){
                currentProcedure->addStatement(getIndent()+"assert ("
                                                +translate(arrayIndex->right)+ "<" +
                                                translate(typeStack->size)+");\n");
                }
            // }
        }
        return translate(arrayIndex->left)+"."+translate(arrayIndex->right)+"."+member->member.toString();
    }

    if(auto typeHeader = member->type->to<IR::Type_Header>()){
        cstring hdr = translate(member->expr)+"."+member->member.toString();
        cstring stmt = getIndent()+"assert(isValid["+hdr+"]);\n";
        if(options.addValidityAssertion){
            if(currentProcedure->lastStatement() == "" || 
                (currentProcedure->lastStatement() != stmt 
                    && stmt.find(currentProcedure->lastStatement()) == nullptr)){
                currentProcedure->addStatement(stmt);
                // std::cout << translate(member->expr)+"."+member->member.toString() << std::endl;
            }
            else{
                // std::cout << "fail to add:" << std::endl;
                // std::cout << stmt << std::endl;
                // std::cout << "last statement:" << std::endl;
                // std::cout << currentProcedure->lastStatement() << std::endl;
            }
        }
        if(options.addValidityAssertion){
            cstring stmt = getIndent()+"assert(false);\n";
            if(options.addValidityAssertion && currentProcedure->lastStatement() == "" || 
                (currentProcedure->lastStatement() != stmt 
                    && stmt.find(currentProcedure->lastStatement()) == nullptr)){
                currentProcedure->addStatement(stmt);
                // std::cout << translate(member->expr)+"."+member->member.toString() << std::endl;
            }
        }
        return hdr;
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
    else if (auto instance = decl->to<IR::Declaration_Instance>()){
        translate(instance);
    }
    return "";
}

cstring Translator::translate(const IR::Declaration_Variable *declVar){ 
    // Should be declared as global variables
    // Variables have been renamed by p4c

    cstring res = "";
    addGlobalVariables(translate(declVar->name));
    
    if(auto typeBits = declVar->type->to<IR::Type_Bits>()){
        if(options.ultimateAutomizer){
            addDeclaration("var "+translate(declVar->name)+":int;\n");
            updateVariableSize(translate(declVar->name), typeBits->size);
        }
        else addDeclaration("var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    }
    else if(auto typeName = declVar->type->to<IR::Type_Name>()){
        if(headers.find(translate(typeName)) != headers.end()){
            translate(headers[translate(typeName)], translate(declVar->name));
        }
        else addDeclaration("var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    }
    else
        addDeclaration("var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    
    if(declVar->initializer == nullptr){
        if(currentProcedure != nullptr){
            // For Type_Unknown
            // Record the types of local variables
            if(auto typeBits = declVar->type->to<IR::Type_Bits>()){
                updateMaxBitvectorSize(typeBits);
                currentProcedure->declarationVariables[translate(declVar->name)] = typeBits->size;
            }
        }
    }
    else{
        if(currentProcedure != nullptr){
            currentProcedure->addStatement(BoogieStatement(getIndent()+translate(declVar->name)+" := "+translate(declVar->initializer)+";\n"));
            if(auto typeBits = declVar->type->to<IR::Type_Bits>()){
                updateMaxBitvectorSize(typeBits);
                currentProcedure->declarationVariables[translate(declVar->name)] = typeBits->size;
            }
        }
    }
    return res;

    // cstring res = "";
    // if(declVar->initializer == nullptr){
    //     if(currentProcedure != nullptr){
    //         // Variable declaration in Boogie must be at the beginning of procesures
    //         currentProcedure->addVariableDeclaration(getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    //         // For Type_Unknown
    //         // Record the types of local variables
    //         if(auto typeBits = declVar->type->to<IR::Type_Bits>()){
    //             currentProcedure->declarationVariables[translate(declVar->name)] = typeBits->size;
    //         }
    //     }
    //     else
    //         res += getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n";
    // }
    // else{
    //     if(currentProcedure != nullptr){
    //         currentProcedure->addVariableDeclaration(getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    //         currentProcedure->addStatement(BoogieStatement(getIndent()+translate(declVar->name)+" := "+translate(declVar->initializer)+";\n"));
    //         if(auto typeBits = declVar->type->to<IR::Type_Bits>()){
    //             currentProcedure->declarationVariables[translate(declVar->name)] = typeBits->size;
    //         }
    //     }
    //     else{
    //         res += getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n";
    //     }
    //     // currentProcedure->addVariableDeclaration(getIndent()+"var "+translate(declVar->name)+":"+translate(declVar->type)+";\n");
    //     // currentProcedure->addStatement(BoogieStatement(getIndent()+translate(declVar->name)+" := "+translate(declVar->initializer)+";\n"));
    // }
    // return res;
}

// cstring Translator::translate(const IR::SelectExpression *selectExpression, cstring localDeclArg){
//     cstring res = "";
//     bool flag = false;
//     int cnt = selectExpression->selectCases.size();
//     for(auto selectCase:selectExpression->selectCases){
//         if (auto defaultExpression = selectCase->keyset->to<IR::DefaultExpression>()){
//             if(flag)
//                 continue;
//             flag = true;
//             cstring nextState = translate(selectCase->state);
//             if(selectExpression->selectCases.size()==1){
//                 res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
//                 currentProcedure->addSucc(nextState);
//                 addPred(nextState, currentProcedure->getName());
//             }
//             else{
//                 res += getIndent()+"else{\n";
//                 incIndent();
//                 res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
//                 currentProcedure->addSucc(nextState);
//                 addPred(nextState, currentProcedure->getName());
//                 decIndent();
//                 res += getIndent()+"}\n";
//             }
//         }
//         else{
//             cstring nextState = translate(selectCase->state);
//             if(cnt == selectExpression->selectCases.size())
//                 res += getIndent()+"if(";
//             else
//                 res += getIndent()+"else if(";

//             int sz = selectExpression->select->components.size();
//             int cnt2 = 0;
//             for(auto expr:selectExpression->select->components){
//                 if(auto constant = selectCase->keyset->to<IR::Constant>()){
//                     res += translate(expr);
//                     res += " == ";
//                     std::stringstream ss;
//                     ss << constant->value;
//                     res += ss.str()+translate(constant->type);
//                 }
//                 else if(auto mask = selectCase->keyset->to<IR::Mask>()){
//                     cstring functionName = translate(mask);
//                     res += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
//                     res += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
//                 }
//                 else if(auto listExpression = selectCase->keyset->to<IR::ListExpression>()){
//                     if(auto mask = listExpression->components.at(cnt2)->to<IR::Mask>()){
//                         cstring functionName = translate(mask);
//                         res += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
//                         res += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
//                     }
//                     else{
//                         res += translate(expr)+" == ";
//                         res += translate(listExpression->components.at(cnt2));
//                     }
//                 }
//                 cnt2++;
//                 if(cnt2 < sz)
//                     res += " && ";
//             }
//             res += "){\n";
//             incIndent();
//             res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
//             currentProcedure->addSucc(nextState);
//             addPred(nextState, currentProcedure->getName());
//             decIndent();
//             res += getIndent()+"}\n";
//         }
//         cnt--;
//     }
//     return res;
// }

cstring Translator::translate(const IR::SelectExpression *selectExpression, cstring stateName, cstring localDeclArg){
    cstring res = "";
    // goto Statement
    if(options.gotoOrIf){

        cstring gotoStmt = getIndent()+"goto ";
        bool flag = false;  // avoid multiple default cases

        cstring defaultLabel = "State$"+stateName+"$"+"DEFAULT";
        cstring defaultBlock = "";
        cstring defaultCondition = "";

        int cnt = selectExpression->selectCases.size();
        for(auto selectCase:selectExpression->selectCases){
            std::stringstream ss_cnt;
            ss_cnt << cnt;
            if (auto defaultExpression = selectCase->keyset->to<IR::DefaultExpression>()){
                if(flag)
                    continue;
                flag = true;
                cstring nextState = translate(selectCase->state);

                defaultBlock += getIndent()+"goto "+"State$"+nextState+";\n";
                // defaultBlock += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
                currentProcedure->addSucc(nextState);
                addPred(nextState, currentProcedure->getName());
            }
            else{
                cstring nextState = translate(selectCase->state);

                // Goto label for next state
                cstring gotoLabel = "State$"+stateName+"$"+nextState+"_"+ss_cnt.str();
                gotoStmt += gotoLabel+", ";

                res += getIndent()+"\n"+gotoLabel+":\n";
                res += getIndent()+"assume (";

                cstring condition = "";

                int sz = selectExpression->select->components.size();
                int cnt2 = 0;
                for(auto expr:selectExpression->select->components){
                    if(auto constant = selectCase->keyset->to<IR::Constant>()){
                        condition += translate(expr);
                        condition += " == ";
                        std::stringstream ss;
                        ss << constant->value;
                        condition += ss.str()+translate(constant->type);
                    }
                    else if(auto mask = selectCase->keyset->to<IR::Mask>()){
                        cstring functionName = translate(mask);
                        condition += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
                        condition += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
                    }
                    else if(auto listExpression = selectCase->keyset->to<IR::ListExpression>()){
                        if(auto mask = listExpression->components.at(cnt2)->to<IR::Mask>()){
                            cstring functionName = translate(mask);
                            condition += functionName+"("+translate(expr)+", "+translate(mask->right)+") == ";
                            condition += functionName+"("+translate(mask->left)+", "+translate(mask->right)+")";
                        }
                        else{
                            condition += translate(expr)+" == ";
                            condition += translate(listExpression->components.at(cnt2));
                        }
                    }
                    cnt2++;
                    if(cnt2 < sz)
                        condition += " && ";
                }
                if(defaultCondition.size()>0)
                    defaultCondition += "&&";
                defaultCondition += "!("+condition+")";

                res += condition;
                res += ");\n";
                res += getIndent()+"goto "+"State$"+nextState+";\n";
                // res += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
                // res += getIndent()+"goto Exit;\n";
                currentProcedure->addSucc(nextState);
                addPred(nextState, currentProcedure->getName());
            }
            cnt--;
        }
        gotoStmt += defaultLabel+";\n";
        res = gotoStmt+res;

        res += "\n"+getIndent()+defaultLabel+":\n";
        defaultBlock = getIndent()+"assume("+defaultCondition+");\n"+defaultBlock;
        if(!flag)
            defaultBlock = defaultBlock+"goto State$reject;\n";
        res += defaultBlock;

        // res += "State$"+stateName+"$"+"Exit:\n";
    }
    else{
        cstring defaultCondition = "";
        cstring defaultBlock = "";
        bool flag = false;  // avoid multiple default cases
        // int cnt = selectExpression->selectCases.size();
        int cnt = 0;
        for(auto selectCase:selectExpression->selectCases){
            if (auto defaultExpression = selectCase->keyset->to<IR::DefaultExpression>()){
                if(flag)
                    continue;
                flag = true;
                cstring nextState = translate(selectCase->state);
                defaultBlock += "call "+nextState+"("+localDeclArg+");\n";
                // defaultBlock += getIndent()+"call "+nextState+"("+localDeclArg+");\n";
                currentProcedure->addSucc(nextState);
                addPred(nextState, currentProcedure->getName());
            }
            else{
                cstring condition = "";
                cstring nextState = translate(selectCase->state);
                int sz = selectExpression->select->components.size();
                int cnt2 = 0;
                for(auto expr:selectExpression->select->components){
                    if(auto constant = selectCase->keyset->to<IR::Constant>()){
                        if(options.ultimateAutomizer && options.bitBlasting 
                            && expr->type->to<IR::Type_Bits>()){
                            auto typeBits = expr->type->to<IR::Type_Bits>();
                            int size = typeBits->size;
                            cstring left = translate(expr);
                            cstring right = integerBitBlasting((int)constant->value, size);
                            for(int i = 0; i < size; i++){
                                condition += connect(left, i) + " == " + connect(right, i);
                                if(i < size-1) condition += " && ";
                            }
                        }
                        else if(options.ultimateAutomizer && constant->type->to<IR::Type_Bits>()){
                            condition += translate(expr);
                            condition += " == ";
                            std::stringstream ss;
                            ss << constant->value;
                            condition += ss.str();
                        }
                        else{
                            condition += translate(expr);
                            condition += " == ";
                            std::stringstream ss;
                            ss << constant->value;
                            condition += ss.str()+translate(constant->type);
                        }
                    }
                    else if(auto mask = selectCase->keyset->to<IR::Mask>()){
                        cstring functionName = translate(mask);
                        cstring maskLeft = translate(mask->left);
                        cstring maskRight = translate(mask->right);
                        int maskLeftNum = -1, maskRightNum = -1;
                        if(maskLeft.size() <= 9 && maskRight.size() <= 9){
                            if(isNumber(maskLeft)){
                                maskLeftNum = atoi(std::string(maskLeft.c_str()).c_str());
                            }
                            if(isNumber(maskRight)){
                                maskRightNum = atoi(std::string(maskRight.c_str()).c_str());
                            }

                            if(maskRightNum == 0){
                                condition += "true";
                            }
                            else{
                                bool flag = false;
                                for(int i = 1; i <= 2147483647; i=(i<<1)+1){
                                    if(maskRightNum == i){
                                        flag = true;
                                        break;
                                    }
                                    if(i == 2147483647) break;
                                }                                
                                if(flag){
                                    condition += translate(expr)+"%"+maskRight+" == ";
                                }
                                else{
                                    condition += functionName+"("+translate(expr)+", "+maskRight+") == ";
                                }

                                if(maskLeftNum != -1 && maskRightNum != -1){
                                    condition += toString(maskLeftNum & maskRightNum);
                                }
                                else if(maskRightNum == 0){
                                    condition += functionName+"("+maskLeft+", "+maskRight+")";
                                }
                            }

                        }
                        else{
                            condition += functionName+"("+translate(expr)+", "+maskRight+") == ";
                            condition += functionName+"("+maskLeft+", "+maskRight+")";
                        }
                    }
                    else if(auto listExpression = selectCase->keyset->to<IR::ListExpression>()){
                        if(auto mask = listExpression->components.at(cnt2)->to<IR::Mask>()){
                            cstring functionName = translate(mask);
                            cstring maskLeft = translate(mask->left);
                            cstring maskRight = translate(mask->right);
                            int maskLeftNum = -1, maskRightNum = -1;
                            if(maskLeft.size() <= 9 && maskRight.size() <= 9){
                                if(isNumber(maskLeft)){
                                    maskLeftNum = atoi(std::string(maskLeft.c_str()).c_str());
                                }
                                if(isNumber(maskRight)){
                                    maskRightNum = atoi(std::string(maskRight.c_str()).c_str());
                                }

                                if(maskRightNum == 0){
                                    condition += "true";
                                }
                                else{
                                    bool flag = false;
                                    for(int i = 1; i <= 2147483647; i=(i<<1)+1){
                                        if(maskRightNum == i){
                                            flag = true;
                                            break;
                                        }
                                        if(i == 2147483647) break;
                                    }                                
                                    if(flag){
                                        condition += translate(expr)+"%"+maskRight+" == ";
                                    }
                                    else{
                                        condition += functionName+"("+translate(expr)+", "+maskRight+") == ";
                                    }

                                    if(maskLeftNum != -1 && maskRightNum != -1){
                                        condition += toString(maskLeftNum & maskRightNum);
                                    }
                                    else if(maskRightNum == 0){
                                        condition += functionName+"("+maskLeft+", "+maskRight+")";
                                    }
                                }

                            }
                            else{
                                condition += functionName+"("+translate(expr)+", "+maskRight+") == ";
                                condition += functionName+"("+maskLeft+", "+maskRight+")";
                            }
                        }
                        else{
                            condition += translate(expr)+" == ";
                            condition += translate(listExpression->components.at(cnt2));
                        }
                    }
                    cnt2++;
                    if(cnt2 < sz)
                        condition += " && ";
                }
                if(cnt == 0)
                    currentProcedure->addStatement(getIndent() + "if(" + condition + "){\n");
                else 
                    currentProcedure->addStatement(getIndent() + "else if(" + condition + "){\n");
                incIndent();
                currentProcedure->addStatement(getIndent()+"call "+nextState+"("+localDeclArg+");\n");
                decIndent();
                cnt++;
                currentProcedure->addStatement(getIndent()+"}\n");
                currentProcedure->addSucc(nextState);
                addPred(nextState, currentProcedure->getName());
            }            
        }
        if(defaultCondition.size()>0){
            currentProcedure->addStatement(getIndent()+"else{\n");
            incIndent();
            currentProcedure->addStatement(getIndent()+defaultBlock);
            decIndent();
            currentProcedure->addStatement(getIndent()+"}\n");
        }
    }
    return res;
}

cstring Translator::translate(const IR::Argument *argument){
    return translate(argument->expression);
}

cstring Translator::translate(const IR::Constant *constant){
    std::stringstream ss;
    ss << constant->value;
    if(options.ultimateAutomizer){
        if(auto typeBits = constant->type->to<IR::Type_Bits>()) return ss.str();
    }
    return ss.str()+translate(constant->type);
}

cstring Translator::translate(const IR::ConstructorCallExpression *constructorCallExpression){
    return translate(constructorCallExpression->constructedType);
}

cstring Translator::translate(const IR::Cast *cast){
    if (cast->destType->to<IR::Type_Bits>() || cast->destType->to<IR::Type_Name>()){

    // if (auto destType = cast->destType->to<IR::Type_Bits>()){
        int dstSize = -1, srcSize = -1;
        if(auto destType = cast->destType->to<IR::Type_Bits>()){
            dstSize = destType->size;
            updateMaxBitvectorSize(destType);
        }
        else if(auto destType = cast->destType->to<IR::Type_Name>()){
            cstring name = translate(destType);
            if(typeDefs.find(name) != typeDefs.end())
                dstSize = typeDefs[name];
            else return "";
        }

        cstring expr = translate(cast->expr);

        if(auto srcType = cast->expr->type->to<IR::Type_Bits>()){
            updateMaxBitvectorSize(srcType);
            srcSize = srcType->size;
        }
        else if(auto srcType = cast->expr->type->to<IR::Type_Unknown>()){
            if(currentProcedure->parameters.find(expr)!=
                currentProcedure->parameters.end()){
                srcSize = currentProcedure->parameters[expr];
            }
            else if(currentProcedure->declarationVariables.find(expr)!=
                currentProcedure->declarationVariables.end()){
                srcSize = currentProcedure->declarationVariables[expr];
            }
        }

        if(srcSize!=-1){
            if(dstSize < srcSize) {
                if(options.ultimateAutomizer)
                    return "("+expr+"\%"+"power_2_"+toString(dstSize)+"())";
                else
                    return expr+"["+std::to_string(dstSize)+":0]";
            }
            else if(dstSize > srcSize){
                if(options.ultimateAutomizer)
                    return expr;
                else
                    return "0bv"+std::to_string(dstSize-srcSize)+"++"+expr;
            }
            else{
                return expr;
            }
        }
        else{
            return expr;
        }

    }
    return "";
}

cstring Translator::translate(const IR::Slice *slice){
    // if(options.bitBlasting){
    //     cstring res = getTempPrefix();
    //     cstring expr = translate(slice->e0);
    //     int start = atoi(translate(slice->e1));
    //     int end = atoi(translate(slice->e2));
    //     return res;
    // }
    if(options.ultimateAutomizer){
        cstring res = "";
        cstring expr = translate(slice->e0);
        int start = atoi(translate(slice->e1));
        int end = atoi(translate(slice->e2));
        // eg: n[3:0] = n2_n1_n0
        //            = ( (n-n%power_2_0())/power_2_0() %(power_2_3()) )
        res = "( ("+expr+"-"+expr+"\%power_2_"+toString(end)+"())/power_2_"+toString(end)+"()"
            + "\%(power_2_" + toString(start+1-end) + "()) )";
        return res;
    }

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
            updateMaxBitvectorSize(typeBits);
            cstring returnType = translate(typeBits);
            cstring functionName = "band."+returnType;

            if(options.ultimateAutomizer){
                cstring powerFunc = "";
                cstring function = "function {:inline true} "+functionName+"(left:int, right:int) : int{\n";
                
                for(int i = 0; i < typeBits->size; i++){
                    powerFunc = "power_2_"+toString(i)+"()";
                    
                    // eg: band( ((left-left%power_2_0())/power_2_0())%2, 
                    //           ((right-right%power_2_0())/power_2_0())%2 ) * power_2_0()
                    function += "    band( ((left-left\%"+powerFunc+")/"+powerFunc+")\%2, "+
                        "((right-right\%"+powerFunc+")/"+powerFunc+")\%2 ) * " + powerFunc;
                    
                    if(i < typeBits->size-1)
                        function += " +";
                    function += "\n";
                }
                function += "}\n";

                addFunction(functionName, function);
            }
            else
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

cstring Translator::translate(const IR::BoolLiteral *boolLiteral){
    return boolLiteral->toString();
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
    else if (auto typeTypedef = type->to<IR::Type_Typedef>()){
        return translate(typeTypedef);
    }
    return "";
}

cstring Translator::translate(const IR::Type_Bits *typeBits){
    updateMaxBitvectorSize(typeBits);
    // if(options.ultimateAutomizer)
        // return "int";
    std::stringstream ss;
    ss << "bv" << typeBits->size;
    // std::cout << "Type_Bits" << std::endl;
    // std::cout << ss.str() << std::endl;
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
            extractStack.addDeclaration("procedure {:inline 1} "+procName+"(stack:HeaderStack);\n");
            extractStack.addModifiedGlobalVariables("stack.index");
            extractStack.addModifiedGlobalVariables("isValid");
            extractStack.addDeclaration("ensures(isValid[stack[stack.index[stack]]]==true && stack.index[stack]==old(stack.index[stack])+1);\n");
            // incIndent();
            // extractStack.addStatement(getIndent()+"isValid[stack[stack.index[stack]]] := true;\n");
            // extractStack.addStatement(getIndent()+"stack.index[stack] := stack.index[stack]+1;\n");
            // decIndent();
            addProcedure(extractStack);
        }
    }
    return "";
}

cstring Translator::translate(const IR::Type_Typedef *typeTypedef){
    cstring name = translate(typeTypedef->name);
    if(options.ultimateAutomizer){
        if(auto typeBits = typeTypedef->type->to<IR::Type_Bits>()){
            typeDefs[name] = typeBits->size;
            addDeclaration("type "+name+" = int;\n");
        }
        else addDeclaration("type "+name+" = "+translate(typeTypedef->type)+";\n");
    }
    else
        addDeclaration("type "+name+" = "+translate(typeTypedef->type)+";\n");
    return "";
}

cstring Translator::bitBlastingTempDecl(const cstring &tmpPrefix, int size){
    for(int i = 0; i < size; i++){
        cstring tempVar = connect(tmpPrefix, i);
        addDeclaration("var "+tempVar+" : bool;\n");
        addGlobalVariables(tempVar);
        updateVariableSize(tempVar, 0);
        if(currentProcedure != nullptr)
            currentProcedure->addModifiedGlobalVariables(tempVar);
    }
}

cstring Translator::bitBlastingTempAssign(const cstring &tmpPrefix, int start, int end){
    for(int i = start; i <= end; i++){
        currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := false;\n");
    }
}

cstring Translator::exprXor(const cstring &a, const cstring &b){
    // (!a&&b || a&&!b)
    return "(!"+a+" && "+b+") || ("+a+" && !"+b+")";
}

cstring Translator::exprXor(const cstring &a, const cstring &b, const cstring &c){
    // (!a&&!b&&c || !a&&b&&!c || a&&!b&&!c || a&&b&&c)
    return "(!"+a+" && !"+b+" && "+c+") || (!"+a+" && "+b+" && !"+c+") || ("+
           a+" && !"+b+" && !"+c+ ") || ("+a+" && "+b+" && "+c+")";
}

cstring Translator::connect(const cstring &expr, int idx){
    return expr+SPLIT+toString(idx);
}

cstring Translator::integerBitBlasting(int num, int size){
    cstring res = getTempPrefix();
    bitBlastingTempDecl(res, size);
    for(int i = 0; i < size; i++){
        bool bit = num&1;
        num >>= 1;
        if(bit)
            currentProcedure->addStatement(getIndent()+connect(res, i)+" := true;\n");
        else
            currentProcedure->addStatement(getIndent()+connect(res, i)+" := false;\n");
    }
    return res;
}

cstring Translator::bitBlasting(const IR::Operation_Binary *opBinary){
    if (auto arrayIndex = opBinary->to<IR::ArrayIndex>()) {
        return translate(arrayIndex);
    }
    else if (auto mask = opBinary->to<IR::Mask>()) {
        return translate(mask);
    }
    else if (opBinary->left->type->to<IR::Type_Bits>() || 
        currentProcedure->declarationVariables.find(translate(opBinary->left)) != currentProcedure->declarationVariables.end()){
        int size;
        cstring typeName;
        if(auto typeBits = opBinary->left->type->to<IR::Type_Bits>()){
            size = typeBits->size;
            typeName = translate(opBinary->left->type);
        }
        else{
            size = currentProcedure->declarationVariables[translate(opBinary->left)];
            typeName = "bv"+toString(size);
        }
        if (auto shl = opBinary->to<IR::Shl>()){ 
            // the 2nd parameter must be constant integer
            if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>()){
                cstring tmpPrefix = getTempPrefix();
                bitBlastingTempDecl(tmpPrefix, size);

                int right = atoi(translate(opBinary->right));
                cstring left = translate(opBinary->left);

                if(right >= size) bitBlastingTempAssign(tmpPrefix, 0, size-1);
                else{
                    bitBlastingTempAssign(tmpPrefix, size-right, size-1);
                    for(int i = 0; i < size-right; i++){
                        currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)
                            +" := "+connect(left, i-right)+";\n");
                    }
                }
                return tmpPrefix;
            }
            return "";
        }
        else if (auto shr = opBinary->to<IR::Shr>()){
            // the 2nd parameter must be constant integer
            if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>()){
                cstring tmpPrefix = getTempPrefix();
                bitBlastingTempDecl(tmpPrefix, size);

                int right = atoi(translate(opBinary->right));
                cstring left = translate(opBinary->left);

                if(right >= size) bitBlastingTempAssign(tmpPrefix, 0, size-1);
                else{
                    bitBlastingTempAssign(tmpPrefix, 0, right-1);
                    for(int i = right; i < size; i++){
                        currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)
                            +" := "+connect(left, i-right)+";\n");
                    }
                }
                return tmpPrefix;
            }
            return "";
        }
        else if (auto mul = opBinary->to<IR::Mul>()){
            return "";
        }
        else if (auto add = opBinary->to<IR::Add>()){
            /*  Example:
                    vector<bool> res(a.size(), false);
                    res[0] = a[0]^b[0];        bool tmp1 = a[0]&b[0];
                    res[1] = a[1]^b[1]^tmp1;   bool tmp2 = a[1]&b[1] || a[1]&tmp1 || b[1]&tmp1;
                    res[2] = a[2]^b[2]^tmp2;   bool tmp3 = a[2]&b[2] || a[2]&tmp1 || b[2]&tmp2;
                    return res;
                Note that:
                    a[0]^b[0] = a[0]&!b[0] || !a[0]&b[0]
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, size);

            std::vector<cstring> tmpPrefixes;
            for(int i = 0; i < size; i++){
                tmpPrefixes.push_back(getTempPrefix());
                bitBlastingTempDecl(tmpPrefixes.back(), 1);
            }

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }
            currentProcedure->addStatement(getIndent()+connect(tmpPrefix, 0)+" := "
                +exprXor(connect(left, 0), connect(right, 0))+";\n");
            currentProcedure->addStatement(getIndent()+connect(tmpPrefixes[0], 0)+" := "
                +connect(left, 0)+" && "+connect(right, 0)+";\n");
            for(int i = 1; i < size; i++){
                currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := "
                    +exprXor(connect(left, i), connect(right, i), connect(tmpPrefixes[i-1], 0))+";\n");
                currentProcedure->addStatement(getIndent()+connect(tmpPrefixes[i], 0)+" := ("
                    +connect(left, i)+" && "+connect(right, i)+ ") || ("
                    +connect(left, i)+" && "+connect(tmpPrefixes[i-1], 0)+") || ("
                    +connect(right, i)+" && "+connect(tmpPrefixes[i-1], 0)+");\n");
            }
            return tmpPrefix;
        }
        else if (auto addSat = opBinary->to<IR::AddSat>()) {
            return "";
        }
        else if (auto sub = opBinary->to<IR::Sub>()) {
            /*  Example:
                vector<bool> tmp(b.size()), res(b.size());
                // tmp = ~b+1
                tmp[0] = (!b[0])^1;     bool tmp1 = (!b[0])&1;
                tmp[1] = (!b[1])^tmp1;  bool tmp2 = (!b[1])&tmp1;
                tmp[2] = (!b[2])^tmp2;  bool tmp3 = (!b[2])&tmp2;
                // a + tmp
                res[0] = a[0]^tmp[0];        bool tmp4 = a[0]&tmp[0];
                res[1] = a[1]^tmp[1]^tmp4;   bool tmp5 = a[1]&tmp[1] || a[1]&tmp4 || tmp[1]&tmp4;
                res[2] = a[2]^tmp[2]^tmp5;   bool tmp6 = a[2]&tmp[2] || a[2]&tmp5 || tmp[2]&tmp5;
                return res;
            */

            // res = left-right
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, size);

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            // -right
            cstring negRight = getTempPrefix();
            bitBlastingTempDecl(negRight, size);

            cstring negRightTmp = getTempPrefix();
            bitBlastingTempDecl(negRightTmp, size);
            
            // negRight[0] := (!right[0])^true
            currentProcedure->addStatement(getIndent()+connect(negRight, 0)+" := "+
                exprXor("(!"+connect(right, 0)+")", "true")+";\n");
            // negRightTmp[0] := (!right[0])&true
            currentProcedure->addStatement(getIndent()+connect(negRightTmp, 0)+" := (!"+
                connect(right, 0)+") && true;\n");
            for(int i = 1; i < size; i++){
                // negRight[i] := (!right[i]) ^ negRightTmp[i-1]
                currentProcedure->addStatement(getIndent()+connect(negRight, i)+" := "+
                    exprXor("(!"+connect(right, i)+")", connect(negRightTmp, i-1))+";\n");
                // negRightTmp[i] := (!right[i]) & negRightTmp[i-1]
                currentProcedure->addStatement(getIndent()+connect(negRight, i)+" := (!"+
                    connect(right, i)+") && "+connect(negRightTmp, i-1)+";\n");
            }

            cstring resTmp = getTempPrefix();
            bitBlastingTempDecl(resTmp, size);
            // res[0] := left[0] ^ negRight[0]
            currentProcedure->addStatement(getIndent()+connect(tmpPrefix, 0)+" := "+
                exprXor(connect(left, 0), connect(negRight, 0))+";\n");
            // resTmp[0] := left[0] & negRight[0]
            currentProcedure->addStatement(getIndent()+connect(resTmp, 0)+" := "+
                connect(left, 0)+" && "+connect(negRight, 0)+";\n");
            for(int i = 1; i < size; i++){
                // res[i] := left[i] ^ negRight[i] ^ resTmp[i-1]
                currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := "+
                    exprXor(connect(left, i), connect(negRight, i), connect(resTmp, i-1))+";\n");
                currentProcedure->addStatement(getIndent()+connect(resTmp, i)+" := ("+
                    connect(left, i)+" && "+connect(right, i)+") || ("+
                    connect(left, i)+" && "+connect(resTmp, i-1)+") || ("+
                    connect(right, i)+" && "+connect(resTmp, i-1)+");\n");
            }

            return tmpPrefix;
        }
        else if (auto subSat = opBinary->to<IR::SubSat>()) {
            return "";
        }
        else if (auto bAnd = opBinary->to<IR::BAnd>()) {
            /*  Example:
                    vector<bool> res(a.size(), false);
                    res[0] = a[0]&b[0];
                    res[1] = a[1]&b[1];
                    res[2] = a[2]&b[2];
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, size);
            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i < size; i++){
                currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := "
                    +connect(left, i)+" && "+connect(right, i)+";\n");
            }
            
            return tmpPrefix;
        }
        else if (auto bOr = opBinary->to<IR::BAnd>()) {
            /*  Example:
                    vector<bool> res(a.size(), false);
                    res[0] = a[0]|b[0];
                    res[1] = a[1]|b[1];
                    res[2] = a[2]|b[2];
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, size);
            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i < size; i++){
                currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := "
                    +connect(left, i)+" || "+connect(right, i)+";\n");
            }
            
            return tmpPrefix;
        }
        else if (auto bXor = opBinary->to<IR::BXor>()) {
            /*  Example:
                    vector<bool> res(a.size(), false);
                    res[0] = a[0]^b[0];
                    res[1] = a[1]^b[1];
                    res[2] = a[2]^b[2];
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, size);
            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i < size; i++){
                currentProcedure->addStatement(getIndent()+connect(tmpPrefix, i)+" := "
                    +exprXor(connect(left, i), connect(right, i))+";\n");
            }
            
            return tmpPrefix;
        }
        else if (auto geq = opBinary->to<IR::Geq>()) {
            /*  Example:
                    bool tmp1 = a[2] && !b[2];
                    bool tmp2 = (a[2] == b[2]) && (a[1] && !b[1]);
                    bool tmp3 = (a[2] == b[2]) && (a[1] == b[1]) && (a[0] && !b[0]);
                    bool tmp4 = (a[2] == b[2]) && (a[1] == b[1]) && (a[0] == b[0]);
                    bool res = tmp1 || tmp2 || tmp3 || tmp4;
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);

            cstring tmpPrefix2 = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix2, size+1);

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i <= size; i++){
                cstring stmt = getIndent()+connect(tmpPrefix2, i) + " := ";
                for(int j = 0; j < i; j++){
                    stmt += "("+connect(left, size-1-j)+"=="+connect(right, size-1-j)+")";
                    if(j < i-1) stmt += " && ";
                }
                if(i == size){
                    stmt += ";\n";
                }
                else{
                    if(i != 0) stmt += " && ";
                    stmt += "("+connect(left, size-1-i)+"&&"+"!"+connect(right, size-1-i)+");\n";
                }
                currentProcedure->addStatement(stmt);
            }
            cstring stmt = getIndent()+connect(tmpPrefix, 0) + " := ";
            for(int i = 0; i <= size; i++){
                stmt += connect(tmpPrefix2, i);
                if(i < size) stmt += " || ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
        else if (auto leq = opBinary->to<IR::Leq>()) {
            /*  Example:
                    bool tmp1 = !a[2] && b[2];
                    bool tmp2 = (a[2] == b[2]) && (!a[1] && b[1]);
                    bool tmp3 = (a[2] == b[2]) && (a[1] == b[1]) && (!a[0] && b[0]);
                    bool tmp4 = (a[2] == b[2]) && (a[1] == b[1]) && (a[0] == b[0]);
                    bool res = tmp1 || tmp2 || tmp3 || tmp4;
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);

            cstring tmpPrefix2 = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix2, size+1);

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i <= size; i++){
                cstring stmt = getIndent()+connect(tmpPrefix2, i) + " := ";
                for(int j = 0; j < i; j++){
                    stmt += "("+connect(left, size-1-j)+"=="+connect(right, size-1-j)+")";
                    if(j < i-1) stmt += " && ";
                }
                if(i == size){
                    stmt += ";\n";
                }
                else{
                    if(i != 0) stmt += " && ";
                    stmt += "(!"+connect(left, size-1-i)+"&&"+connect(right, size-1-i)+");\n";
                }
                currentProcedure->addStatement(stmt);
            }
            cstring stmt = getIndent()+connect(tmpPrefix, 0) + " := ";
            for(int i = 0; i <= size; i++){
                stmt += connect(tmpPrefix2, i);
                if(i < size) stmt += " || ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
        else if (auto grt = opBinary->to<IR::Grt>()) {
            /*  Example:
                    bool tmp1 = a[2] && !b[2];
                    bool tmp2 = (a[2] == b[2]) && (a[1] && !b[1]);
                    bool tmp3 = (a[2] == b[2]) && (a[1] == b[1]) && (a[0] && !b[0]);
                    bool res = tmp1 || tmp2 || tmp3;
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);

            cstring tmpPrefix2 = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix2, size);

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i < size; i++){
                cstring stmt = getIndent()+connect(tmpPrefix2, i) + " := ";
                for(int j = 0; j < i; j++){
                    stmt += "("+connect(left, size-1-j)+"=="+connect(right, size-1-j)+")";
                    if(j < i-1) stmt += " && ";
                }
                if(i != 0) stmt += " && ";
                stmt += "("+connect(left, size-1-i)+"&&"+"!"+connect(right, size-1-i)+");\n";
                currentProcedure->addStatement(stmt);
            }
            cstring stmt = getIndent()+connect(tmpPrefix, 0) + " := ";
            for(int i = 0; i < size; i++){
                stmt += connect(tmpPrefix2, i);
                if(i < size-1) stmt += " || ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
        else if (auto lss = opBinary->to<IR::Lss>()) {
            /*  Example:
                    bool tmp1 = !a[2] && b[2];
                    bool tmp2 = (a[2] == b[2]) && (!a[1] && b[1]);
                    bool tmp3 = (a[2] == b[2]) && (a[1] == b[1]) && (!a[0] && b[0]);
                    bool res = tmp1 || tmp2 || tmp3;
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);

            cstring tmpPrefix2 = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix2, size);

            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            for(int i = 0; i < size; i++){
                cstring stmt = getIndent()+connect(tmpPrefix2, i) + " := ";
                for(int j = 0; j < i; j++){
                    stmt += "("+connect(left, size-1-j)+"=="+connect(right, size-1-j)+")";
                    if(j < i-1) stmt += " && ";
                }
                if(i != 0) stmt += " && ";
                stmt += "(!"+connect(left, size-1-i)+"&&"+connect(right, size-1-i)+");\n";
                currentProcedure->addStatement(stmt);
            }
            cstring stmt = getIndent()+connect(tmpPrefix, 0) + " := ";
            for(int i = 0; i < size; i++){
                stmt += connect(tmpPrefix2, i);
                if(i < size-1) stmt += " || ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
        else if (auto equ = opBinary->to<IR::Equ>()) {
            /*  Example:
                    bool res;
                    res = a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);
            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            cstring stmt = getIndent()+connect(tmpPrefix, 0)+ " := ";
            for(int i = 0; i < size; i++){
                stmt += "("+connect(left, i)+"=="+connect(right, i)+")";
                if(i != size-1) stmt += " && ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
        else if (auto neq = opBinary->to<IR::Neq>()) {
            /*  Example:
                    bool res;
                    res = a[0]!=b[0] && a[1]!=b[1] && a[2]!=b[2];
                    return res;
            */
            cstring tmpPrefix = getTempPrefix();
            bitBlastingTempDecl(tmpPrefix, 1);
            cstring left = translate(opBinary->left), right = translate(opBinary->right);
            if(isNumber(left)){
                left = integerBitBlasting(atoi(left), size);
            }
            if(isNumber(right)){
                right = integerBitBlasting(atoi(right), size);
            }

            cstring stmt = getIndent()+connect(tmpPrefix, 0)+ " := ";
            for(int i = 0; i < size; i++){
                stmt += "("+connect(left, i)+"!="+connect(right, i)+")";
                if(i != size-1) stmt += " || ";
            }
            stmt += ";\n";
            currentProcedure->addStatement(stmt);
            return connect(tmpPrefix, 0);
        }
    }
    else if (opBinary->left->type->to<IR::Type_Boolean>()){
        std::cout << opBinary->left->type->toString() << std::endl;
        return "("+translate(opBinary->left)+") "+opBinary->getStringOp()+" ("+translate(opBinary->right)+")";
    }
    return "";
}

cstring Translator::translateUA(const IR::Operation_Binary *opBinary){
    if (auto arrayIndex = opBinary->to<IR::ArrayIndex>()) {
        return translate(arrayIndex);
    }
    else if (auto mask = opBinary->to<IR::Mask>()) {
        return translate(mask);
    }
    // currentProcedure->declarationVariables[translate(declVar->name)] = typeBits->size;
            // }
    // else if (auto typeBits = opBinary->left->type->to<IR::Type_Bits>()){
    else if (opBinary->left->type->to<IR::Type_Bits>() || 
        currentProcedure->declarationVariables.find(translate(opBinary->left)) != currentProcedure->declarationVariables.end()){
        int size;
        cstring typeName;
        if(auto typeBits = opBinary->left->type->to<IR::Type_Bits>()){
            size = typeBits->size;
            typeName = translate(opBinary->left->type);
        }
        else{
            size = currentProcedure->declarationVariables[translate(opBinary->left)];
            typeName = "bv"+toString(size);
        }
        cstring function = "";
        if (auto shl = opBinary->to<IR::Shl>()){ 
            // the 2nd parameter must be constant integer
            if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>()){
                // eg: shl.bv8_2(num:int) : int {(num*power_2_2())%power_2_8()}
                cstring right = translate(opBinary->right);
                cstring powerFunc = "power_2_"+right+"()";
                cstring funcName = "shl."+typeName+"_"+right;

                function = "function {:inline true} "+funcName+"(num:int) : ";
                function += "int {(num*"+powerFunc+")\%"+powerFunc+"}\n";
                
                addFunction(funcName, function);

                return funcName+"("+translate(opBinary->left)+")";
            }
            else{
                cstring left = translate(opBinary->left);
                if(isNumber(left)){
                    cstring funcName = "shl."+typeName+"_"+left+"_n";
                    int leftNum = atoi(std::string(left.c_str()).c_str());

                    function = "function {:inline true} "+funcName+"(n:int) : ";
                    function += "int {\n";
                    function += "    if(n == 0) then "+left+"\n";
                    bool flag = false;
                    for(int i = 1; i < size; i++){
                        cstring shl_funcName = "shl."+typeName+"_"+toString(i);
                        function += "    else if(n == "+toString(i)+") then ";
                        long long tmp = leftNum;
                        tmp <<= i;
                        if(flag || tmp > 2147483647){
                            flag = true;
                            function += toString(leftNum)+"*power_2_"+toString(i)+"()\n";
                        }
                        else{
                            function += toString(leftNum << i)+"\n";
                        }
                        // function += shl_funcName+"(num)\n";
                    }
                    function += "    else 0\n";
                    function += "}\n";

                    addFunction(funcName, function);

                    return funcName+"("+translate(opBinary->right)+")";
                }
                else{
                    cstring funcName = "shl."+typeName+"_n";

                    for(int i = 1; i <= size; i++){
                        cstring shl_function = "";
                        cstring shl_funcName = "shl."+typeName+"_"+toString(i);
                        cstring shl_powerFunc = "power_2_"+toString(i)+"()";
                        shl_function = "function {:inline true} "+shl_funcName+"(num:int) : ";
                        shl_function += "int {(num*"+shl_powerFunc+")\%"+shl_powerFunc+"}\n";
                        addFunction(shl_funcName, shl_function);
                    }
                    function = "function {:inline true} "+funcName+"(num:int, n:int) : ";
                    function += "int {\n";
                    function += "    if(n == 0) then num\n";
                    for(int i = 1; i < size; i++){
                        cstring shl_funcName = "shl."+typeName+"_"+toString(i);
                        function += "    else if(n == "+toString(i)+") then ";
                        function += shl_funcName+"(num)\n";
                    }
                    function += "    else 0\n";
                    function += "}\n";

                    addFunction(funcName, function);

                    return funcName+"("+translate(opBinary->left)+","+translate(opBinary->right)+")";
                }
            }
        }
        else if (auto shr = opBinary->to<IR::Shr>()){
            // the 2nd parameter must be constant integer
            if(auto typeInfInt = opBinary->right->type->to<IR::Type_InfInt>()){
                // eg: shr.bv8_2(num:int) : int {(num-num%power_2_2())/power_2_2()}
                cstring right = translate(opBinary->right);
                cstring powerFunc = "power_2_"+right+"()";
                cstring funcName = "shr."+typeName+"_"+right;

                function = "function {:inline true} "+funcName+"(num:int) : ";
                function += "int {(num-num\%"+powerFunc+")/"+powerFunc+"}\n";
                
                addFunction(funcName, function);
                
                return funcName+"("+translate(opBinary->left)+")";
            }
            else{
                return "";
            }
        }
        else if (auto mul = opBinary->to<IR::Mul>()){
            cstring powerFunc = "power_2_"+toString(size)+"()";
            cstring funcName = "mul."+typeName;
            
            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                "(left\%"+powerFunc+")*(right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            
            addFunction(funcName, function);
            
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto add = opBinary->to<IR::Add>()){
            // TODO: left/right may be integers
            cstring powerFunc = "power_2_"+toString(size)+"()";
            cstring funcName = "add."+typeName;

            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                "(left\%"+powerFunc+")+(right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            
            addFunction(funcName, function);
            
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto addSat = opBinary->to<IR::AddSat>()) {
            // TODO: left/right may be integers
            cstring powerFunc = "power_2_"+toString(size)+"()";
            cstring funcName = "add."+typeName;

            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                "(left\%"+powerFunc+")+(right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            
            addFunction(funcName, function);
            
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto sub = opBinary->to<IR::Sub>()) {
            // overflow???
            cstring powerFunc = "power_2_"+toString(size)+"()";
            cstring funcName = "sub."+typeName;

            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                powerFunc+" + (left\%"+powerFunc+") - (right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            
            addFunction(funcName, function);

            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto subSat = opBinary->to<IR::SubSat>()) {
            // overflow???
            cstring powerFunc = "power_2_"+toString(size)+"()";
            cstring funcName = "sub."+typeName;

            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                powerFunc+" + (left\%"+powerFunc+") - (right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            
            addFunction(funcName, function);

            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto bAnd = opBinary->to<IR::BAnd>()) {
            cstring powerFunc = "";
            cstring funcName = "band."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{\n";
            
            for(int i = 0; i < size; i++){
                powerFunc = "power_2_"+toString(i)+"()";
                
                // eg: band( ((left-left%power_2_0())/power_2_0())%2, 
                //           ((right-right%power_2_0())/power_2_0())%2 ) * power_2_0()
                function += "    band( ((left-left\%"+powerFunc+")/"+powerFunc+")\%2, "+
                    "((right-right\%"+powerFunc+")/"+powerFunc+")\%2 ) * " + powerFunc;
                
                if(i < size-1)
                    function += " +";
                function += "\n";
            }
            function += "}\n";

            addFunction(funcName, function);

            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto bOr = opBinary->to<IR::BOr>()) {
            cstring powerFunc = "";
            cstring funcName = "bor."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{\n";
            
            for(int i = 0; i < size; i++){
                powerFunc = "power_2_"+toString(i)+"()";

                // eg: bor( ((left-left%power_2_0())/power_2_0())%2, 
                //          ((right-right%power_2_0())/power_2_0())%2 ) * power_2_0()
                function += "    bor( ((left-left\%"+powerFunc+")/"+powerFunc+")\%2, "+
                    "((right-right\%"+powerFunc+")/"+powerFunc+")\%2 ) * " + powerFunc;
                
                if(i < size-1)
                    function += " +";
                function += "\n";
            }
            function += "}\n";

            addFunction(funcName, function);

            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto bXor = opBinary->to<IR::BXor>()) {
            cstring powerFunc = "";
            cstring funcName = "bxor."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : int{\n";
            
            for(int i = 0; i < size; i++){
                powerFunc = "power_2_"+toString(i)+"()";

                // eg: bor( ((left-left%power_2_0())/power_2_0())%2, 
                //          ((right-right%power_2_0())/power_2_0())%2 ) * power_2_0()
                function += "    bxor( ((left-left\%"+powerFunc+")/"+powerFunc+")\%2, "+
                    "((right-right\%"+powerFunc+")/"+powerFunc+")\%2 ) * " + powerFunc;
                
                if(i < size-1)
                    function += " +";
                function += "\n";
            }
            function += "}\n";

            addFunction(funcName, function);

            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto geq = opBinary->to<IR::Geq>()) {
            // eg: bsge.bv8(left:int, right:int) : bool{left >= right}
            cstring funcName = "bsge."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{"
                + "left >= right" + "}\n";
            addFunction(funcName, function);
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto leq = opBinary->to<IR::Leq>()) {
            // eg: bsle.bv8(left:int, right:int) : bool{left <= right}
            cstring funcName = "bsle."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{"
                + "left <= right" + "}\n";
            addFunction(funcName, function);
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto grt = opBinary->to<IR::Grt>()) {
            // eg: bugt.bv8(left:int, right:int) : bool{left > right}
            cstring funcName = "bugt."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{"
                + "left > right" + "}\n";
            addFunction(funcName, function);
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto lss = opBinary->to<IR::Lss>()) {
            // eg: bult.bv8(left:int, right:int) : bool{left < right}
            cstring funcName = "bult."+typeName;
            function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{"
                + "left < right" + "}\n";
            addFunction(funcName, function);
            return funcName+"("+translate(opBinary->left)+", "+translate(opBinary->right)+")";
        }
        else if (auto equ = opBinary->to<IR::Equ>()) {
            return "(" + translate(opBinary->left) + " == " + translate(opBinary->right) + ")";
        }
        else if (auto neq = opBinary->to<IR::Neq>()) {
            return "(" + translate(opBinary->left) + " != " + translate(opBinary->right) + ")";
        }
    }
    else
        return "("+translate(opBinary->left)+") "+opBinary->getStringOp()+" ("+translate(opBinary->right)+")";
    return "";
}

cstring Translator::translate(const IR::Operation_Binary *opBinary){
    if(options.bitBlasting){
        return bitBlasting(opBinary);
    }

    if(options.ultimateAutomizer){
        return translateUA(opBinary);
    }

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
    else if (auto equ = opBinary->to<IR::Equ>()) {
        return "(" + translate(opBinary->left) + " == " + translate(opBinary->right) + ")";
    }
    else if (auto equ = opBinary->to<IR::Neq>()) {
        return "(" + translate(opBinary->left) + " != " + translate(opBinary->right) + ")";
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
    else if (auto cmpl = opUnary->to<IR::Cmpl>()) {
        if(auto typeBits = opUnary->type->to<IR::Type_Bits>()){
            if(options.ultimateAutomizer){
                cstring returnType = translate(opUnary->type);
                cstring powerFunc = "";
                cstring funcName = "bnot."+returnType;
                cstring function = "function {:inline true} "+funcName+"(num:int) : int{\n";
                int size = typeBits->size;

                for(int i = 0; i < size; i++){
                    powerFunc = "power_2_"+toString(i)+"()";
                    
                    // eg: bnot( ((num-num%power_2_0())/power_2_0())%2 ) * power_2_0()
                    function += "    bnot( ((num-num\%"+powerFunc+")/"+powerFunc+")\%2 ) * " + powerFunc;
                    
                    if(i < size-1)
                        function += " +";
                    function += "\n";
                }
                function += "}\n";

                addFunction(funcName, function);

                return funcName+"("+translate(opUnary->expr)+")";
            }
        }

        // cstring typeName = translate(opBinary->left->type);
        cstring returnType = translate(opUnary->type);
        cstring functionName = "bnot."+returnType;
        cstring opbuiltin = "bvnot";
        cstring res = "\nfunction {:bvbuiltin \""+opbuiltin+"\"} "+functionName;
        res += "(left:"+returnType+") returns("+returnType+");\n";
        // addDeclaration(res);

        if(functions.find(functionName)==functions.end()){
            functions.insert(functionName);
            addDeclaration(res);
        }
        return functionName+"("+translate(opUnary->expr)+")";
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
    if(options.addForwardingAssertion){
        mainProcedure.addStatement("    assert(forward || drop);\n");
    }
}

void Translator::translate(const IR::Type_Error *typeError){
    // std::cout << "translate Type_Error: " << typeError->error << std::endl;
    // for(auto elem:typeError->members){
    //     if(auto member = elem->to<IR::Declaration_ID>()){
    //         std::cout << member->name << std::endl;
    //     }
    // }
}

void Translator::translate(const IR::Type_Extern *typeExtern){
    // std::cout << "translate Type_Extern" << std::endl;
}

void Translator::translate(const IR::Type_Enum *typeEnum){
    // std::cout << "translate Type_Enum" << std::endl;
}

void Translator::translate(const IR::Declaration_Instance *instance, cstring instanceName){
    cstring typeName = translate(instance->type);
    cstring name = instance->getName().toString();

    if(instanceName != "") name = instanceName;

    // std::cout << "**instance: " << typeName << " " << name << std::endl;
    // std::cout << "**instance: " << instance->toString() << std::endl;

    if(typeName=="V1Switch"){
        BoogieProcedure main = BoogieProcedure(name);
        main.addDeclaration("procedure {:inline 1} "+name+"()\n");
        incIndent();

        if(options.whileLoop) {
            // if(options.addInvariant){
            //     main.addStatement(getIndent()+"while (true)\n");
            //     main.addStatement(getIndent()+"invariant(true);\n");
            //     // need to specify the variable set for invariant
            //     main.addStatement(getIndent()+"{\n");
            // }else{
            //     main.addStatement(getIndent()+"while (true){\n");
            // }
            main.addStatement(getIndent()+"call havocProcedure();\n");
            main.addSucc(havocProcedure.getName());
            // main.addStatement(getIndent()+"call clear_drop();\n");
            // main.addSucc("clear_drop");
            // main.addStatement(getIndent()+"call clear_forward();\n");
            // main.addSucc("clear_forward");
            addPred(havocProcedure.getName(), name);
        }

        int cnt = instance->arguments->size();
        for(auto argument:*instance->arguments){
            cnt--;
            if(cnt != 0){
                cstring procName = translate(argument->expression);
                if(options.ultimateAutomizer){
                    if(auto typeParser = argument->expression->type->to<IR::Type_Parser>()){
                        procName = "_parser_"+procName;
                    }
                }
                main.addStatement(getIndent()+"call "+procName+"();\n");
                main.addSucc(procName);
                addPred(procName, name);
            }
            else
                deparser = translate(argument->expression);
        }
        main.addStatement(getIndent()+"if(forward == false){\n");
        incIndent();
        main.addStatement(getIndent()+"drop := true;\n");
        decIndent();
        main.addStatement(getIndent()+"}\n");

        decIndent();

        // add children
        addProcedure(main);
        if(options.whileLoop){
            // if(options.p4ltlSpec){
                // mainProcedure.addStatement("        call "+name+"();\n");
            // }
            // else{
                mainProcedure.addStatement("    while(true){\n");
                mainProcedure.addStatement("        call "+name+"();\n");
                mainProcedure.addStatement("    }\n");
            // }
        }
        else
            mainProcedure.addStatement("    call "+name+"();\n");
        mainProcedure.addSucc(name);
        addPred(name, mainProcedure.getName());
    }

    // TOFO: rename
    // std::cout << "name: " << name << std::endl;
    if(typeName=="register"){

        // size
        auto constant = (*instance->arguments)[0]->expression->to<IR::Constant>();
        cstring size = toString(constant->value);

        // std::cout << "size: " << size << std::endl;

        // value type
        auto valueType = instance->type->to<IR::Type_Specialized>();
        cstring valueTypeName = translate((*valueType->arguments)[0]);

        if(options.ultimateAutomizer && (*valueType->arguments)[0]->to<IR::Type_Bits>()){
            valueTypeName = "int";
        }

        // std::cout << "valueTypeName: " << valueTypeName << std::endl;

        // size
        cstring sizeTypeName;
        if((*valueType->arguments).size() > 1){
            sizeTypeName = translate((*valueType->arguments)[1]);
        }
        else{
            if(options.ultimateAutomizer)
                sizeTypeName = "int";
            else
                sizeTypeName = "bv32";
        }

        if(options.ultimateAutomizer)
            sizeTypeName = "int";
        else
            sizeTypeName = "bv32";

        // std::cout << "sizeTypeName: " << sizeTypeName << std::endl;

        // Consider the register as a set of variables (e.g., reg1, reg2, ...)
        // TODO: rename register
        // addDeclaration("\n// Register "+name+"\n");
        // for(int i = 0; i < constant->value; i++){
            // addDeclaration(name+toString(i)+":"+valueTypeName+";\n");
        // }

        addDeclaration("\n// Register "+name+"\n");
        addDeclaration("var "+name+":["+sizeTypeName+"]"+valueTypeName+";\n");
        addDeclaration("const "+name+".size:"+sizeTypeName+";\n");
        
        if(sizeTypeName == "int") addDeclaration("axiom "+name+".size == "+size+";\n");
        else addDeclaration("axiom "+name+".size == "+size+sizeTypeName+";\n");
        
        addGlobalVariables(name);
        // std::cout << typeName << " " << name << " " << size << " " << 
        //     valueTypeName << std::endl;


        /* read and write functions 
           may be related to renaming
        */
        // read function
        BoogieProcedure read = BoogieProcedure(name+".read");
        // one parameter, return reg[index]
        read.addDeclaration("function {:inline true}"+read.getName()+"(reg:["+sizeTypeName+"]"+valueTypeName
            +", index:"+sizeTypeName+")"+"returns ("+valueTypeName+") {reg[index]}\n");
        addProcedure(read);

        // write function
        BoogieProcedure write = BoogieProcedure(name+".write");
        // two parameters, reg[index] := value
        write.addDeclaration("procedure {:inline 1} "+write.getName()+"(index:"+sizeTypeName+", value:"
            +valueTypeName+")\n");
        incIndent();
        write.addStatement(getIndent()+name+"[index] := value;\n");
        decIndent();
        write.addModifiedGlobalVariables(name);
        addProcedure(write);


        // Register initialization
        // cstring registerInitName = name+".init";
        // BoogieProcedure registerInit = BoogieProcedure(registerInitName);

        // registerInit.addDeclaration("procedure {:inline 1} "+registerInitName+"();\n");
        // registerInit.addDeclaration("    ensures(forall idx:"+sizeTypeName+":: "+name+"[idx]==0"+valueTypeName+");\n");
        // registerInit.addModifiedGlobalVariables(name);
        
        // addProcedure(registerInit);
        // mainProcedure.addFrontStatement("    call "+registerInitName+"();\n");
        // mainProcedure.addModifiedGlobalVariables(name);
        // addPred(registerInitName, mainProcedure.getName());
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
    else{

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
        else{
            auto typeName = field->type->to<IR::Type_Name>();
            cstring name = translate(typeName->path);
            addDeclaration("var "+arg+"."+field->name+":"+name+";\n");
            addGlobalVariables(arg+"."+field->name);
        }

        // std::cout << "finding " << fieldName << std::endl;
        // std::cout << (headers.find(fieldName)!=headers.end()) << std::endl;
        // std::cout << (structs.find(fieldName)!=structs.end()) << std::endl;
    }
    else if(field->type->node_type_name() == "Type_Bits"){
        auto typeBits = field->type->to<IR::Type_Bits>();
        updateMaxBitvectorSize(typeBits);
        cstring fieldName = arg+"."+field->name;
        if(options.bitBlasting){
            bitBlastingTempDecl(fieldName, typeBits->size);
        }
        else if(options.ultimateAutomizer){
            addDeclaration("var "+fieldName+":int;\n");
        }
        else
            addDeclaration("var "+fieldName+":bv"+std::to_string(typeBits->size)+";\n");
        addGlobalVariables(fieldName);
        updateVariableSize(fieldName, typeBits->size);
        if(fieldName.startsWith("meta.") || fieldName.startsWith("standard_metadata.")){
            havocProcedure.addStatement("    "+fieldName+" := 0;\n");
            havocProcedure.addModifiedGlobalVariables(fieldName);
        }
    }
    else if(field->type->node_type_name() == "Type_Varbits"){
        auto typeVarbits = field->type->to<IR::Type_Varbits>();
        // std::cout << "Type_Varbits " << typeVarbits->size << std::endl;
        // updateMaxBitvectorSize(typeVarbits->size);
        if(options.bitBlasting){
            bitBlastingTempDecl(arg+"."+field->name, typeVarbits->size);
        }
        else if(options.ultimateAutomizer){
            addDeclaration("var "+arg+"."+field->name+":int;\n");
        }
        else
            addDeclaration("var "+arg+"."+field->name+":bv"+std::to_string(typeVarbits->size)+";\n");
        addGlobalVariables(arg+"."+field->name);
        // updateVariableSize(arg+"."+field->name, typeVarbits->size);
    }
    else if(field->type->node_type_name() == "Type_Stack"){
        addDeclaration("const "+arg+"."+field->name+":HeaderStack;\n");
        if (auto typeStack = field->type->to<IR::Type_Stack>()){
            translate(typeStack, arg+"."+field->name);
        }
    }
    else if(field->type->node_type_name() == "Type_Typedef"){
        auto typeTypedef = field->type->to<IR::Type_Typedef>();
        addDeclaration("var "+arg+"."+field->name+":"+translate(typeTypedef->name)+";\n");
        addGlobalVariables(arg+"."+field->name);
    }
}

void Translator::translate(const IR::Type_Header *typeHeader){
    // cstring arg = ""
    // addDeclaration("\n// Header "+typeHeader->name.toString()+"\n");
    // addDeclaration("var "+arg+":Ref;\n");
    // addGlobalVariables(arg);
    // for(const IR::StructField* field:typeHeader->fields){
    //     translate(field, arg);
    // }
    // for(const IR::StructField* field:typeHeader->fields){
    //     translate(field);
    // }
    // std::cout << "translate typeHeader" << std::endl;
}

void Translator::translate(const IR::Type_Header *typeHeader, cstring arg){
    // std::cout << "\n// Header "+arg+"\n" << std::endl;
    addDeclaration("\n// Header "+typeHeader->name.toString()+"\n");
    addDeclaration("var "+arg+":Ref;\n");
    addGlobalVariables(arg);
    addDeclaration("var "+arg+".valid:bool;\n");
    addGlobalVariables(arg+".valid");
    updateVariableSize(arg+".valid", 0);

    havocProcedure.addStatement("    "+arg+".valid := false;\n");
    havocProcedure.addModifiedGlobalVariables(arg+".valid");
    // havocProcedure.addStatement("    isValid["+arg+"] := false;\n");
    // havocProcedure.addModifiedGlobalVariables("isValid");
    if(currentProcedure==nullptr || currentProcedure->getName().find("_parser_") == nullptr){
        havocProcedure.addStatement("    emit["+arg+"] := false;\n");
        havocProcedure.addModifiedGlobalVariables("emit");
    }
    for(const IR::StructField* field:typeHeader->fields){
        translate(field, arg);
        cstring fieldName = arg + "." + field->name;

        cstring oldFieldName = "_old_"+fieldName;
        if(options.p4ltlSpec){
            for(auto item:p4ltlSpec){
                std::set<cstring> oldExprs = ltlTranslator->getOldExprs(item.second);
                if(oldExprs.find(fieldName) != oldExprs.end()){
                    translate(field, "_old_"+arg);
                    break;
                }
            }
        }
        else{
            translate(field, "_old_"+arg);
        }

        if(options.bitBlasting){
            if(auto typeBits = field->type->to<IR::Type_Bits>()){
                for(int i = 0; i < typeBits->size; i++){
                    havocProcedure.addStatement("    havoc "+connect(fieldName, i)+";\n");
                    havocProcedure.addModifiedGlobalVariables(connect(fieldName, i));
                }
                for(int i = 0; i < typeBits->size; i++){
                    havocProcedure.addStatement("    "+connect(oldFieldName, i)+" := "+
                        connect(fieldName, i) +";\n");
                    havocProcedure.addModifiedGlobalVariables(connect(oldFieldName, i));
                }
            }
        }
        else{
            if(currentProcedure==nullptr || currentProcedure->getName().find("_parser_") == nullptr){
                havocProcedure.addStatement("    havoc "+fieldName+";\n");
                if(auto typeBits = field->type->to<IR::Type_Bits>()){
                    havocProcedure.addStatement("    assume(0 <= "+fieldName+" && "+
                        fieldName + " <= power_2_" +toString(typeBits->size) +"() );\n");
                }
                havocProcedure.addModifiedGlobalVariables(fieldName);
            }

            if(options.p4ltlSpec){
                for(auto item:p4ltlSpec){
                    std::set<cstring> oldExprs = ltlTranslator->getOldExprs(item.second);
                    if(oldExprs.find(fieldName) != oldExprs.end()){
                        havocProcedure.addStatement("    "+oldFieldName+" := "+
                           fieldName +";\n");
                        havocProcedure.addModifiedGlobalVariables(oldFieldName);
                        break;
                    }
                }
            }
            else{
                havocProcedure.addStatement("    "+oldFieldName+" := "+
                   fieldName +";\n");
                havocProcedure.addModifiedGlobalVariables(oldFieldName);
            }
        }
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
    if(options.ultimateAutomizer){
        parserName = "_parser_" + parserName;
    }
    BoogieProcedure parser = BoogieProcedure(parserName);
    currentProcedure = &parser;
    parser.addDeclaration("\n// Parser "+parserName+"\n");
    parser.addDeclaration("procedure {:inline 1} "+parserName+"()\n");
    incIndent();
    cstring localDecl = "";
    cstring localDeclArg = "";
    int cnt = p4Parser->parserLocals.size();
    for(auto parserLocal:p4Parser->parserLocals){
        cnt--;
        parser.addStatement(translate(parserLocal));
        // if (auto declVar = parserLocal->to<IR::Declaration_Variable>()) {
        //     cstring name = translate(declVar->name);
        //     cstring type = translate(declVar->type);
        //     if(options.gotoOrIf)
        //         currentProcedure->addVariableDeclaration(getIndent()+"var "+name+":"+type+";\n");
        //     // addGlobalVariables(name);
        //     localDecl += name+":"+type;
        //     localDeclArg += translate(declVar->name);
        // }
        // if(cnt > 0){
        //     localDecl += ", ";
        //     localDeclArg += ", ";
        // }
    }

    if(options.gotoOrIf){
        parser.addStatement(getIndent()+"goto State$start;\n");
        parser.addStatement("\n"+getIndent()+"State$accept:\n");
        parser.addStatement(getIndent()+"call accept();\n");
        parser.addStatement(getIndent()+"goto Exit;\n");

        parser.addStatement("\n"+getIndent()+"State$reject:\n");
        parser.addStatement(getIndent()+"call reject();\n");
        parser.addStatement(getIndent()+"goto Exit;\n");

        parser.addStatement("\n"+getIndent()+"Exit:\n");

        addProcedure(parser);
        for(auto state:p4Parser->states){
            translate(state);
            // translate(state, localDecl, localDeclArg);
        }
        decIndent();
    }
    else{
        // parser.addStatement("    call start("+localDeclArg+");\n");
        parser.addStatement("    call start();\n");
        parser.addSucc("start");
        addPred("start", parserName);


        parser.addSucc("accept");
        addPred("accept", parserName);

        parser.addSucc("reject");
        addPred("reject", parserName);
        decIndent();
        addProcedure(parser);
        for(auto state:p4Parser->states){
            translate(state);
            // translate(state, localDecl, localDeclArg);
        }
    }
    // TODO: parser local variables
}

void Translator::translate(const IR::ParserState *parserState, cstring localDecl, cstring localDeclArg){
    if(options.gotoOrIf){
        cstring stateName = parserState->name.toString();
        cstring stateLabel = getIndent(); stateLabel += "    State$"; stateLabel += stateName;
        if(stateName=="accept" || stateName=="reject")
            return;
        // BoogieProcedure state = BoogieProcedure(stateName);
        // state.isParserState = true;
        // currentProcedure = &state;
        // state.addDeclaration("\n//Parser State "+stateName+"\n");
        // state.addDeclaration("procedure {:inline 1} "+stateName+"("+localDecl+")\n");
        // incIndent();
        // currentProcedure->addStatement(stateLabel+":\n");
        currentProcedure->addStatement("\n"+stateLabel+":\n");
        for(auto statOrDecl:parserState->components){
            currentProcedure->addStatement(translate(statOrDecl));
        }
        if(parserState->selectExpression!=nullptr){
            if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
                cstring nextState = translate(pathExpression);
                cstring nextStateLabel = "State$"+nextState;
                currentProcedure->addStatement(getIndent()+"goto "+nextStateLabel+";\n");
                // currentProcedure->addSucc(nextS)
                // state.addStatement(getIndent()+"call "+nextState+"("+localDeclArg+");\n");
                // state.addSucc(nextState);
                // addPred(nextState, stateName);
            }
            else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
                currentProcedure->addStatement(translate(selectExpression, stateName, localDeclArg));
            }
        }
        // TODO: add succ
        // decIndent();
        // addProcedure(state);
    }
    else{
        cstring stateName = parserState->name.toString();
        BoogieProcedure state = BoogieProcedure(stateName);
        state.isParserState = true;
        currentProcedure = &state;
        state.addDeclaration("\n//Parser State "+stateName+"\n");
        state.addDeclaration("procedure {:inline 1} "+stateName+"()\n");
        incIndent();
        for(auto statOrDecl:parserState->components){
            currentProcedure->addStatement(translate(statOrDecl));
        }
        if(parserState->selectExpression!=nullptr){
            if (auto pathExpression = parserState->selectExpression->to<IR::PathExpression>()){
                cstring nextState = translate(pathExpression);
                // state.addStatement(getIndent()+"call "+nextState+"("+localDeclArg+");\n");
                state.addStatement(getIndent()+"call "+nextState+"();\n");
                state.addSucc(nextState);
                addPred(nextState, stateName);
            }
            else if(auto selectExpression = parserState->selectExpression->to<IR::SelectExpression>()){
                currentProcedure->addStatement(translate(selectExpression, stateName, localDeclArg));
            }
        }
        decIndent();
        addProcedure(state);
    }
}

void Translator::translate(const IR::P4Control *p4Control){
    cstring controlName = p4Control->name.toString();
    BoogieProcedure control = BoogieProcedure(controlName);
    control.setImplemented();
    addProcedure(control);

    std::vector<cstring> declarations;
    for(auto declaration:*p4Control->getDeclarations()){
        if(declaration->to<IR::Declaration_Instance>())
            declarations.push_back(translate(declaration->getName()));
        // std::cout << "**declaration: " << translate(declaration->getName()) << std::endl;
    }
    currentProcedure = &procedures[controlName];

    for(auto controlLocal:p4Control->controlLocals){
        currentProcedure = &procedures[controlName];
        if(auto instance = controlLocal->to<IR::Declaration_Instance>()){
            cstring instanceName = instance->getName().toString();
            cstring renamedInstance = "";
            for(cstring declaration:declarations){
                if(declaration.find(instanceName)!=nullptr 
                    && declaration.size()>renamedInstance.size()){
                    int idx = instanceName.size()+1;
                    bool digit = true;
                    for(int i = idx; i < declaration.size(); i++){
                        if(!(declaration[i] >= '0' && declaration[i] <= '9')){
                            digit = false;
                        }   
                    }
                    if(digit)
                        renamedInstance = declaration;
                }
            }
            translate(instance, renamedInstance);
        }
        else{
            // can be declared as global variables
            // p4c has finished renaming
            translate(controlLocal);
        }
    }

    currentProcedure = &procedures[controlName];
    currentProcedure->addDeclaration("\n// Control "+controlName+"\n");
    currentProcedure->addDeclaration("procedure {:inline 1} "+controlName+"()\n");
    incIndent();
    for(auto statOrDecl:p4Control->body->components){
        currentProcedure->addStatement(translate(statOrDecl));
    }
    decIndent();
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

    // add table entry
    // BoogieProcedure tableEntry = BoogieProcedure(tableName+"_table_entry");
    // tableEntry.addDeclaration("\n// Table Entry "+tableName+"_table_entry"+"\n");
    // tableEntry.addDeclaration("procedure "+tableName+"_table_entry"+"();\n");
    // addProcedure(tableEntry);

    // add table exit
    // BoogieProcedure tableExit = BoogieProcedure(tableName+"_table_exit");
    // tableExit.addDeclaration("\n// Table Exit "+tableName+"_table_exit"+"\n");
    // tableExit.addDeclaration("procedure "+tableName+"_table_exit();\n");
    // addProcedure(tableExit);


    BoogieProcedure table = BoogieProcedure(tableName);
    table.addDeclaration("\n// Table "+name+"\n");
    table.addDeclaration("procedure {:inline 1} "+tableName+"()\n");
    table.setImplemented();
    addDeclaration("\n// Table "+name+" Actionlist Declaration\n");
    addDeclaration("type "+name+".action;\n");
    incIndent();
    // Consider keys
    // Keys are not changed and this is only for key access validity checking
    if(!options.ultimateAutomizer){
        for(auto property:p4Table->properties->properties){
            if (auto key = property->value->to<IR::Key>()) {
                for(auto keyElement:key->keyElements){
                    cstring expr = translate(keyElement->expression);
                    if(expr!=nullptr && expr.find("[")==nullptr && expr.find("(")==nullptr) {
                        std::string stmt(getIndent());
                        stmt += expr;
                        stmt += " := ";
                        stmt += expr;
                        stmt += ";\n";
                        table.addStatement(stmt);
                        table.addModifiedGlobalVariables(expr);
                        std::cout << expr << std::endl;
                    }
                }
            }
        }
    }


    // table.addStatement("\n    call "+tableName+"_table_entry"+"();\n");


    // std::cout << tableName << std::endl;
    cstring gotoStmt = getIndent()+"goto ";

    for(auto property:p4Table->properties->properties){
        if (auto actionList = property->value->to<IR::ActionList>()) {
            // add local variables
            for(auto actionElement:actionList->actionList){
                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                    cstring actionName = translate(actionCallExpr->method);
                    const IR::P4Action* action = actions[actionName];
                    for(auto parameter:action->parameters->parameters){
                        if(options.ultimateAutomizer && options.bitBlasting &&
                            parameter->type->to<IR::Type_Bits>()){
                            auto typeBits = parameter->type->to<IR::Type_Bits>();
                            cstring parameterName = actionName+"."+translate(parameter->name);
                            for(int i = 0; i < typeBits->size; i++){
                                table.addFrontStatement("    var "+connect(parameterName, i)+":bool;\n");
                            }
                        }
                        else
                            table.addFrontStatement("    var "+actionName+"."+translate(parameter)+";\n");
                    }
                }
            }

            // no table rules
            if(bMV2CmdsAnalyzer== nullptr || !bMV2CmdsAnalyzer->hasTableAddCmds(name)){
                int cnt = actionList->actionList.size();

                // goto statement
                if(options.gotoOrIf){
                    bool firstAction = true;
                    for(auto actionElement:actionList->actionList){
                        if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                            // NoAction should not be considered
                            cnt--;
                            if(cnt == 0)
                                break;

                            cstring actionName = translate(actionCallExpr->method);
                            if(!firstAction) gotoStmt += ", ";
                            else firstAction = false;
                            gotoStmt += "action_"; gotoStmt += actionName;
                        }
                    }
                    gotoStmt += ";\n";
                    table.addStatement(gotoStmt);
                }

                cnt = actionList->actionList.size();
                bool firstAction = true;
                for(auto actionElement:actionList->actionList){
                    // if(actionList->actionList.size()!=1){
                    //     table.addStatement(getIndent()+"assume(");
                    // }
                    
                    // NoAction should not be considered
                    cnt--;
                    if(cnt == 0)
                        break;
                    if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                        cstring actionName = translate(actionCallExpr->method);

                        std::string label("\n"+getIndent());
                        label += "action_"; label += actionName; label += ":\n";
                        if(options.gotoOrIf){
                            table.addStatement(label);
                        }

                        if(actionList->actionList.size()!=1){
                            // table.addStatement(getIndent()+"assume("+name+".action_run == "+name+".action."
                                // +actionName+");\n");
                        }

                        if(options.gotoOrIf){
                            table.addStatement(getIndent()+"assume "+name+".action_run == "+
                                name+".action."+actionName+";\n");
                            table.addModifiedGlobalVariables(name+".action_run");
                        }
                        else{
                            if(firstAction){
                                table.addStatement(getIndent()+"if("+name+".action_run == "+
                                    name+".action."+actionName+"){\n");
                                firstAction = false;
                            }
                            else{
                                table.addStatement(getIndent()+"else if("+name+".action_run == "+
                                    name+".action."+actionName+"){\n");
                            }
                            incIndent();
                        }
                        
                        const IR::P4Action* action = actions[actionName];
                        table.addStatement(getIndent()+"call "+actionName+"(");
                        table.addSucc(actionName);
                        addPred(actionName, tableName);
                        int cnt2 = action->parameters->parameters.size();
                        for(auto parameter:action->parameters->parameters){
                            cnt2--;
                            if(options.ultimateAutomizer && options.bitBlasting && 
                                parameter->type->to<IR::Type_Bits>()){
                                auto typeBits = parameter->type->to<IR::Type_Bits>();
                                cstring stmt = "";
                                for(int i = 0; i < typeBits->size; i++){
                                    stmt += connect(actionName+"."+translate(parameter->name), i);
                                    if(i < typeBits->size-1) stmt += ", ";
                                }
                                table.addStatement(stmt);
                            }
                            else
                                table.addStatement(actionName+"."+translate(parameter->name));
                            if(cnt2 != 0)
                                table.addStatement(", ");
                        }
                        table.addStatement(");\n");
                        if(options.gotoOrIf){
                            table.addStatement(getIndent()+"goto Exit;\n");
                        }
                        else{
                            decIndent();
                            table.addStatement(getIndent()+"}\n");
                        }
                        // decIndent();
                    }
                }
                // add action declaration
                translate(actionList, name+".action");
            }
            /* handle table add commands, i.e., table rules
                1. find the rules of the current table (from BMV2CmdsAnalyzer)
                2. add condition statements (according to keys and priority)
                3. assign parameters
                4. call the corresponding actions
                5. if no matching rules, consider the default action
            */
            else{
                std::vector<TableAdd*> rules = bMV2CmdsAnalyzer->getTableAddCmds(name);
            }
        }
    }

    if(options.gotoOrIf){
        // table.addStatement("\n    Exit:\n");
        // table.addStatement("        call "+tableName+"_table_exit();\n");
    }

    addDeclaration("var "+name+".action_run : "+name+".action;\n");
    addGlobalVariables(name+".action_run");
    addDeclaration("var "+name+".hit : bool;\n");
    decIndent();
    addProcedure(table);
}

// void Translator::translate(const IR::P4Table *p4Table){
//     cstring name = translate(p4Table->name);
//     cstring tableName = name+".apply";
//     BoogieProcedure table = BoogieProcedure(tableName);
//     table.addDeclaration("\n// Table "+name+"\n");
//     table.addDeclaration("procedure {:inline 1} "+tableName+"()\n");
//     addDeclaration("\n// Table "+name+" Actionlist Declaration\n");
//     addDeclaration("type "+name+".action;\n");
//     incIndent();
//     for(auto property:p4Table->properties->properties){
//         if (auto key = property->value->to<IR::Key>()) {
//             for(auto keyElement:key->keyElements){
//                 cstring expr = translate(keyElement->expression);
//                 if(expr!=nullptr && expr.find("[")==nullptr && expr.find("(")==nullptr) {
//                     std::string stmt(getIndent());
//                     stmt += expr;
//                     stmt += " := ";
//                     stmt += expr;
//                     stmt += ";\n";
//                     table.addStatement(stmt);
//                     table.addModifiedGlobalVariables(expr);
//                 }
//             }
//         }
//     }
//     // std::cout << tableName << std::endl;
//     for(auto property:p4Table->properties->properties){
//         if (auto actionList = property->value->to<IR::ActionList>()) {
//             // add local variables
//             for(auto actionElement:actionList->actionList){
//                 if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
//                     cstring actionName = translate(actionCallExpr->method);
//                     const IR::P4Action* action = actions[actionName];
//                     for(auto parameter:action->parameters->parameters){
//                         table.addFrontStatement("    var "+actionName+"."+translate(parameter)+";\n");
//                     }
//                 }
//             }
//             // add action call statements
//             int cnt = actionList->actionList.size();
//             for(auto actionElement:actionList->actionList){
//                 if(actionList->actionList.size()!=1){
//                     if(cnt == actionList->actionList.size())
//                         table.addStatement(getIndent()+"if(");
//                     else
//                         table.addStatement(getIndent()+"else if(");
//                 }
//                 cnt--;
//                 // if(cnt == 0)
//                 //     break;
//                 if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
//                     cstring actionName = translate(actionCallExpr->method);
//                     if(actionList->actionList.size()!=1){
//                         table.addStatement(name+".action_run == "+name+".action."+actionName+"){\n");
//                         incIndent();
//                     }
//                     const IR::P4Action* action = actions[actionName];
//                     table.addStatement(getIndent()+"call "+actionName+"(");
//                     table.addSucc(actionName);
//                     addPred(actionName, tableName);
//                     int cnt2 = action->parameters->parameters.size();
//                     for(auto parameter:action->parameters->parameters){
//                         cnt2--;
//                         table.addStatement(actionName+"."+translate(parameter->name));
//                         if(cnt2 != 0)
//                             table.addStatement(", ");
//                     }
//                     table.addStatement(");\n");
//                     decIndent();
//                     if(actionList->actionList.size()!=1){
//                         table.addStatement(getIndent()+"}\n");
//                     }
//                 }
//                 // if(actionList->actionList.size()!=2)     
//             }
//             // add action declaration
//             translate(actionList, name+".action");
//         }
//     }
//     addDeclaration("var "+name+".action_run : "+name+".action;\n");
//     addGlobalVariables(name+".action_run");
//     addDeclaration("var "+name+".hit : bool;\n");
//     decIndent();
//     addProcedure(table);
// }

/*
    translate action_run (discarded)
*/
cstring Translator::translate(const IR::P4Table *p4Table, std::map<cstring, cstring> switchCases){
    cstring res = "";
    cstring name = translate(p4Table->name);
    for(auto property:p4Table->properties->properties){
        if (auto key = property->value->to<IR::Key>()) {
            for(auto keyElement:key->keyElements){
                cstring expr = translate(keyElement->expression);
                if(expr.find("[")==nullptr&&expr.find("(")==nullptr) {
                    res += getIndent()+expr+" := "+expr+";\n";
                    updateModifiedVariables(expr);
                }
            }
        }
    }
    for(auto property:p4Table->properties->properties){
        if (auto actionList = property->value->to<IR::ActionList>()) {
            // add local variables
            for(auto actionElement:actionList->actionList){
                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                    cstring actionName = translate(actionCallExpr->method);
                    const IR::P4Action* action = actions[actionName];
                    for(auto parameter:action->parameters->parameters){
                        currentProcedure->addFrontStatement("    var "+actionName+"."+translate(parameter)+";\n");
                    }
                }
            }
            // TODO: add keys
            // add action call statements
            int cnt = actionList->actionList.size();
            for(auto actionElement:actionList->actionList){
                if(actionList->actionList.size()!=2){
                    if(cnt == actionList->actionList.size())
                        res += getIndent()+"if(";
                    else if(cnt != 1)
                        res += getIndent()+"else if(";
                }
                cnt--;
                if(cnt == 0)
                    break;
                if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
                    cstring actionName = translate(actionCallExpr->method);
                    if(actionList->actionList.size()!=2)
                        res += name+".action_run == "+name+".action."+actionName+"){\n";
                    incIndent();
                    const IR::P4Action* action = actions[actionName];
                    if(switchCases[name+".action."+actionName] != nullptr)
                        res += switchCases[name+".action."+actionName];
                    // std::cout << name+".action."+actionName << std::endl;
                    // std::cout << switchCases[name+".action."+actionName] << std::endl;
                    // res += switchCases[name+".action."+actionName];
                    res += getIndent()+"call "+actionName+"(";
                    currentProcedure->addSucc(actionName);
                    addPred(actionName, currentProcedure->getName());
                    int cnt2 = action->parameters->parameters.size();
                    for(auto parameter:action->parameters->parameters){
                        cnt2--;
                        res += actionName+"."+translate(parameter->name);
                        if(cnt2 != 0)
                            res += ", ";
                    }
                    res += ");\n";
                    decIndent();
                }
                if(actionList->actionList.size()!=2)
                    res += getIndent()+"}\n";
            }
        }
    }
    // decIndent();
    return res;
}

cstring Translator::translate(const IR::Parameter *parameter, cstring arg){
    cstring name = translate(parameter->name);
    cstring type = translate(parameter->type);
    if(arg == "action"){
        if(auto typeBits = parameter->type->to<IR::Type_Bits>()){
            updateMaxBitvectorSize(typeBits);
            currentProcedure->parameters[name] = typeBits->size;
            if(options.ultimateAutomizer && options.bitBlasting){
                cstring res = "";
                for(int i = 0; i < typeBits->size; i++){
                    res += connect(name, i)+":bool";
                    if(i < typeBits->size-1) res += ", ";
                }
                return res;
            }
        }
        else if(auto typeName = parameter->type->to<IR::Type_Name>()){
            cstring _name = translate(typeName);
            if(typeDefs.find(_name) != typeDefs.end()){
                currentProcedure->parameters[name] = typeDefs[_name];
            }
        }
    }
    if(options.ultimateAutomizer && parameter->type->to<IR::Type_Bits>())
        type = "int";
    return name+":"+type;
}

void Translator::translate(const IR::ActionList *actionList, cstring arg){
    cstring limitName = arg+"_run.limit";
    BoogieProcedure limit = BoogieProcedure(limitName);
    limit.addModifiedGlobalVariables(arg+"_run");
    limit.addDeclaration("\nprocedure "+limitName+"();\n");
    limit.addDeclaration("    ensures(");
    int cnt = actionList->actionList.size();
    if(cnt == 0 || cnt == 1) limit.addDeclaration("true");
    for(auto actionElement:actionList->actionList){
        cnt--;
        // NoAction should not be considered
        if(cnt == 0) break;
        if(auto actionCallExpr = actionElement->expression->to<IR::MethodCallExpression>()){
            cstring actionName = translate(actionCallExpr->method);
            addDeclaration("const unique "+arg+"."+actionName+" : "+arg+";\n");
            limit.addDeclaration(arg+"_run=="+arg+"."+actionName);
        }
        // NoAction should not be considered
        if(cnt > 1){
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