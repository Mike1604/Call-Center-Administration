#include "Name.h"
using namespace std;
Name::Name(){};
Name::Name(const Name& n): last(n.last), first(n.first){}
Name::Name(const string& f,const string& l){
    first=f;
    last=l;
}
//Getters
std::string Name::getFirst() const{
    return first;
}
std::string Name::getLast()const{
    return last;
}
//Setters
void Name::setFirst(const string &f){
    first=f;
}
void Name::setLast(const string &l){
    last=l;
}

string Name::toString() const{
    return first+" "+last;
}
Name& Name::operator=(const Name& n){
    first=n.first;
    last=n.last;
    return *this;
}
bool Name::operator==(const Name &n) const{
    return toString() == n.toString();
}
bool Name::operator!=(const Name &n) const{
    return toString() != n.toString();
}
bool Name::operator<=(const Name &n) const{
    return toString() <= n.toString();
}
bool Name::operator>=(const Name &n) const{
    return toString() >= n.toString();
}
bool Name::operator<(const Name &n) const{
    return toString() < n.toString();
}
bool Name::operator>(const Name &n) const{
    return toString() > n.toString();
}

ostream& operator<<(ostream& os, const Name& n) {
    os << n.toString();
    return os;
}
istream& operator>>(istream& is, Name& s){
    getline(is, s.first, ' ');
    getline(is, s.last);
    return is;
}
