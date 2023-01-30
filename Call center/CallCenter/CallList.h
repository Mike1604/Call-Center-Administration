#ifndef CALLLIST_H
#define CALLLIST_H
#include "CallNode.h"
#include "Call.h"
#include "ListException.h"
#include <iostream>
#include <string>
#include  <fstream>
using namespace std;
class CallList
{
private:
    CallNode* ancla;
public:
    CallList();
    CallList(const CallList&);
    ~CallList(); //Destructor
    bool validPos(CallNode*);
    bool empty();
    //Operaciones de la lista
    string toString()const;
    void pushCall(CallNode*,Call&);
    void pushcallordered(Call&);
    void popCall(CallNode*);
    CallNode* findCall(Call);
    Call& findACall(Call);
    bool findCode(int&);
    void popAllCalls();
    //Getters
    CallNode* get1stPos() const;
    CallNode* getLastPos();
    CallNode* getNextPos(CallNode*);
    CallNode* getPrevPos(CallNode*);
    void copyAll(const CallList&);
    void writeToDisk(const string&);
    void readFromDisk(const string&);

    CallList& operator=(const CallList&);
};
#endif 

