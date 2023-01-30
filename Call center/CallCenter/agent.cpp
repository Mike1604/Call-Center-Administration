#include "agent.h"
//Constructores
Agent::Agent(){}
Agent::Agent(const Agent& a): code((a.code)), nameAgent(a.nameAgent), extension(a.extension), entrada(a.entrada), salida(a.salida), especialidad(a.especialidad), hrsExtra(a.hrsExtra), listaLlamadas(a.listaLlamadas){
}//Constructor Copia

string Agent::toString(const bool& sublist=false) const{
    string res;
    res+=code;
    res+="|"
    +nameAgent.toString()
    +"\t|"
    +to_string(extension)
    +"\t|"
    +entrada.toString()
    +"\t|"
    +salida.toString()
    +"\t|"
    +especialidad
    +"\t|"
    +hrsExtra.toString();
    if(sublist){
        res+= "\n";
        res+="__________________________\n";
        res+=listaLlamadas.toString()
        +"__________________________\n";
    }
    return res;
}
//Getters
string Agent::getCode() const{
    return code;
}
Name Agent::getName() const{
    return nameAgent;
}

int Agent::getExtension() const{
    return extension;
}
Hour Agent::getEntrada() const{
    return entrada;
}
Hour Agent::getSalida() const{
    return salida;
}
std::string Agent::getEspecialidad() const{
    return especialidad;
}
Hour Agent::getHrsExtra() const{
    return hrsExtra;
}
CallList& Agent::getCallList(){
    return listaLlamadas;
}
//Setters
void Agent::setCode(const string& c){
    code = c;
}
void Agent::setNameAgent(const Name& n){
    nameAgent=n;
}
void Agent::setExtension(const int& e){
    extension=e;
}
void Agent::setEntrada(const Hour& en){
    entrada=en;
}
void Agent::setSalida(const Hour& s){
    salida=s;
}
void Agent::setEspecialidad(const string& es){
    especialidad=es;
}
void Agent::setHrsExtra(const Hour& hr){
    hrsExtra=hr;
}
//Operadores
Agent& Agent::operator=(const Agent& a){
    code=a.code;
    nameAgent=a.nameAgent;
    extension=a.extension;
    entrada=a.entrada;
    salida=a.salida;
    especialidad=a.especialidad;
    hrsExtra=a.hrsExtra;
    listaLlamadas=a.listaLlamadas;
    return *this;
}
bool Agent::operator==(const Agent& a)const{
    return code == a.code;
}
bool Agent::operator!=(const Agent& a)const{
    return code!=a.code;
}
bool Agent::operator<=(const Agent& a)const{
    return code<=a.code;
}
bool Agent::operator>=(const Agent& a)const{
    return code>=a.code;
}
bool Agent::operator<(const Agent& a)const{
    return code<a.code;
}
bool Agent::operator>(const Agent& a)const{
    return code>a.code;
}
ostream& operator<<(ostream& os, const Agent& s){
    os<<s.code<<endl;
    os<<s.nameAgent<<endl;
    os<<s.extension<<endl;
    os<<s.entrada<<endl;
    os<<s.salida<<endl;
    os<<s.especialidad<<endl;
    os<<s.hrsExtra;
   return os;
}
istream& operator>>(istream& is, Agent& s){
    string myStr;
    getline(is, s.code);
    is>>s.nameAgent;
    getline(is, myStr);
    s.extension = atoi(myStr.c_str());
    is>>s.entrada;
    is>>s.salida;
    getline(is, s.especialidad);
    is>>s.hrsExtra;
    return is;
}
