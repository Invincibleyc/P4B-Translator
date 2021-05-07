#ifndef BACKENDS_VERIFY_TRANSLATE_BOOGIE_STATEMENT_H_
#define BACKENDS_VERIFY_TRANSLATE_BOOGIE_STATEMENT_H_

class BoogieStatement{
private:
	cstring cont;
	bool hide;
public:
	BoogieStatement();
	BoogieStatement(const cstring &cont);
	cstring toString();
};

class CallStatement:BoogieStatement{
private:
public:
	CallStatement();
	cstring toString();
};

#endif