#include "Hour.h"
#include<string.h>
#include <chrono>

bool Hour::ValidHour(const int& h, const int& m) {
    return (h >= 0) && (h <= 24) && (m >= 0) && (m <= 60);
}

//Constructores
Hour::Hour() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t(today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);
    hora = timeinfo->tm_hour;
    minuto = timeinfo->tm_min;
}
Hour::Hour(const Hour& h){
    hora = h.hora;
    minuto = h.minuto;
}

Hour::Hour(const int& h, const int& m) {
    if (ValidHour(h, m))
    {
        this->hora = h;
        this->minuto = m;
    }
    else {
        cout << "Hora ingresada no valida" << std::endl;
    }

}
int Hour::toInt()const{
    return hora * 100 + minuto;
}
//Getters
int Hour::getHour() {
    return hora;
}
int Hour::getMin() {
    return minuto;
}
//setters
void Hour::setHour(const int& h) {
    if (ValidHour(h, minuto))
    {
        this->hora = h;
    }
    else {
        cout << "La hora ingresada no es valida" << std::endl;
    }

}
void Hour::setMin(const int& m) {
    if (ValidHour(hora, m))
    {
        this->minuto = m;
    }
    else {
        cout << "El minuto ingresada no es valida" << std::endl;
    }
}
//toString
string Hour::toString()const{
    char texto[8];
    sprintf(texto, "%02i:%02i", hora, minuto);
    return texto;
}
//Operadores
Hour& Hour::operator=(const Hour& h) {
    hora = h.hora;
    minuto = h.minuto;
    return *this;
}
bool Hour::operator==(const Hour& h) const{
    return toInt() == h.toInt();
}
bool Hour::operator!=(const Hour& h)const{
    return toInt() != h.toInt();
}
bool Hour::operator<=(const Hour& h) const{
    return toInt() <= h.toInt();
}
bool Hour::operator>=(const Hour& h) const{
    return toInt() >= h.toInt();
}
bool Hour::operator<(const Hour& h) const{
    return toInt() < h.toInt();
}
bool Hour::operator>(const Hour& h) const{
    return toInt() > h.toInt();
}

ostream& operator<<(ostream& os, const Hour& h) {
    os << h.toString();
    return os;
}

istream& operator>>(istream& is, Hour& h) {
    string myStr;

    getline(is, myStr, ':');
    h.hora = atoi(myStr.c_str());

    getline(is, myStr);
    h.minuto = atoi(myStr.c_str());

    return is;
}
