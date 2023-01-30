#ifndef NAME_H
#define NAME_H
#include<string>
#include <iostream>
class Name
{
private:
    std::string last;
    std::string first;
public:
    Name();
    Name(const Name&);
    Name(const std::string&, const std::string&);
    //Getters
    std::string getFirst()const;
    std::string getLast()const;
    //Setters
    void setFirst(const std::string&);
    void setLast(const std::string&);

    std::string toString() const;

    Name& operator=(const Name&);
    bool operator==(const Name&) const;
    bool operator!=(const Name&) const;
    bool operator<=(const Name&) const;
    bool operator>=(const Name&) const;
    bool operator<(const Name&) const;
    bool operator>(const Name&) const;
    //Operadores de flujo
    friend std::ostream& operator<<(std::ostream&, const Name&);
    friend std::istream& operator>>(std::istream&, Name&);
};

#endif // NAME_H
