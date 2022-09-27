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
	modifies.insert(variable);
}

void BoogieProcedure::addLocalVariables(cstring variable){
	localVariables.insert(variable);
}

bool BoogieProcedure::hasLocalVariables(cstring variable){
	return localVariables.find(variable) != localVariables.end();
}

void BoogieProcedure::addFrontStatement(const cstring &cont){
	addFrontStatement(BoogieStatement(cont));
}

void BoogieProcedure::addFrontStatement(BoogieStatement statement){
	statements.insert(statements.begin(), statement);
}

int BoogieProcedure::findStatement(const cstring &cont){
	int offset = 0;
	for(BoogieStatement statement:statements){
		if(statement.toString().find(cont) != nullptr)
			return offset;
		offset += 1;
	}
	return -1;
}

void BoogieProcedure::insertStatement(int offset, const cstring &cont){
	insertStatement(offset, BoogieStatement(cont));
}

void BoogieProcedure::insertStatement(int offset, BoogieStatement statement){
	if(offset != -1){
		statements.insert(statements.begin()+offset, statement);
	}
}

void BoogieProcedure::addVariableDeclaration(const cstring &cont){
	addVariableDeclaration(BoogieStatement(cont));
}

void BoogieProcedure::addVariableDeclaration(BoogieStatement statement){
	variableDeclaration.push_back(statement);
}

void BoogieProcedure::addStatement(const cstring &cont){
	this->hasImplementation = true;
	if(addAssertions){
		if(lastStatement().find("assert(") != nullptr){
			if(cont.find("call packet_in.extract") != nullptr){
				statements.pop_back();
			}
		}
	}
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

int BoogieProcedure::getModifiesSize(){
	return modifies.size();
}

cstring BoogieProcedure::lastStatement(){
	if(statements.empty())
		return "";
	return statements.back().toString();
}

void BoogieProcedure::removeLastStatement(){
	statements.pop_back();
}

cstring BoogieProcedure::toString(){
	cstring res = declaration;
	if(!modifies.empty()){
		res += "	modifies ";
		int cnt = modifies.size();
		std::set<cstring>::iterator iter;
		for (iter=modifies.begin(); iter!=modifies.end(); iter++){
	        res += *iter;
	        cnt--;
	        if(cnt != 0){
				res += ", ";
			}
	    }
		// for(cstring variable:modifies){
		// 	res += variable;
		// 	cnt--;
		// 	if(cnt != 0){
		// 		res += ", ";
		// 	}
		// }
		res += ";\n";
	}
	
	if(hasImplementation){
		res += "{\n";
		if(!variableDeclaration.empty()){
			for(BoogieStatement statement:variableDeclaration){
				res += statement.toString();
			}
		}
		if(!statements.empty()){
			for(BoogieStatement statement:statements){
				res += statement.toString();
			}
		}
		res += "}\n";
	}
	return res;
}

cstring BoogieProcedure::getName(){
	return name;
}