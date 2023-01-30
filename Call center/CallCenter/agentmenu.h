#ifndef AGENTMENU_H
#define AGENTMENU_H
#include <iostream>
#include<windows.h>
#include<string>
#include "Agentlist.h"
#include "CallMenu.h"

class AgentMenu
{
private:
    AgentList* ListRefer;
    void gotoxy(int x,int y);
    void enterToContinue();
    void frame();
    void splash();
    void mainMenu();
    void agentMenu();
    void admCalls();
    void pushAgent();
    void modifyAgent();
    void popAgent();
    void deleteAll();
    void showAgents();
    void findAgent();
    void sortAgents();
    void admAlmac();
    void writeToDisk();
    void readFromDisk();

public:
    AgentMenu(AgentList*);

};

#endif // AGENTMENU_H
