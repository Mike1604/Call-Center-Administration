#ifndef HOUR_H
#define HOUR_H
#include<iostream>
#include<conio.h>
#include<string>
#include <chrono>
using namespace std;

class Hour
{
private:
    int hora, minuto;
public:
    bool ValidHour(const int&, const int&);
    Hour(); //<<Constructor>>
    Hour(const Hour&); //<<Constructor>>
    Hour(const int&, const int&); //<<Constructor>>
    int toInt()const;
    //Getters
    int getHour();
    int getMin();
    //Setters
    void setHour(const int&);
    void setMin(const int&);
    //ToString
    string toString()const;
    //Operadores de comparacion
    Hour& operator=(const Hour&);
    bool operator==(const Hour&)const;
    bool operator!=(const Hour&)const;
    bool operator<=(const Hour&)const;
    bool operator>=(const Hour&)const;
    bool operator<(const Hour&)const;
    bool operator>(const Hour&)const;
    //Operadores de flujo
    friend ostream& operator<<(ostream&, const Hour&);
    friend istream& operator>>(istream&, Hour&);
};
#endif
