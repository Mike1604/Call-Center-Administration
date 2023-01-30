#ifndef CALL_H
#define CALL_H
#include "Hour.h"
#include "Name.h"
#include<iostream>
#include<string>

using namespace std;

class Call
{
private:
    Name client;
	Hour hourCall;
	Hour duration;
	int id;
public:
	Call(); //Constructor
	Call(Call&); //Constructor
    Call(Name&,const Hour&, const Hour&,const int&); //Constructor

    string toString() const;
	//Getters
    Name getClient() const;
    Hour getHourCall() const;
    Hour getDuration() const;
    int getId() const;
	//Setters
    void setClient(const Name&);
    void setHour(const Hour&);
    void setDuration(const Hour&);
    void setId(const int&);
	//Operadores
    Call& operator=(const Call&);
    bool operator==(const Call&) const;
    bool operator!=(const Call&) const;
    bool operator<=(const Call&) const;
    bool operator>=(const Call&) const;
    bool operator<(const Call&) const;
    bool operator>(const Call&) const;
    //Operadores de flujo
    friend ostream& operator<<(ostream&,const Call&);
    friend istream& operator>>(istream&,Call&);
};
#endif
