#ifndef AGENTNODE_H
#define AGENTNODE_H
#include <exception>
#include "agent.h"

class AgentNodeException
{
private:
    std::string mensaje;
public:
    explicit AgentNodeException(const char* message) :mensaje(message) {}
    explicit AgentNodeException(const std::string& message) :mensaje(message) {}
    virtual ~AgentNodeException() throw() {}
    virtual const char* what() const throw() {
        return mensaje.c_str();
    }
};

class AgentNode
{
private:
    Agent* dataPtr;
    AgentNode* next;
    AgentNode* prev;
public:
    AgentNode();//Constructor
    AgentNode(const Agent&);//Constructor
    ~AgentNode();
    //Getters
    Agent* getData();
    Agent& getDataPtr();
    AgentNode* getPrev();
    AgentNode* getNext();
    //Setters
    void setDataPtr(Agent*);
    void setData(const Agent&);
    void setPrev(AgentNode*);
    void setNext(AgentNode*);
};

#endif // AGENTNODE_H
