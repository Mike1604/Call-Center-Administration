#include "Date.h"

bool Date::validDate(const int& d, const int& m, const int& y) {
    int daysMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,30};
    if(y==0 | m<0 | m>12 | d<1){
        return false;
    }
    if(y % 4 == 0 && (y % 100 != 0 | y % 400 ==0)){//Bisiesto
        daysMonth[2]++;
    }
    if(d > daysMonth[m]){
        return false;
    }
    return true;
}
int Date::toInt()const{
    return year*10000 + month*100 + day;
}
//Constructores

Date::Date() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    time_t tt;
    tt = chrono::system_clock::to_time_t(today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    year = timeinfo->tm_year + 1900;
}
Date::Date(const Date& d) : day(d.day), month(d.month), year(d.year){
}
Date::Date(const int& year, const int& month, const int& day) : Date(){
    if(validDate(year,month,day)){
        this->year = year;
        this->month = month;
        this->day = day;
    }
}
string Date::toString(const int& m)const{
    char res[20];
    switch (m) {
        case 0:
            sprintf(res, "%02i / %02i / %02i", day, month, year);
        break;
        case 1:
            sprintf(res, "%02i / %02i / %02i",  month, day, year);
        break;
        case 2:
            sprintf(res, "%02i / %02i / %02i",  year, month, day);
        break;
    }

    return res;
}
//Getters
int Date::getDay()const{
    return day;
}
int Date::getMonth()const{
    return month;
}
int Date::getYear()const{
    return year;
}
//Setters
void Date::setDay(const int& d) {
    if (validDate(d, month, year))
    {
        day = d;
    }
    else {
        cout << "El dia ingresado no es valido" << endl;
    }
}
void Date::setMonth(const int& m) {
    if (validDate(day, m, year))
    {
        month = m;
    }
    else {
        cout << "El mes ingresado no es valido" << endl;
    }
}
void Date::setYear(const int& y) {
    if (validDate(day, month, y))
    {
        year = y;
    }
    else {
        cout << "El a�o ingresado no es valido" << endl;
    }
}
//Operadores
//Operadores
Date& Date::operator=(const Date& d) {
    day = d.day;
    month = d.month;
    year = d.year;
    return *this;;
}
bool Date::operator==(const Date& d)const {
    return toInt() == d.toInt();
}
bool Date::operator!=(const Date& d)const{
    return toInt() != d.toInt();
}
bool Date::operator<=(const Date& d)const{
    return toInt() <= d.toInt();
}
bool Date::operator>=(const Date& d)const{
    return toInt() >= d.toInt();
}
bool Date::operator<(const Date& d)const{
    return toInt() < d.toInt();
}
bool Date::operator>(const Date& d)const{
    return toInt() > d.toInt();
}
ostream& operator<<(ostream& os, Date& d) {
    os << d.toString();
    return os;
}
/*istream& operator>>(istream& is,Date& h){
    std::string myStr;

    getline(is,myStr," : ");
    h.day=atoi(myStr.c_str());

    getline(is, myStr);
    h.month=atoi(myStr.c_str());

    getline(is, myStr);
    h.year=atoi(myStr.c_str());
    return is;
}*/
