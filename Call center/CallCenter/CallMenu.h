#ifndef CALLMENU_H
#define CALLMENU_H
#include "CallList.h"
#include <iostream>
#include<windows.h>
#include<string>
class CallMenu
{
private:
    CallList* ListRefer;
    void gotoxy(int x,int y);
    void enterToContinue();
    void frame();
    void mainMenu();
    void pushCall();
    void modifyCall();
    void popCall();
    void deleteAll();
    void showCalls();
    void findCall();

public:
    CallMenu(CallList*);

};
#endif 
