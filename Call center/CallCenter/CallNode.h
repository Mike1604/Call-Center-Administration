#ifndef CallNode_H
#define CallNode_H
#include "Call.h"
#include<iostream>
#include<stdlib.h>
#include<string>
class CallNode
{
private:
	Call data;
	CallNode* next;
public:
	CallNode(); //Constructor
    CallNode(const Call&); //Constructor
	~CallNode(); //Destructor
	//Getters
	Call& getData();
	CallNode* getNext();
	//Setters
	void setData(Call&);
	void setNext(CallNode*);
	bool operator!=(Call&);

};
#endif 
