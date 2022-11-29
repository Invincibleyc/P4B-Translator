#ifndef BACKENDS_VERIFY_TRANSLATEP4LTL_P4LTL_UTILS_H_ 
#define BACKENDS_VERIFY_TRANSLATEP4LTL_P4LTL_UTILS_H_

#include <vector>
#include <map>
#include "frontends/parsers/p4ltl/p4ltlast.hpp"
#include "backends/verify/translate/translate.h"

/*
	## AST Node Types ##
	
	BinOpNode
	- BinaryTemporalOperator
	- ExtendedComparativeOperator
	- BinaryPredicateOperator
	- BinaryTermOperator

	UOpNode
	- UnaryTemporalOperator
	- UnaryPredicateOperator

	P4LTLAtomicProposition

	Predicate
	- Drop
	- Forward
	- Valid
	- Apply

	IntLiteral

	BooleanLiteral

	Name
	- OldExpression

	Key

	ArrayAccessExprssion
*/

const std::vector<cstring> P4LTL_KEYS = {"//#LTLVariables:", "//#LTLProperty:", "//#LTLFairness:"};

bool isAPNode(P4LTL::AstNode* node);
void getAllNodes(std::vector<P4LTL::AstNode*>& nodes, P4LTL::AstNode* root);
std::vector<P4LTL::AstNode*> getAllNodes(P4LTL::AstNode* root);
std::vector<P4LTL::AstNode*> getAllAPs(P4LTL::AstNode* root);

class Translator;

class P4LTLTranslator{
	Translator* p4Translator;
	std::vector<cstring> vars;
	std::vector<cstring> stmts;
	std::vector<cstring> declarations;
	std::map<cstring, cstring> freeVars;
	std::map<cstring, int> sizes;

public:
	P4LTLTranslator(){
		p4Translator = nullptr;
	}
	P4LTLTranslator(Translator* translator){
		p4Translator = translator;
	}
	cstring translateP4LTL(P4LTL::AstNode* node);
	cstring translateP4LTL(P4LTL::BinOpNode* node);
	cstring translateP4LTL(P4LTL::UOpNode* node);
	cstring translateP4LTL(P4LTL::P4LTLAtomicProposition* node);
	cstring translateP4LTL(P4LTL::Predicate* node);
	cstring translateP4LTL(P4LTL::IntLiteral* node);
	cstring translateP4LTL(P4LTL::BooleanLiteral* node);
	cstring translateP4LTL(P4LTL::Name* node);
	cstring translateP4LTL(P4LTL::Key* node);
	cstring translateP4LTL(P4LTL::ArrayAccessExprssion* node);

	int getSize(cstring variable);

	std::map<cstring, cstring> getFreeVariables();
	void addFreeVariable(cstring variable);
	void createFreeVariables(cstring decl);
	bool isFreeVariable(cstring variable);
	
	std::vector<cstring> getVariables();
	void addVariable(cstring stmt);

	std::vector<cstring> getStatements();
	void addStatement(cstring stmt);

	std::vector<cstring> getDeclarations();
	void addDeclaration(cstring declaration);

};

#endif