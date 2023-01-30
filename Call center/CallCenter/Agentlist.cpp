#include "Agentlist.h"
using namespace std;
bool AgentList::isValidPos(AgentNode *p){
    AgentNode* aux(header->getNext());
    while(aux != header){
        if(p==aux){
            return true;
        }
        aux=aux->getNext();
    }
    return false;
}

void AgentList::copyAll(const AgentList &l){
    AgentNode* aux(l.header->getNext());
    AgentNode* newNode;
    while(aux!=l.header){
        newNode = new AgentNode(aux->getDataPtr());
        if(newNode == nullptr){
            throw ListException("Memoria no disponible, copyAll");
        }

        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux=aux->getNext();
    }
}

void AgentList::swatPtr(AgentNode *a, AgentNode *b){
    if(a != b){
        Agent* aux(a->getData());
        a->setDataPtr(b->getData());
        b->setDataPtr(aux);
    }
}

void AgentList::sortByName(AgentNode *left, AgentNode *right){
        if(left == right){
            return;
        }
        if(left->getNext() == right){
            if(left->getDataPtr().getName() > right->getDataPtr().getName()){
                swatPtr(left,right);
            }
            return;
        }
        AgentNode* i(left);
        AgentNode* j(right);
        while (i != j) {
            while ((i != j) && (i->getDataPtr().getName() <= right->getDataPtr().getName())) {
                i = i->getNext();
            }
            while ((i != j) && (j->getDataPtr().getName() >= right->getDataPtr().getName())) {
                j = j->getPrev();
            }
            swatPtr(i,j);
        }
        swatPtr(i,right);
        if(i != left){
            sortByName(left, i->getPrev());
        }
        if(i != right){
            sortByName(i->getNext(),right);
        }
}

void AgentList::sortBySpeciality(AgentNode *left, AgentNode *right){
    if(left == right){
        return;
    }
    if(left->getNext() == right){
        if(left->getDataPtr().getEspecialidad() > right->getDataPtr().getEspecialidad()){
            swatPtr(left,right);
        }
        return;
    }
    AgentNode* i(left);
    AgentNode* j(right);
    while (i != j) {
        while ((i != j) && (i->getDataPtr().getEspecialidad()<=right->getDataPtr().getEspecialidad())) {
            i = i->getNext();
        }
        while ((i != j) && (j->getDataPtr().getEspecialidad()>=right->getDataPtr().getEspecialidad())) {
            j = j->getPrev();
        }
        swatPtr(i,j);
    }
    swatPtr(i,right);
    if(i != left){
        sortBySpeciality(left, i->getPrev());
    }
    if(i != right){
        sortBySpeciality(i->getNext(),right);
    }
}

AgentList::AgentList() : header(new AgentNode){
    if(header==nullptr){
        throw ListException("Memoria no disponible, inicializando lista");
    }
    header->setPrev(header);
    header->setNext(header);
}
AgentList::AgentList(const AgentList& l){
    copyAll(l);
}

//Destructor
AgentList::~AgentList(){
    deleteAll();
    delete header;
}


bool AgentList::isEmpty(){
    return header->getNext()==header;
}

void AgentList::insertData(AgentNode *p, const Agent &e){
    if((p != nullptr)&&(!isValidPos(p))){
        throw  ListException("Posicion invalida, insertdata");
    }
    AgentNode* aux(new AgentNode(e));
    if(aux==nullptr){
        throw ListException("Memoria no disponible, Insertdata");
    }
    if(p==nullptr){
        p=header;
    }
    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);
}

void AgentList::deleteData(AgentNode *d){
    if(!isValidPos(d)){
        throw ListException("Posicion invalida, deleteData");
    }
    d->getPrev()->setNext(d->getNext());
    d->getNext()->setPrev(d->getPrev());
    delete d;
}

//Getters
AgentNode* AgentList::getFirstPos(){
    if(isEmpty()){
        return nullptr;
    }
    return header->getNext();
}
AgentNode* AgentList::getLastPos(){
    if(isEmpty()){
        return nullptr;
    }
    return header->getPrev();
}
AgentNode* AgentList::getPrevPos(AgentNode *p){
    if(p==header->getNext() or !isValidPos(p)){
        return nullptr;
    }
    return p->getPrev();
}
AgentNode* AgentList::getNextPos(AgentNode *p){
    if(p==header->getPrev() or !isValidPos(p)){
        return nullptr;
    }
    return p->getNext();
}

AgentNode* AgentList::findata(const Agent& e){
    AgentNode* aux(header->getNext());
    while(aux!=header){
        if(aux->getDataPtr() == e){
            return aux;
        }
        aux=aux->getNext();
    }
    return nullptr;
}

AgentNode* AgentList::findAgent(const Agent& e){
    AgentNode* aux(header->getNext());
    while(aux!=header){
        if(aux->getDataPtr().getName() == e.getName()){
            return aux;
        }
        aux=aux->getNext();
    }
    return nullptr;
}

Agent AgentList::retrieve(AgentNode *p){
    if(!isValidPos(p)){
        throw ListException("Posicion invalida, retrieve");
    }
    return p->getDataPtr();
}

void AgentList::sortByName(){
    sortByName(getFirstPos(),getLastPos());
}

void AgentList::sortBySpeciality(){
    sortBySpeciality(getFirstPos(),getLastPos());
}

string AgentList::toString(const bool& withAgentList){
    AgentNode* aux(header->getNext());
    string res;
    while(aux != header){
        res+= aux->getData()->toString(withAgentList);
        res+="\n";
        aux=aux->getNext();
    }
    return res;
}

void AgentList::deleteAll(){
    AgentNode* aux;
    while(header->getNext()!=header){
        aux=header->getNext();
        header->setNext(aux->getNext());
        delete aux;
    }
    header->setPrev(header);
}

void AgentList::writeToDisk(const string & fileName){
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()){
        string message;
        message ="Error al abrir el archivo ";
        message+=fileName;
        message+=" para escritura";

        throw ListException(message);
    }
    AgentNode* aux(header->getNext());
    system("del *.Calls");

    while(aux!=header){
        myFile <<aux->getDataPtr()<<endl;
        try{
            aux->getDataPtr().getCallList().writeToDisk(aux->getDataPtr().getCode()+".Calls");
        }
        catch(ListException ex){
            system("cls");
            cout<<ex.what()<<endl;
        }
        aux = aux->getNext();
    }

    myFile.close();
}

void AgentList::readFromDisk(const string& fileName){
    ifstream myFile;
    myFile.open(fileName);

    if(!myFile.is_open()){
        string message;
        message="Error al tratar de abrir el archivo ";
        message+=fileName;
        message+=" para lectura";
        throw ListException(message);
    }

    Agent myAgent;
    AgentNode* aux;

    deleteAll();

    while(myFile >> myAgent){
        try{
            myAgent.getCallList().readFromDisk(myAgent.getCode()+".Calls");
        }
        catch(ListException ex){
            cout<<ex.what()<<endl;
        }
        if((aux = new AgentNode(myAgent)) == nullptr){
            myFile.close();
            throw ListException("Memoria no disponible, readFromDisk");
        }

        aux->setPrev(header->getPrev());
        aux->setNext(header);

        header->getPrev()->setNext(aux);
        header->setPrev(aux);
    }
    myFile.close();
}

AgentList& AgentList::operator=(const AgentList &l){
    deleteAll();
    copyAll(l);
    return *this;
}
