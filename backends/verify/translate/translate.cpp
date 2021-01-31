#include "translate.h"

Translator::Translator(std::ostream &out) : out(out){
    // init main procedure
    cstring mainProcedureDeclaration;
    mainProcedure = BoogieProcedure("mainProcedure");
    mainProcedure.addStatement("    call clear_forward();\n");
    mainProcedure.addStatement("    call clear_drop();\n");
    mainProcedure.addStatement("    call clear_valid();\n");
    mainProcedure.addStatement("    call clear_emit();\n");
    mainProcedure.addStatement("    call init.stack.index();\n");
    mainProcedure.setImplemented();

    procedures = std::vector<BoogieProcedure>();

    // declare necessary types and files
    declaration = cstring("type Ref;\n");
    declaration += "var Heap:HeapType;\n";
    declaration += "type HeaderStack = [int]Ref;\n";
    declaration += "var last:[HeaderStack]Ref;\n";

    declaration += "var forward:bool;\n";

    headers = std::map<cstring, const IR::Type_Header*>();
    structs = std::map<cstring, const IR::Type_Struct*>();
    declared = std::set<cstring>();

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
    initStackIndex.addModifiedGlobalVariables("stack.index;");
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
}

void Translator::addProcedure(BoogieProcedure procedure){
    procedures.push_back(procedure);
}

void Translator::addDeclaration(cstring decl){
    declaration += decl;
}

void Translator::analyzeProgram(const IR::P4Program *program){
    for(auto obj:program->objects){
        if (auto typeHeader = obj->to<IR::Type_Header>()) {
            headers[typeHeader->name.toString()] = typeHeader;
        }
        else if (auto typeStruct = obj->to<IR::Type_Struct>()) {
            structs[typeStruct->name.toString()] = typeStruct;
        }
    }
}

void Translator::writeToFile(){
    out << declaration;
    out << "\n";
    out << mainProcedure.toString();
    for(BoogieProcedure procedure:procedures){
        out << "\n";
        out << procedure.toString();
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
    else{
        std::cout << node->node_type_name() << std::endl;
        // translate(obj);
    }
}

void Translator::translate(const IR::Node *node, cstring arg){
    std::cout << node->node_type_name() << std::endl;
}

void Translator::translate(const IR::P4Program *program){
    analyzeProgram(program);
    std::cout << "translate P4Program" << std::endl;
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

void Translator::translate(const IR::Type_Struct *typeStruct){
    std::cout << "translate Struct " << typeStruct->name << std::endl;
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
    std::cout << "translate Struct " << typeStruct->name << std::endl;
    for(const IR::StructField* field:typeStruct->fields){
        translate(field, arg);
    }
}

void Translator::translate(const IR::StructField *field){
    std::cout << "translate StructField" << std::endl;
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
    }
    else if(field->type->node_type_name() == "Type_Stack"){

    }
}

void Translator::translate(const IR::Type_Header *typeHeader){
    // for(const IR::StructField* field:typeHeader->fields){
    //     translate(field);
    // }
    std::cout << "translate typeHeader" << std::endl;
}

void Translator::translate(const IR::Type_Header *typeHeader, cstring arg){
    addDeclaration("\n// Header "+typeHeader->name.toString()+"\n");
    addDeclaration("var "+arg+":Ref;\n");
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
    // std::cout << "translate p4Parser" << std::endl;
}

void Translator::translate(const IR::P4Control *p4Control){
    // std::cout << "translate p4Control" << std::endl;
}

void Translator::translate(const IR::Method *method){
    // std::cout << "translate method" << std::endl;
}