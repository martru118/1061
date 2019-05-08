#include "person.h"

Person::Person() : _name("No name") 
{
    cout << "Person [" << this->_name << "] is created (DC)." << endl;
}

Person::Person(const string& name, int y, int m, int d) 
    : _name(name)
{
    _dob.y = y;
    _dob.m = m;
    _dob.d = d;

    cout << "Person [" << this->_name << "] is created (NC)." << endl;
}

Person::Person(const Person& p)
{
    _name = p._name;
    _dob = p._dob;  // Relying upon implicit assignment for structs

    cout << "Person [" << this->_name << "] is created (CC)." << endl;
}

Person::~Person()
{
    cout << "Person [" << this->_name << "] is being destroyed." << endl;
}

const Person& Person::operator=(const Person& p)
{
    _name = p._name;
    _dob = p._dob;  // Relying upon implicit assignment for structs
    return *this;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << p._name << endl;
    os << "dob: " << p._dob.y << " " << p._dob.m << " " << p._dob.d;
    return os;
}

istream& operator>>(istream& is, Person& p)
{
    is >> p._name;
    return is;
}