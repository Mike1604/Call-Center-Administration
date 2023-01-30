#ifndef AGENTLIST_H
#define AGENTLIST_H
#include  <fstream>
#include "Agentnode.h"
#include "agent.h"
#include "ListException.h"

class AgentList
{
private:
    AgentNode* header;
    bool isValidPos(AgentNode*);

    void copyAll(const AgentList&);

    void swatPtr(AgentNode*, AgentNode*);

    void sortByName(AgentNode*, AgentNode*);
    void sortBySpeciality(AgentNode*, AgentNode*);
public:
    AgentList();
    AgentList(const AgentList&);

    ~AgentList();

    bool isEmpty();
    void insertData(AgentNode*, const Agent&);
    void deleteData(AgentNode*);

    AgentNode* getFirstPos();
    AgentNode* getLastPos();
    AgentNode* getPrevPos(AgentNode*);
    AgentNode* getNextPos(AgentNode*);

    AgentNode* findata(const Agent&);
    AgentNode* findAgent(const Agent&);
    Agent retrieve(AgentNode*);

    void sortByName();
    void sortBySpeciality();

    std::string toString(const bool&);

    void deleteAll();

    void writeToDisk(const string&);
    void readFromDisk(const string&);

    AgentList& operator=(const AgentList&);
};

#endif // AGENTLIST_H
