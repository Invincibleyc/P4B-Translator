#ifndef BACKENDS_VERIFY_TRANSLATE_BOOGIE_PROCEDURE_H_
#define BACKENDS_VERIFY_TRANSLATE_BOOGIE_PROCEDURE_H_

#include "lib/cstring.h"
#include "boogie_statement.h"
#include <vector>

class BoogieProcedure{
	cstring name;
	cstring declaration;
	cstring body;
	
	std::vector<BoogieStatement> statements;
	bool hasImplementation = false;
public:
	std::set<cstring> modifies;
	std::vector<cstring> succ;
	BoogieProcedure();
	BoogieProcedure(const cstring& name);
	BoogieProcedure(cstring& name, cstring& decl, cstring& body);
	void addDeclaration();
	void addModifiedGlobalVariables(cstring variable);
	void addFrontStatement(const cstring &cont);
	void addFrontStatement(BoogieStatement statement);
	void addStatement(const cstring &cont);
	void addStatement(BoogieStatement statement);
	void addImplementation(const cstring& body);
	void addDeclaration(const cstring& declaration);
	void setImplemented();
	void addSucc(cstring name);
	int getModifiesSize();
	cstring getName();
	cstring toString();
};

#endif