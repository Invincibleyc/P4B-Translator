#ifndef BACKENDS_VERIFY_TRANSLATE_TRANSLATE_H_
#define BACKENDS_VERIFY_TRANSLATE_TRANSLATE_H_

#include <fstream>
#include <map>
#include "ir/ir.h"
#include "boogie_procedure.h"
#include "boogie_statement.h"

class Translator{
private:
	BoogieProcedure mainProcedure;
	std::vector<BoogieProcedure> procedures;
	cstring declaration;
	cstring code;
	std::ostream& out;
	int indent = 0;
	std::map<cstring, const IR::Type_Header*> headers;
	std::map<cstring, const IR::Type_Struct*> structs;
	std::set<cstring> declared;
	BoogieProcedure* currentProcedure=nullptr;
public:
	Translator(std::ostream &out);
	void writeToFile();
	cstring toString();
	void addNecessaryProcedures();
	void addProcedure(BoogieProcedure procedure);
	void addDeclaration(cstring decl);
	void addFunction(cstring op, cstring opbuiltin, cstring typeName, cstring returnType);
	void analyzeProgram(const IR::P4Program *program);
	void incIndent();
	void decIndent();
	cstring getIndent();

	void translate(const IR::Node *node);
	void translate(const IR::Node *node, cstring arg);
	cstring translate(const IR::StatOrDecl *statOrDecl);
	

	void translate(const IR::Type_Declaration *typeDeclaration);
	cstring translate(const IR::Declaration *declaration);

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
	cstring translate(const IR::SelectExpression *selectExpression);
	cstring translate(const IR::Argument *argument);
	cstring translate(const IR::Constant *constant);

	// Type
	cstring translate(const IR::Type *type);
	cstring translate(const IR::Type_Bits *typeBits);
	cstring translate(const IR::Type_Boolean *typeBoolean);

	// Operation (also Expression)
	cstring translate(const IR::Operation_Binary *opBinary);

	void translate(const IR::P4Program *program);
	void translate(const IR::Type_Error *typeError);
	void translate(const IR::Type_Extern *typeExtern);
	void translate(const IR::Type_Enum *typeEnum);

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
	void translate(const IR::ParserState *parserState);
	void translate(const IR::P4Control *p4Control);
	void translate(const IR::Method *method);
	void translate(const IR::P4Action *p4Action);
	void translate(const IR::P4Table *p4Table);
	cstring translate(const IR::Parameter *parameter);
};

#endif