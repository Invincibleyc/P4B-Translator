#ifndef P4LTLAST_H
#define P4LTLAST_H

#include <string>
#include <vector>
#include <stdexcept>

namespace P4LTL
{
    class AstNode
{
private:
    std::vector<AstNode*> outgoingNodes;

public:
    virtual std::string toString() const = 0;
    const std::vector<AstNode*>& getOutgoingNodes () const;
    void addOutgoing(AstNode*);
};

class BinOpNode: public AstNode
{
private:
    AstNode* left, *right;

public:
    BinOpNode(AstNode* l, AstNode* r);
    std::string toString() const;
    virtual std::string getOp() const = 0;
    AstNode* getLeft() const;
    AstNode* getRight() const;
};

class UOpNode: public AstNode
{ 
private:
    AstNode* child;

public:
    UOpNode(AstNode* c);
    std::string toString() const;
    virtual std::string getOp() const = 0;
    AstNode* getChild() const;
};

// LTL part
class BinaryTemporalOperator: public BinOpNode
{
public:
    enum BinaryTemporalOperatorType
    {
        And, Or, Implies, Until, Release
    };    
private:
    BinaryTemporalOperatorType type;

public:
    BinaryTemporalOperator(BinaryTemporalOperatorType type, AstNode* l, AstNode* r);
    std::string getOp() const;
    BinaryTemporalOperatorType getOpType() const;
};

class UnaryTemporalOperator: public UOpNode
{
public:
    enum UnaryTemporalOperatorType
    {
        Global, Final, Next, Not
    };    
private:
    UnaryTemporalOperatorType type;

public:
    UnaryTemporalOperator(UnaryTemporalOperatorType type, AstNode* c);
    std::string getOp() const;
    UnaryTemporalOperatorType getOpType() const;
};

class P4LTLAtomicProposition: public AstNode
{
private:
    AstNode* p;
public:
    P4LTLAtomicProposition(AstNode* p);
    std::string toString() const;
    AstNode* getProposition() const;
};

// Pred part
class Predicate: public AstNode
{
public:
    enum PredicateType
    {
        drop, fwd, valid, apply
    };
    virtual PredicateType getType() const = 0; 
};

class Drop: public Predicate
{
public:
    std::string toString() const;
    PredicateType getType() const;
};

class Forward: public Predicate
{
private:
    AstNode* port;

public:
    Forward(AstNode* port);
    std::string toString() const;
    PredicateType getType() const;
    AstNode* getPort() const;
};

class Valid: public Predicate
{
private:
    std::string header;

public:
    Valid(const std::string& header);
    std::string toString() const;
    PredicateType getType() const;
    std::string getHeader() const;
};

class Apply: public Predicate
{
private:
    std::string table;
    std::string action;

public:
    Apply(const std::string& table);
    Apply(const std::string& table, const std::string& action);
    std::string toString() const;
    PredicateType getType() const;
    std::string getTable() const;
    std::string getAction() const;
};

class ExtendedComparativeOperator: public BinOpNode
{
public:
    enum ExtendedComparativeOperatorType
    {
        eq, gt, geq, neq, leq, lt
    };    
private:
    ExtendedComparativeOperatorType type;

public:
    ExtendedComparativeOperator(ExtendedComparativeOperatorType type, AstNode* l, AstNode* r);
    ExtendedComparativeOperatorType getOpType() const;
    std::string getOp() const;
};

class BinaryPredicateOperator: public BinOpNode
{
public:
    enum BinaryPredicateOperatorType
    {
        And, Or, Implies
    };    
private:
    BinaryPredicateOperatorType type;

public:
    BinaryPredicateOperator(BinaryPredicateOperatorType type, AstNode* l, AstNode* r);
    BinaryPredicateOperatorType getOpType() const;
    std::string getOp() const;
};

class UnaryPredicateOperator: public UOpNode
{
public:
    enum UnaryPredicateOperatorType
    {
        Not
    };    
private:
    UnaryPredicateOperatorType type;

public:
    UnaryPredicateOperator(UnaryPredicateOperatorType type, AstNode* c);
    std::string getOp() const;
    UnaryPredicateOperatorType getOpType() const;
};

// Term Part
typedef unsigned long long int INT_TYPE;
class IntLiteral: public AstNode
{
private:
    INT_TYPE value;
public:
    INT_TYPE getValue() const;
    IntLiteral(INT_TYPE val);
    std::string toString() const;
};

class BooleanLiteral: public AstNode
{
private:
    bool value;
public:
    bool getValue() const;
    BooleanLiteral(bool val);
    std::string toString() const;
};

class Name: public AstNode
{
private:
    std::string identity;
public:
    std::string getValue() const;
    Name(const std::string& name);
    std::string toString() const;
};

class OldExpression: public AstNode
{
private:
    AstNode* value;
public:
    // OldExpression(const std::string& name);
    OldExpression(AstNode* value);
    AstNode* getValue() const;
    std::string toString() const;
};

class BinaryTermOperator: public BinOpNode
{
public:
    enum BinaryTermOperatorType
    {
        Plus, Minus, Multiply, Divide
    };    
private:
    BinaryTermOperatorType type;

public:
    BinaryTermOperator(BinaryTermOperatorType type, AstNode* l, AstNode* r);
    BinaryTermOperatorType getOpType() const;
    std::string getOp() const;
};

class Key: public AstNode
{
private:
    std::string table;
    std::string key;
public:
    Key(const std::string& table, const std::string& key);
    std::string toString() const;
    std::string getTable() const;
    std::string getKey() const;
};

class ArrayAccessExprssion: public AstNode
{
public:
    std::string toString() const;
    ArrayAccessExprssion(AstNode* name, AstNode* accessor);
    ArrayAccessExprssion(AstNode* name, AstNode* accessor1, AstNode* accessor2);
};
}


#endif