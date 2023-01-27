#include "p4ltlast.hpp"

namespace P4LTL
{
    // Class ASTNode
const std::vector<AstNode*>& AstNode::getOutgoingNodes() const
{
    return this->outgoingNodes;
}

void AstNode::addOutgoing(AstNode* successorNode)
{
    outgoingNodes.push_back(successorNode);
}

// Class BinOp Node
BinOpNode::BinOpNode(AstNode* l, AstNode* r)
: left(l), right(r)
{
    this->addOutgoing(left);
    this->addOutgoing(right);
}

std::string BinOpNode::toString() const
{
    std::string result = "(" + 
    left->toString() + 
    this->getOp() + 
    right->toString() + ")";
    return result;
}

AstNode* BinOpNode::getLeft() const
{
    return this->left;
}

AstNode* BinOpNode::getRight() const
{
    return this->right;
}

// Class UOp Node
UOpNode::UOpNode(AstNode* c)
: child(c)
{
    this->addOutgoing(child);
}

std::string UOpNode::toString() const
{
    std::string result = "(" + 
    this->getOp() + "(" + 
    child->toString() + ")" 
    + ")";
    return result;
}

AstNode* UOpNode::getChild() const
{
    return this->child;
}

/* LTL part */

// BinOp LTL
BinaryTemporalOperator::BinaryTemporalOperator(BinaryTemporalOperatorType type, AstNode* l, AstNode* r)
: type(type), BinOpNode(l, r)
{

}

BinaryTemporalOperator::BinaryTemporalOperatorType BinaryTemporalOperator::getOpType() const
{
    return this->type;
}

std::string BinaryTemporalOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case And:
        op = " && ";
        break;
    case Or:
        op = " || ";
        break;
    case Implies:
        op = " ==> ";
        break;
    case Until:
        op = " U ";
        break;
    case Release:
        op = " R ";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Binary Temporal Time Initilization error, type is" + 
        std::to_string(type));
    return op;
}

// UOp LTL
UnaryTemporalOperator::UnaryTemporalOperator(UnaryTemporalOperatorType type, AstNode* c)
: type(type), UOpNode(c)
{
}

UnaryTemporalOperator::UnaryTemporalOperatorType UnaryTemporalOperator::getOpType() const
{
    return this->type;
}

std::string UnaryTemporalOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case Global:
        op = "[]";
        break;
    case Final:
        op = "<>";
        break;
    case Next:
        op = "X";
        break;
    case Not:
        op = "!";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Unary Temporal Time Initilization error, type is" + 
        std::to_string(type));
    return op;
}

// Class AP
P4LTLAtomicProposition::P4LTLAtomicProposition(AstNode* p)
:p(p)
{
    this->addOutgoing(p);
}

std::string P4LTLAtomicProposition::toString() const
{
    return "AP(" + p->toString() + ")";
}

AstNode* P4LTLAtomicProposition::getProposition() const
{
    return p;
}

/* Predicate part*/


// Class Drop
std::string Drop::toString() const
{
    return "drop";
}

Predicate::PredicateType Drop::getType() const
{
    return drop;
}

// Class Forward
Forward::Forward(AstNode* port): port(port)
{
}

std::string Forward::toString() const
{
    // note: need to convert to "(egress_port == port)" in p4expr
    return "fwd(" + port->toString() + ")";
}

Predicate::PredicateType Forward::getType() const
{
    return fwd;
}

AstNode* Forward::getPort() const
{
    return port;
}

// Class Valid
Valid::Valid(const std::string& header): header(header)
{
}

std::string Valid::toString() const
{
    // note: need to convert to "header.valid" in p4expr
    return "valid(" + header + ")";
}

Predicate::PredicateType Valid::getType() const
{
    return valid;
}

std::string Valid::getHeader() const
{
    return header;
}

// Class Apply
Apply::Apply(const std::string& table)
: table(table)
{
}
Apply::Apply(const std::string& table, const std::string& action)
: table(table), action(action)
{
}
std::string Apply::toString() const
{
    if(action.empty())
        return "Apply(" + table + ")";
    else
        return "Apply(" + table + "," + action + ")";
}
Predicate::PredicateType Apply::getType() const
{
    return apply;
}
std::string Apply::getTable() const
{
    return table;
}
std::string Apply::getAction() const
{
    return action; 
}

// comp predicate
ExtendedComparativeOperator::ExtendedComparativeOperator(ExtendedComparativeOperatorType type, AstNode* l, AstNode* r)
: type(type), BinOpNode(l, r)
{

}

ExtendedComparativeOperator::ExtendedComparativeOperatorType ExtendedComparativeOperator::getOpType() const
{
    return this->type;
}

std::string ExtendedComparativeOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case eq:
        op = " == ";
        break;
    case gt:
        op = " > ";
        break;
    case geq:
        op = " >= ";
        break;
    case neq:
        op = " != ";
        break;
    case leq:
        op = " <= ";
        break;
    case lt:
        op = " < ";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Binary Temporal Time Initilization error, type is" + 
        std::to_string(type));
    
    return op;
}

// predicate binop
BinaryPredicateOperator::BinaryPredicateOperator(BinaryPredicateOperatorType type, AstNode* l, AstNode* r)
: type(type), BinOpNode(l, r)
{

}

BinaryPredicateOperator::BinaryPredicateOperatorType BinaryPredicateOperator::getOpType() const
{
    return this->type;
}

std::string BinaryPredicateOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case And:
        op = " && ";
        break;
    case Or:
        op = " || ";
        break;
    case Implies:
        op = " ==> ";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Binary Temporal Time Initilization error, type is" + 
        std::to_string(type));
    return op;
}

// predicate uop
UnaryPredicateOperator::UnaryPredicateOperator(UnaryPredicateOperatorType type, AstNode* c)
: type(type), UOpNode(c)
{
}

UnaryPredicateOperator::UnaryPredicateOperatorType UnaryPredicateOperator::getOpType() const
{
    return this->type;
}

std::string UnaryPredicateOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case Not:
        op = "!";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Unary Temporal Time Initilization error, type is" + 
        std::to_string(type));
    return op;
}

/*Term part*/
// Class Int
IntLiteral::IntLiteral(INT_TYPE val)
:value(val)
{}

INT_TYPE IntLiteral::getValue() const
{
    return this->value;
}

std::string IntLiteral::toString() const
{
    return std::to_string(this->getValue());
}

// Class Bool
BooleanLiteral::BooleanLiteral(bool val)
:value(val)
{}

bool BooleanLiteral::getValue() const
{
    return this->value;
}

std::string BooleanLiteral::toString() const
{
    return std::to_string(this->getValue());
}

//Class Name
Name::Name(const std::string& name)
:identity(name)
{}

std::string Name::getValue() const
{
    return this->identity;
}

std::string Name::toString() const
{
    return getValue();
}

//Class Old
OldExpression::OldExpression(AstNode* expr)
{
    this->value = expr;
}

AstNode* OldExpression::getValue() const
{
    return this->value;
}

std::string OldExpression::toString() const
{
    return "old(" + this->getValue()->toString() + ")";
}

//Class BinOp Term
BinaryTermOperator::BinaryTermOperator(BinaryTermOperatorType type, AstNode* l, AstNode* r)
: type(type), BinOpNode(l, r)
{

}

BinaryTermOperator::BinaryTermOperatorType BinaryTermOperator::getOpType() const
{
    return this->type;
}

std::string BinaryTermOperator::getOp() const
{
    std::string op;
    switch (type)
    {
    case Plus:
        op = " + ";
        break;
    case Minus:
        op = " - ";
        break;
    case Multiply:
        op = " * ";
        break;
    case Divide:
        op = " / ";
        break;
    default:
        break;
    }
    
    if(op.empty())
        throw std::invalid_argument("Binary Temporal Time Initilization error, type number is " + 
        std::to_string(type));
    
    return op;
}

// class Key
Key::Key(const std::string& table, const std::string& key)
: table(table), key(key)
{
}
std::string Key::toString() const
{
    return "Key(" + table + "," + key + ")";
}
std::string Key::getTable() const
{
    return table;
}
std::string Key::getKey() const
{
    return key; 
}

//ArrayAccessExpr
std::string ArrayAccessExprssion::toString() const
{
    auto nodes = this->getOutgoingNodes();
    std::string result = nodes[0]->toString();
    for(int i = 1; i < nodes.size(); ++i)
        result += "[" + nodes[i]->toString() + "]";
    return result;
}

ArrayAccessExprssion::ArrayAccessExprssion(AstNode* name, AstNode* accessor)
{
    this->addOutgoing(name);
    this->addOutgoing(accessor);
}
ArrayAccessExprssion::ArrayAccessExprssion(AstNode* name, AstNode* accessor1, AstNode* accessor2)
{
    this->addOutgoing(name);
    this->addOutgoing(accessor1);
    this->addOutgoing(accessor2);
}
}