#include "boogie_statement.h"

BoogieStatement::BoogieStatement(){
	hide = false;
}

BoogieStatement::BoogieStatement(const cstring &cont){
	this->cont = cont;
}

cstring BoogieStatement::toString(){
	// if(this->hide)
	// 	return "";
	return cont;
}

CallStatement::CallStatement(){

}

cstring CallStatement::toString(){
	return "";
}