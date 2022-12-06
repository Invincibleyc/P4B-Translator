#include "backends/verify/translate/p4ltl_utils.h"

// bool isAPNode(P4LTL::AstNode* node){
// 	if(dynamic_cast<P4LTL::P4LTLAtomicProposition*>(node) != nullptr)
// 		return true;
// 	return false;
// }


// std::vector<P4LTL::AstNode*> getAllAPs(P4LTL::AstNode* root){
// 	std::vector<P4LTL::AstNode*> aps;
// 	for(auto child: getAllNodes(root)){
// 		if(isAPNode(child)) aps.push_back(child);
// 	}
// 	return aps;
// }

void P4LTLTranslator::getAllNodes(std::vector<P4LTL::AstNode*>& nodes, P4LTL::AstNode* root){
	nodes.push_back(root);
    for(auto child: root->getOutgoingNodes()){
        getAllNodes(nodes, child);
    }
}

std::vector<P4LTL::AstNode*> P4LTLTranslator::getAllNodes(P4LTL::AstNode* root){
	std::vector<P4LTL::AstNode*> nodes;
	getAllNodes(nodes, root);
	return nodes;
}

std::set<cstring> P4LTLTranslator::getOldExprs(P4LTL::AstNode* root){
	std::set<cstring> res;
	for(auto node:getAllNodes(root)){
		if(auto oldExpression = dynamic_cast<P4LTL::OldExpression*>(node)){
			res.insert(oldExpression->getValue());
		}
	}
	return res;
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::AstNode* node){
	if(auto binOpNode = dynamic_cast<P4LTL::BinOpNode*>(node)){
		return translateP4LTL(binOpNode);
	}
	else if(auto uOpNode = dynamic_cast<P4LTL::UOpNode*>(node)){
		return translateP4LTL(uOpNode);
	}
	else if(auto ap = dynamic_cast<P4LTL::P4LTLAtomicProposition*>(node)){
		return translateP4LTL(ap);
	}
	else if(auto predicate = dynamic_cast<P4LTL::Predicate*>(node)){
		return translateP4LTL(predicate);
	}
	else if(auto intLiteral = dynamic_cast<P4LTL::IntLiteral*>(node)){
		return translateP4LTL(intLiteral);
	}
	else if(auto boolLiteral = dynamic_cast<P4LTL::BooleanLiteral*>(node)){
		return translateP4LTL(boolLiteral);
	}
	else if(auto name = dynamic_cast<P4LTL::Name*>(node)){
		return translateP4LTL(name);
	}
	else if(auto key = dynamic_cast<P4LTL::Key*>(node)){
		return translateP4LTL(key);
	}
	else if(auto arrayAccess = dynamic_cast<P4LTL::ArrayAccessExprssion*>(node)){
		return translateP4LTL(arrayAccess);
	}
	else {
		return node->toString();
	}
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::BinOpNode* node){
	// std::cout << "BinOpNode" << std::endl;
	// std::cout << node->toString() << std::endl;
	if(auto binTempOp = dynamic_cast<P4LTL::BinaryTemporalOperator*>(node)){
		// std::cout << "BinaryTemporalOperator" << std::endl << node->getOp() << std::endl;
		return "("+translateP4LTL(binTempOp->getLeft())+binTempOp->getOp()
				+translateP4LTL(binTempOp->getRight())+")";
	}
	else if(auto extendedCompOp = dynamic_cast<P4LTL::ExtendedComparativeOperator*>(node)){
		// std::cout << "ExtendedComparativeOperator" << std::endl << node->getOp() << std::endl;
		
		cstring variable = TempVariable::getPrefix("_p4ltl_");
		addVariable(variable);
		addDeclaration("\nvar "+variable+":bool;\n");

		cstring left = translateP4LTL(extendedCompOp->getLeft());
		cstring right = translateP4LTL(extendedCompOp->getRight());
		int sizeLeft = getSize(left), sizeRight = getSize(right);
		if(sizeLeft != -1 || sizeRight != -1){
			if(sizeLeft == -1) sizeLeft = sizeRight;
			else if(sizeRight == -1) sizeRight = sizeLeft;
			
			if(sizeLeft != sizeRight){
				std::cout << "ERROR: " << left << extendedCompOp->getOp() << right 
					<< " is not legal." << std::endl;
			}
			else{
				sizes[variable] = sizeLeft;
				// std::cout << "update size: " << variable << " = " << extendedCompOp->toString() << std::endl;
				// std::cout << "              " << sizeLeft << std::endl << std::endl;
				
				cstring size = p4Translator->toString(sizeLeft);
				cstring powerFunc = "power_2_"+size+"()";
            	cstring funcName = "";
            	if(extendedCompOp->getOp() == " == ") funcName = "beq.bv"+size;
            	else if(extendedCompOp->getOp() == " > ") funcName = "bugt.bv"+size;
            	else if(extendedCompOp->getOp() == " >= ") funcName = "bsge.bv"+size;
            	else if(extendedCompOp->getOp() == " != ") funcName = "bneq.bv"+size;
            	else if(extendedCompOp->getOp() == " < ") funcName = "bult.bv"+size;
            	else if(extendedCompOp->getOp() == " <= ") funcName = "bsle.bv"+size;
            	cstring function = "function {:inline true} "+funcName+"(left:int, right:int) : bool{((left\%"
            		+powerFunc+")"+extendedCompOp->getOp()+"(right\%"+powerFunc+"))}\n";
            	p4Translator->addFunction(funcName, function);
            	addStatement(variable+" := "+funcName+"("+left+", "+right+");\n");
			}
		}
		else{
			// std::cout << "unknown size: " << left << " " << right << std::endl;
			addStatement(variable+" := "+left+extendedCompOp->getOp()+right+";\n");
		}
		return "("+variable+" == true)";
		// return "("+translateP4LTL(extendedCompOp->getLeft())+extendedCompOp->getOp()
		// 		+translateP4LTL(extendedCompOp->getRight())+")";
	}
	else if(auto binPredOp = dynamic_cast<P4LTL::BinaryPredicateOperator*>(node)){
		// std::cout << "BinaryPredicateOperator" << std::endl << node->getOp() << std::endl;

		return "("+translateP4LTL(binPredOp->getLeft())+binPredOp->getOp()
				+translateP4LTL(binPredOp->getRight())+")";
	}
	// + - *
	else if(auto binTermOp = dynamic_cast<P4LTL::BinaryTermOperator*>(node)){
		// std::cout << "BinaryTermOperator" << std::endl << node->getOp() << std::endl;

		cstring variable = TempVariable::getPrefix("_p4ltl_");
		addVariable(variable);
		addDeclaration("\nvar "+variable+":int;\n");

		cstring left = translateP4LTL(binTermOp->getLeft());
		cstring right = translateP4LTL(binTermOp->getRight());
		int sizeLeft = getSize(left), sizeRight = getSize(right);
		if(sizeLeft != -1 || sizeRight != -1){
			if(sizeLeft == -1) sizeLeft = sizeRight;
			else if(sizeRight == -1) sizeRight = sizeLeft;
			
			if(sizeLeft != sizeRight){
				std::cout << "ERROR: " << left << binTermOp->getOp() << right 
					<< " is not legal." << std::endl;
			}
			else{
				sizes[variable] = sizeLeft;
				// std::cout << "update size: " << variable << " = " << binTermOp->toString() << std::endl;
				// std::cout << "              " << sizeLeft << std::endl << std::endl;
				
				cstring size = p4Translator->toString(sizeLeft);
				cstring powerFunc = "power_2_"+size+"()";
            	cstring funcName = "";
            	if(binTermOp->getOp() == " + ") funcName = "add.bv"+size;
            	else if(binTermOp->getOp() == " - ") funcName = "sub.bv"+size;
            	else if(binTermOp->getOp() == " * ") funcName = "add.bv"+size;
            	cstring function = "function {:inline true} "+funcName+"(left:int, right:int) : int{("+
                	"(left\%"+powerFunc+")+(right\%"+powerFunc+"))\%"+powerFunc+"}\n";
            	p4Translator->addFunction(funcName, function);
            	addStatement(variable+" := "+funcName+"("+left+", "+right+");\n");
			}
		}
		else{
			// std::cout << "unknown size: " << left << " " << right << std::endl;
			addStatement(variable+" := "+left+binTermOp->getOp()+right+";\n");
		}
		return variable;
	}
	else return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::UOpNode* node){
	if(auto unTempOp = dynamic_cast<P4LTL::UnaryTemporalOperator*>(node)){
		return "("+unTempOp->getOp()+"("+translateP4LTL(unTempOp->getChild())+"))";
	}
	else if(auto unPredOp = dynamic_cast<P4LTL::UnaryPredicateOperator*>(node)){
		return "("+unPredOp->getOp()+"("+translateP4LTL(unPredOp->getChild())+"))";
	}
	else return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::P4LTLAtomicProposition* node){
	return "AP("+translateP4LTL(node->getProposition())+")";
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::Predicate* node){
	if(auto drop = dynamic_cast<P4LTL::Drop*>(node)){
		return drop->toString();
	}
	else if(auto forward = dynamic_cast<P4LTL::Forward*>(node)){
		return forward->toString();
	}
	else if(auto valid = dynamic_cast<P4LTL::Valid*>(node)){
		return valid->getHeader()+".valid == true";
	}
	else if(auto apply = dynamic_cast<P4LTL::Apply*>(node)){
		return apply->toString();
	}
	else return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::IntLiteral* node){
	return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::BooleanLiteral* node){
	return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::Name* node){
	if(auto oldExpression = dynamic_cast<P4LTL::OldExpression*>(node)){
		return "_old_"+oldExpression->getValue();
	}
	else{
		cstring res = node->toString();
		if(isFreeVariable(res)){
			return freeVars[res];
		}
		else return res;
	}
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::Key* node){
	return node->toString();
}

cstring P4LTLTranslator::translateP4LTL(P4LTL::ArrayAccessExprssion* node){
	cstring res = "";
	auto nodes = node->getOutgoingNodes();
	res = translateP4LTL(nodes[0]);
    for(int i = 1; i < nodes.size(); ++i)
        res += "[" + translateP4LTL(nodes[i]) + "]";
	return res;
}

int P4LTLTranslator::getSize(cstring variable){
	if(p4Translator->getSize(variable) != -1){
		return p4Translator->getSize(variable);
	}
	else if(sizes.find(variable) != sizes.end()){
		return sizes[variable];
	}
	else return -1;
}

std::map<cstring, cstring>  P4LTLTranslator::getFreeVariables(){
	return freeVars;
}

bool P4LTLTranslator::isFreeVariable(cstring variable){
	return freeVars.find(variable) != freeVars.end();
}

void P4LTLTranslator::addFreeVariable(cstring variable){
	std::string str = variable.c_str();
	int idx = str.find(':');
	if(idx == -1){
		std::cout << "ERROR: free variable must be declared with TYPE.\n" 
			<< str << std::endl; 
		std::abort();
	}
	cstring name, type;
	name = str.substr(0, idx);
	type = str.substr(idx+1);
	if(type != "bool" && type != "int"){
		std::cout << "ERROR: Unsupported type \""<< type << "\"" << std::endl; 
		std::abort();
	}
	freeVars[name] = "_p4ltl_free_"+name;
	addDeclaration("\nvar "+freeVars[name]+":"+type+";\n");
}

void P4LTLTranslator::createFreeVariables(cstring decl){
	std::string str = decl.c_str();

	int idx = str.find(' ');
	while(idx != -1){
		str.erase(idx, 1);
		idx = str.find(' ');
	}

	int start = 0, end = 0;
	end = str.find(',', start);
	while(end != -1){
		addFreeVariable(str.substr(start, end-start));
		start = end+1;
		end = str.find(',', start);
	}
	if(start < str.length()){
		addFreeVariable(str.substr(start));
	}
}

/*
	Variables:  additional variables
	Statements:  statements for main Procedure
	Declarations:  declarations for variables
*/
std::vector<cstring> P4LTLTranslator::getVariables(){
	return vars;
}

void P4LTLTranslator::addVariable(cstring variable){
	vars.push_back(variable);
}

std::vector<cstring> P4LTLTranslator::getStatements(){
	return stmts;
}

void P4LTLTranslator::addStatement(cstring stmt){
	stmts.push_back(stmt);
}

std::vector<cstring> P4LTLTranslator::getDeclarations(){
	return declarations;
}

void P4LTLTranslator::addDeclaration(cstring declaration){
	declarations.push_back(declaration);
}