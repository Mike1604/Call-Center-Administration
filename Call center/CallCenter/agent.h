#ifndef AGENT_H
#define AGENT_H
#include "Name.h"
#include "Hour.h"
#include "CallList.h"

class Agent
{
private:
    string code;
    Name nameAgent;
    int extension;
    Hour entrada;
    Hour salida;
    string especialidad;
    Hour hrsExtra;
    CallList listaLlamadas;
public:
    Agent();//Constructor base
    Agent(const Agent&);//Constructor Copia

    string toString(const bool&) const;

    //Getters
    string getCode() const;
    Name getName() const;
    int getExtension() const;
    Hour getEntrada() const;
    Hour getSalida() const;
    std::string getEspecialidad() const;
    Hour getHrsExtra() const;
    CallList& getCallList();
    //Setters
    void setCode(const string&);
    void setNameAgent(const Name&);
    void setExtension(const int&);
    void setEntrada(const Hour&);
    void setSalida(const Hour&);
    void setEspecialidad(const string&);
    void setHrsExtra(const Hour&);
    //Operadores
    Agent& operator=(const Agent&);
    bool operator==(const Agent&)const;
    bool operator!=(const Agent&)const;
    bool operator<=(const Agent&)const;
    bool operator>=(const Agent&)const;
    bool operator<(const Agent&)const;
    bool operator>(const Agent&)const;
    //Operadores de flujo
    friend std::ostream& operator<<(std::ostream&,const Agent&);
    friend std::istream& operator>>(std::istream&,Agent&);
};

#endif // AGENT_H
