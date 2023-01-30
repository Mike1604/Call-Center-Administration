#include "Call.h"
Call::Call() {}//Constructor
Call::Call(Call& c): client(c.client),hourCall(c.hourCall), duration(c.duration), id(c.id) {}
Call::Call(Name& c,const Hour& h, const Hour& du,const int& id): client(c),hourCall(h), duration(du), id(id){}
string Call::toString() const{
    string res;
    res += to_string(id)
        + "\t|"
        + client.toString()
        + "\t|"
        + hourCall.toString()
        + "\t|"
        + duration.toString()
        + "\n";
    return res;
}
//Getters
Name Call::getClient() const{
    return client;
}

Hour Call::getHourCall() const{
    return hourCall;
}
Hour Call::getDuration() const{
    return hourCall;
}
int Call::getId() const{
    return id;
}
//Setters
void Call::setClient(const Name& n) {
    client = n;
}

void Call::setHour(const Hour& h) {
    hourCall = h;
}
void Call::setDuration(const Hour& du) {
    duration=du;
}
void Call::setId(const int& i){
    id=i;
}
//Operadores
Call& Call::operator=(const Call& c){
    client = c.client;
    hourCall = c.hourCall;
    duration = c.duration;
    id = c.id;
    return *this;
}
bool Call::operator==(const Call& d) const{
    return id == d.id;
}
bool Call::operator!=(const Call& d) const{
    return id != d.id;
}
bool Call::operator<=(const Call& d) const{
    return hourCall.toInt() <= d.hourCall.toInt();
}
bool Call::operator>=(const Call& d) const{
    return hourCall.toInt() >= d.hourCall.toInt();
}
bool Call::operator<(const Call& d) const{
    return hourCall.toInt() < d.hourCall.toInt();
}
bool Call::operator>(const Call& d) const{
    return hourCall.toInt() > d.hourCall.toInt();
}
ostream& operator<<(ostream& os, const Call& s){
    os<<s.id<<endl;
    os<<s.client<<endl;
    os<<s.hourCall<<endl;
    os<<s.duration;
    return os;
}
istream& operator>>(istream& is, Call& s){
    string myStr;
    getline(is, myStr);
    s.id = atoi(myStr.c_str());
    is>>s.client;
    is>>s.hourCall;
    is>>s.duration;
    return is;
}
