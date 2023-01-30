#include "CallNode.h"
//Constructores
CallNode::CallNode() :next(nullptr) {}
CallNode::CallNode(const Call& e) {
    data = e;
    next = nullptr;
}
CallNode::~CallNode() {}
//Getters
Call& CallNode::getData() {
    return data;
}
CallNode* CallNode::getNext() {
    return next;
}
//setters
void CallNode::setData(Call& e) {
    data = e;
}
void CallNode::setNext(CallNode* p) {
    next = p;
}
