#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<stdlib.h>
#include<string>
#include <chrono>

using namespace std;

using namespace std;
class Date
{
private:
	int day;
	int month;
	int year;

    bool validDate(const int&, const int&, const int&);
    int toInt() const;
public:
	Date();//Constructor
	Date(const Date&); //Constructor
	Date(const int& year, const int& month, const int& day);//Constructor
    string toString(const int& m=0) const ;
	//Getters
    int getDay()const;
    int getMonth()const;
    int getYear()const;
	//Setters
	void setDay(const int&);
	void setMonth(const int&);
	void setYear(const int&);
	//Operadores
    Date& operator=(const Date&);
    bool operator==(const Date&)const;
    bool operator!=(const Date&)const;
    bool operator<=(const Date&)const;
    bool operator>=(const Date&)const;
    bool operator<(const Date&)const;
    bool operator>(const Date&)const;
    //Operadores de flujo
    friend std::ostream& operator<<(std::ostream&, const Date&);
    /*friend std::istream& operator>>(std::istream&, const Date&);
	*/
};
#endif
