#include "Agentnode.h"

AgentNode::AgentNode(): dataPtr(nullptr), next(nullptr), prev(nullptr) {}
AgentNode::AgentNode(const Agent& a): dataPtr(new Agent(a)), next(nullptr),prev(nullptr){
    if(dataPtr==nullptr){
        throw AgentNodeException("Memoria no disponible, creando AgentNode");
    }
}
AgentNode::~AgentNode(){
    delete dataPtr;
}
//Getters
Agent* AgentNode::getData(){
    if(dataPtr==nullptr){
        throw AgentNodeException("Error, el dato no existe, getData");
    }
    return dataPtr;
}
Agent& AgentNode::getDataPtr(){
    return *dataPtr;
}
AgentNode* AgentNode::getPrev(){
    return prev;
}
AgentNode* AgentNode::getNext(){
    return next;
}
//Setters
void AgentNode::setDataPtr(Agent *a){
    dataPtr=a;
}
void AgentNode::setData(const Agent &a){
    delete dataPtr;
    dataPtr = new Agent(a);
    if(dataPtr==nullptr){
        throw AgentNodeException("No se pudo guardar el dato, setData");
    }
}
void AgentNode::setNext(AgentNode *a){
    next=a;
}
void AgentNode::setPrev(AgentNode *a){
    prev=a;
}
