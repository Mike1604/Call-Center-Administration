TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Agentlist.cpp \
        Agentnode.cpp \
        Call.cpp \
        CallList.cpp \
        CallMenu.cpp \
        CallNode.cpp \
        Date.cpp \
        Hour.cpp \
        Name.cpp \
        agent.cpp \
        agentmenu.cpp \
        main.cpp

HEADERS += \
    Agentlist.h \
    Agentnode.h \
    Call.h \
    CallList.h \
    CallMenu.h \
    CallNode.h \
    Date.h \
    Hour.h \
    ListException.h \
    Name.h \
    agent.h \
    agentmenu.h
