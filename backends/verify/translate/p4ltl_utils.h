#ifndef BACKENDS_VERIFY_TRANSLATEP4LTL_P4LTL_UTILS_H_ 
#define BACKENDS_VERIFY_TRANSLATEP4LTL_P4LTL_UTILS_H_

#include <vector>
#include <map>
#include <set>
#include "frontends/parsers/p4ltl/p4ltlast.hpp"
#include "backends/verify/translate/translate.h"
#include "backends/verify/translate/utils.h"

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

const std::vector<cstring> P4LTL_KEYS = {"//#LTLVariables:", "//#LTLProperty:", "//#LTLFairness:", 
										"//#CPI:", "//#CPI_MODEL:", "//#CPI_SPEC:"};
const cstring P4LTL_KEYS_VAR = "//#LTLVariables:";
const cstring P4LTL_KEYS_SPEC = "//#LTLProperty:";
const cstring P4LTL_KEYS_FAIR = "//#LTLFairness:";
const cstring P4LTL_KEYS_CPI = "//#CPI:";
const cstring P4LTL_KEYS_CPI_MODEL = "//#CPI_MODEL:";
const cstring P4LTL_KEYS_CPI_SPEC = "//#CPI_SPEC:";

// bool isAPNode(P4LTL::AstNode* node);
// std::vector<P4LTL::AstNode*> getAllNodes(P4LTL::AstNode* root);
// std::vector<P4LTL::AstNode*> getAllAPs(P4LTL::AstNode* root);

class Translator;

class CPIRule{
private:
	cstring table;
	std::map<cstring, cstring> keys;
	cstring action;
public:
	std::vector<cstring> params;
	CPIRule(){
		table = "";
		action = "";
	}
	void setTable(cstring _table){
		table = _table;
	}
	void addKey(cstring key, cstring value){
		keys[key] = value;
	}
	void addParam(cstring param){
		params.push_back(param);
	}
	void setAction(cstring _action){
		action = _action;
	}
	cstring getTable(){ return table; }
	cstring getAction(){ return action; }
	std::map<cstring, cstring> getKeys(){ return keys; }
	std::vector<cstring> getParams(){ return params; }
	void show(){
		std::cout << "table: " << table << std::endl;
		std::cout << "action: " << action << std::endl;
		for(auto item : keys){
			std::cout << "match: " << item.first << item.second << std::endl;
		}
		for(auto item : params){
			std::cout << "param: " << item << std::endl;
		}
		std::cout << std::endl;
	}
};

class P4LTLTranslator{
	Translator* p4Translator;
	std::vector<cstring> vars;
	std::vector<cstring> stmts;
	std::vector<cstring> declarations;
	std::map<cstring, cstring> freeVars;
	std::map<cstring, int> sizes;

	std::map<cstring, cstring> cache;

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

	void getAllNodes(std::vector<P4LTL::AstNode*>& nodes, P4LTL::AstNode* root);
	std::vector<P4LTL::AstNode*> getAllNodes(P4LTL::AstNode* root);

	std::set<cstring> getOldExprs(P4LTL::AstNode* root);
	std::map<cstring, std::set<cstring>> getOldArrays(P4LTL::AstNode* root);

	bool isActionApplied(P4LTL::AstNode* root, cstring action);

	int getSize(cstring variable);

	bool isBvType(cstring type);
	int getBvLength(cstring type);

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

	bool alreadyDeclared(cstring expr);
	cstring getCacheVariable(cstring expr);

	CPIRule* analyzeRule(P4LTL::AstNode* root);
};
#endif