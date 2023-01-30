#include "CallList.h"
CallList::CallList() :ancla(nullptr) {}
CallList::CallList(const CallList& l){
    copyAll(l);
}
CallList::~CallList() {
    if(empty()){

    }
    else{
        return;
    }

}
bool CallList::validPos(CallNode* p) {
    CallNode* aux(ancla);
    while (aux != nullptr)
    {
        if (aux == p)
        {
            return true;
        }
        aux = aux->getNext();
    }
    return false;
}
bool CallList::empty() {
    return ancla == nullptr;
}
string CallList::toString() const{
    string res;
    CallNode* aux(ancla);
    while (aux != nullptr)
    {
        res += aux->getData().toString();
        aux = aux->getNext();
    }
    return res;
}
void CallList::pushCall(CallNode* p,Call& d) {
    if ((p != nullptr) && ( !validPos(p)))
    {
        throw ListException("El elemento no puede ser guardado, posicion invalida");
    }
    CallNode* aux(new CallNode(d));
    if (aux == nullptr){
        throw ListException("Memoria no disponible");
    }
    if (p == nullptr)
    {
        aux->setNext(ancla);
        ancla = aux;
    }
    else {
        aux->setNext(p->getNext());
        p->setNext(aux);
    }
}
void CallList::pushcallordered(Call& e) {
    CallNode* aux(ancla);
    CallNode* p(nullptr);
    while ((aux != nullptr) && (e.getHourCall() > aux->getData().getHourCall()))
    {
        p = aux;
        aux = aux->getNext();
    }
    pushCall(p, e);
}
void CallList::popCall(CallNode* p) {
    if (!validPos(p)) {
        throw ListException("Posicion invalida, popCall");
    }
    if (p == ancla)
    {
        ancla = p->getNext();
    }
    else {
        getPrevPos(p)->setNext(p->getNext());
    }
    delete p;
}
CallNode* CallList::findCall(Call d) {
    CallNode* aux(ancla);
    while ((aux != nullptr) && (aux->getData() != d))
    {
        aux = aux->getNext();
    }
    return aux;
}
Call& CallList::findACall(Call d) {
    CallNode* aux(ancla);
    while ((aux != nullptr) && (aux->getData() != d))
    {
        aux = aux->getNext();
    }
    return aux->getData();
}
bool CallList::findCode(int& d){
    CallNode* aux(ancla);
    while ((aux != nullptr) && (aux->getData().getId() != d))
    {
        aux = aux->getNext();
    }
    if (aux!=nullptr)
    {
        return true;
    }
    else{
        return false;
    }
}
void CallList::popAllCalls() {
    CallNode* aux;
    while (ancla != nullptr)
    {
        aux = ancla;
        ancla = ancla->getNext();
        delete aux;
    }

}
CallNode* CallList::get1stPos() const {
    return ancla;
}
CallNode* CallList::getLastPos() {
    if (empty())
    {
        return nullptr;
    }
    CallNode* aux(ancla);
    while (aux->getNext() != nullptr)
    {
        aux = aux->getNext();
    }
    return aux;
}
CallNode* CallList::getNextPos(CallNode* p) {
    return p->getNext();
}
CallNode* CallList::getPrevPos(CallNode* p) {
    if (p == ancla || !validPos(p))
    {
        return nullptr;
    }
    CallNode* aux(ancla);
    while (aux->getNext() != p)
    {
        aux = aux->getNext();
    }
    return aux;
}
void CallList::copyAll(const CallList& l) {
    CallNode* aux(l.ancla);
    CallNode* last(nullptr);
    CallNode* newNode;
    while (aux != nullptr)
    {
        newNode = new CallNode(aux->getData());
        if (newNode == nullptr)
        {
            throw ListException("Memoria no disponible, copyAll");
        }

        if (last == nullptr) {
            ancla = newNode;
        }
        else {
            last->setNext(newNode);
        }
        last = newNode;
        aux = aux->getNext();
    }

}

void CallList::writeToDisk(const string &fileName){
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()){
        string message;
        message ="Error al abrir el archivo ";
        message+=fileName;
        message+=" para escritura";

        throw ListException(message);
    }
    CallNode* aux(ancla);

    while(aux!=nullptr){
        myFile << aux->getData()<<endl;
        aux = aux->getNext();
    }

    myFile.close();

}

void CallList::readFromDisk(const string& fileName){
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()){
        string message;
        message = "Error al abrir el archivo";
        message+=fileName;
        message+=" para lectura";

        throw ListException(message);
    }

    popAllCalls();

    Call myCall;
    CallNode* last(nullptr);
    CallNode* newNode;

    while(myFile >> myCall){
        if ((newNode =new CallNode(myCall)) == nullptr){
            myFile.close();

        throw ListException("Memoria no disponible, readFromDisk");
        }

    if(last==nullptr){
        ancla=newNode;
    }
    else{
        last->setNext(newNode);
    }

    last=newNode;

    }
    myFile.close();
}

CallList& CallList::operator=(const CallList& l) {
    popAllCalls();
    copyAll(l);
    return *this;
}
