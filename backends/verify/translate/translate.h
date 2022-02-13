#ifndef BACKENDS_VERIFY_TRANSLATE_TRANSLATE_H_
#define BACKENDS_VERIFY_TRANSLATE_TRANSLATE_H_

#include <typeinfo>
#include <fstream>
#include <map>
#include <queue>
#include "ir/ir.h"
#include "boogie_procedure.h"
#include "boogie_statement.h"
#include "bmv2.h"
#include "backends/verify/translate/options.h"


class Translator{
private:
	BoogieProcedure mainProcedure;
	// std::vector<BoogieProcedure> procedures;
	std::map<cstring, BoogieProcedure> procedures;
	cstring declaration;
	cstring code;
	std::ostream& out;
	int indent = 0;
	std::map<cstring, const IR::Type_Header*> headers;
	std::map<cstring, const IR::Type_Struct*> structs;
	std::map<cstring, const IR::P4Action*> actions;
	std::map<cstring, const IR::P4Table*> tables;
	std::vector<const IR::Declaration_Instance*> instances;
	std::set<cstring> stacks;
	std::set<cstring> functions;
	std::map<cstring, std::vector<cstring>> pred;
	std::set<cstring> globalVariables;
	BoogieProcedure* currentProcedure=nullptr;
	cstring deparser=nullptr;
	// options
	P4VerifyOptions& options;
	// assertion
	bool addAssertions = false;
	int switchStatementCount = 0;
	BMV2CmdsAnalyzer* bMV2CmdsAnalyzer;

public:
	Translator(std::ostream &out, P4VerifyOptions &options, BMV2CmdsAnalyzer* bMV2CmdsAnalyzer = nullptr);
	void writeToFile();
	cstring toString();
	cstring toString(int val);
	cstring toString(const big_int&);
	void addNecessaryProcedures();
	void addProcedure(BoogieProcedure procedure);
	void addDeclaration(cstring decl);
	void addFunction(cstring op, cstring opbuiltin, cstring typeName, cstring returnType);
	void analyzeProgram(const IR::P4Program *program);
	cstring translate(IR::ID id);
	void incIndent();
	void decIndent();
	cstring getIndent();
	void incSwitchStatementCount();
	cstring getSwitchStatementCount();

	void addGlobalVariables(cstring variable);
	bool isGlobalVariable(cstring variable);
	void updateModifiedVariables(cstring variable);
	void addPred(cstring proc, cstring predProc);

	void translate(const IR::Node *node);
	void translate(const IR::Node *node, cstring arg);
	cstring translate(const IR::StatOrDecl *statOrDecl);
	

	void translate(const IR::Type_Declaration *typeDeclaration);
	cstring translate(const IR::Declaration *declaration);

	cstring translate(const IR::Declaration_Variable *declVar);

	// Statement
	cstring translate(const IR::Statement *stat);
	cstring translate(const IR::ExitStatement *exitStatement);
	cstring translate(const IR::ReturnStatement *returnStatement);
	cstring translate(const IR::EmptyStatement *emptyStatement);
	cstring translate(const IR::AssignmentStatement *assignmentStatement);
	cstring translate(const IR::IfStatement *ifStatement);
	cstring translate(const IR::BlockStatement *blockStatement);
	cstring translate(const IR::MethodCallStatement *methodCallStatement);
	cstring translate(const IR::SwitchStatement *switchStatement);

	// Expression
	cstring translate(const IR::Expression *expression);
	cstring translate(const IR::MethodCallExpression *methodCallExpression);
	cstring translate(const IR::Member *member);
	cstring translate(const IR::PathExpression *pathExpression);
	cstring translate(const IR::Path *path);
	cstring translate(const IR::SelectExpression *selectExpression, cstring stateName, cstring localDeclArg="");
	cstring translate(const IR::Argument *argument);
	cstring translate(const IR::Constant *constant);
	cstring translate(const IR::ConstructorCallExpression *constructorCallExpression);
	cstring translate(const IR::Cast *cast);
	cstring translate(const IR::Slice *slice);
	cstring translate(const IR::LNot *lnot);
	cstring translate(const IR::Mask *mask);
	cstring translate(const IR::ArrayIndex *arrayIndex);

	// Type
	cstring translate(const IR::Type *type);
	cstring translate(const IR::Type_Bits *typeBits);
	cstring translate(const IR::Type_Boolean *typeBoolean);
	cstring translate(const IR::Type_Specialized *typeSpecialized);
	cstring translate(const IR::Type_Name *typeName);
	cstring translate(const IR::Type_Stack *typeStack, cstring arg);
	cstring translate(const IR::Type_Typedef *typeTypedef);

	// Operation (also Expression)
	cstring translate(const IR::Operation_Binary *opBinary);
	cstring translate(const IR::Operation_Unary *opUnary);

	void translate(const IR::P4Program *program);
	void translate(const IR::Type_Error *typeError);
	void translate(const IR::Type_Extern *typeExtern);
	void translate(const IR::Type_Enum *typeEnum);
	void translate(const IR::Declaration_Instance *instance, cstring instanceName="");

	void translate(const IR::Type_Struct *typeStruct);
	void translate(const IR::Type_Struct *typeStruct, cstring arg);

	void translate(const IR::StructField *structField);
	void translate(const IR::StructField *structField, cstring arg);

	void translate(const IR::Type_Header *typeHeader);
	void translate(const IR::Type_Header *typeHeader, cstring arg);

	void translate(const IR::Type_Parser *typeParser);
	void translate(const IR::Type_Control *typeControl);
	void translate(const IR::Type_Package *typePackage);

	void translate(const IR::P4Parser *p4Parser);
	void translate(const IR::ParserState *parserState, cstring localDecl="", cstring localDeclArg="");
	void translate(const IR::P4Control *p4Control);
	void translate(const IR::Method *method);
	void translate(const IR::P4Action *p4Action);
	void translate(const IR::P4Table *p4Table);
	cstring translate(const IR::P4Table *p4Table, std::map<cstring, cstring> switchCases);
	cstring translate(const IR::Parameter *parameter, cstring arg="others");
	void translate(const IR::ActionList *actionList, cstring arg);

};

#endif