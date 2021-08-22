#ifndef BACKENDS_VERIFY_TRANSLATE_BOOGIE_PROCEDURE_H_
#define BACKENDS_VERIFY_TRANSLATE_BOOGIE_PROCEDURE_H_

#include "boogie_statement.h"
#include <vector>
#include <set>
#include <map>

class BoogieProcedure{
	cstring name;
	cstring declaration;
	cstring body;
	
	std::vector<BoogieStatement> statements;
	std::vector<BoogieStatement> variableDeclaration;
	bool hasImplementation = false;
	bool addAssertions = false;
public:
	std::set<cstring> modifies;
	std::map<cstring, int> parameters;  // <name, size>
	std::vector<cstring> succ;
	bool isParserState = false;
	BoogieProcedure();
	BoogieProcedure(const cstring& name);
	BoogieProcedure(cstring& name, cstring& decl, cstring& body);
	void addDeclaration();
	void addModifiedGlobalVariables(cstring variable);
	void addFrontStatement(const cstring &cont);
	void addFrontStatement(BoogieStatement statement);
	int findStatement(const cstring &cont);
	void insertStatement(int offset, BoogieStatement statement);
	void insertStatement(int offset, const cstring &cont);
	void addStatement(const cstring &cont);
	void addStatement(BoogieStatement statement);
	void addVariableDeclaration(const cstring &cont);
	void addVariableDeclaration(BoogieStatement statement);
	void addImplementation(const cstring& body);
	void addDeclaration(const cstring& declaration);
	void removeLastStatement();
	void setImplemented();
	void addSucc(cstring name);
	int getModifiesSize();
	cstring getName();
	cstring toString();
	cstring lastStatement();
};

#endif