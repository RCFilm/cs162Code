#include <iostream>
#include <cassert>
#include <string>
#include <sstream>
#include <exception>

#include "ExpressionNode.h"
using namespace std;



ValueNode::ValueNode(int val) {
    value = val;
}

int ValueNode::evaluate() const {
    return value;
}

string ValueNode::toString() const {
    return std::to_string(value);
}


//--------------------------------------------------------

BinaryOperatorNode::BinaryOperatorNode(operationType op) {
    operation = op;
    //left and right shared_ptrs are automatically initialized to nullptr
//    left = nullptr;
//    right= nullptr;
}

void BinaryOperatorNode::setLeft(shared_ptr<ExpressionNode> child) {
    left = child;
}

void BinaryOperatorNode::setRight(shared_ptr<ExpressionNode> child) {
    right = child;
}

int BinaryOperatorNode::evaluate() const {
    if(left == nullptr || right == nullptr)
        throw(logic_error("Can't evaluate - missing child for BinaryOperatorNode"));

//    //Debug sample
//    cout << "Starting evaluate on " << getName() << endl;

    //Calculate left and right values
    int leftResult = left->evaluate();

//    //Debug sample
//    cout << getName() << " got " << leftResult << " from left" << endl;

    int rightResult = right->evaluate();

//    //Debug sample
//    cout << getName() << " got " << rightResult << " from right" << endl;

    switch(operation) {
        case ADD: return leftResult + rightResult;
        case SUBTRACT: return leftResult - rightResult;
        case MULTIPLY: return leftResult * rightResult;
        case DIVIDE: return leftResult / rightResult;
        case MOD: return leftResult % rightResult;
        default:
            throw(logic_error("Bad operation for BinaryOperatorNode"));
    }
    return 0; //never reach... make compiler happy
}


string BinaryOperatorNode::getName() const {
    switch(operation) {
        case SUBTRACT: return "subtract";
        case MULTIPLY: return "multiply";
        case DIVIDE: return "divide";
        case ADD: return "add";
        case MOD: return "mod";
        default:
            throw(logic_error("Bad operation for BinaryOperatorNode"));
    }
}

string BinaryOperatorNode::getSymbol() const {
    switch(operation) {
        case MULTIPLY: return "*";
        case DIVIDE: return "/";
        case ADD: return "+";
        case SUBTRACT: return "-";
        case MOD: return "%";
        default:
            throw(logic_error("Bad operation for BinaryOperatorNode"));
    }
}


string BinaryOperatorNode::toString() const {
    if(left == nullptr || right == nullptr)
        throw(logic_error("Can't evaluate - missing child for BinaryOperatorNode"));

    string s = "(";

    s += left->toString();              //recursively ask left side to strigify

    s += " " + getSymbol() + " ";       //add this operator

    s += right->toString();             //recursively ask right side to strigify

    s += ")";

    return s;
}

////If we were not using shared_ptrs, this node would have to delete both its children
//BinaryOperatorNode::~BinaryOperatorNode() {
//    //This node's parent will delete it.
//    //Just worry about children
//    if(left != nullptr) {
//        delete left;
//    }
//    if(right != nullptr) {
//        delete right;
//    }
//}
