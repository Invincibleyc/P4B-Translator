#include "boogie_statement.h"

BoogieStatement::BoogieStatement(){

}

BoogieStatement::BoogieStatement(const cstring &cont){
	this->cont = cont;
}

cstring BoogieStatement::toString(){
	return cont;
}

CallStatement::CallStatement(){

}

cstring CallStatement::toString(){
	return "";
}