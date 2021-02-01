#include "boogie_procedure.h"

BoogieProcedure::BoogieProcedure(){
	name = cstring("");
	declaration = cstring("");
	body = cstring("");
}

BoogieProcedure::BoogieProcedure(const cstring& name){
	this->name = name;
	declaration = cstring("");
	body = cstring("");
}

BoogieProcedure::BoogieProcedure(cstring& name, cstring& decl, cstring& body){
	this->name = name;
	this->declaration = declaration;
	this->body = body;
}

void BoogieProcedure::addModifiedGlobalVariables(cstring variable){
	modifies.push_back(variable);
}

void BoogieProcedure::addFrontStatement(BoogieStatement statement){
	statements.insert(statements.begin(), statement);
}

void BoogieProcedure::addStatement(const cstring &cont){
	this->hasImplementation = true;
	addStatement(BoogieStatement(cont));
}

void BoogieProcedure::addStatement(BoogieStatement statement){
	this->hasImplementation = true;
	statements.push_back(statement);
}

void BoogieProcedure::addImplementation(const cstring& body){
	this->hasImplementation = true;
	this->body += body;
}

void BoogieProcedure::addDeclaration(const cstring& declaration){
	this->declaration += declaration;
}

void BoogieProcedure::setImplemented(){
	this->hasImplementation = true;
}

void BoogieProcedure::addSucc(cstring name){
	succ.push_back(name);
}

cstring BoogieProcedure::toString(){
	cstring res = declaration;
	if(!modifies.empty()){
		res += "	modifies ";
		int cnt = modifies.size();
		for(cstring variable:modifies){
			res += variable;
			cnt--;
			if(cnt != 0){
				res += ", ";
			}
		}
		res += ";\n";
	}
	if(hasImplementation){
		res += "{\n";
		if(!statements.empty()){
			for(BoogieStatement statement:statements){
				res += statement.toString();
			}
		}
		res += "}\n";
	}
	return res;
}