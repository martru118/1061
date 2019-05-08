#include <iostream>
#include "student.h"

using namespace std;

Student::Student() : Person()
{
    _institute = "Not set";

    cout << "Student [" << this->_name << "] is created (DC)." << endl;
}

Student::Student(const string& name, int yyyy, int mm, int dd)
    : Person(name, yyyy, mm, dd)
{
    _institute = "Not set";

    cout << "Student [" << this->_name << "] is created (NC)." << endl;
}

Student::Student(const Student& p)
    : Person(p)
{
    _institute = p._institute;

    cout << "Student [" << this->_name << "] is created (CC)." << endl;
}

Student::~Student()
{
    cout << "Student [" << this->_name << "] is being destroyed." << endl;
}

void Student::institute(const string& ins)
{
    _institute = ins;
}
 
const string& Student::institute() const
{
    return _institute;
}

const Student& Student::operator=(const Student& p)
{
    (Person&) *this = (const Person&) p;
    _institute = p._institute;

    return *this;
}

ostream& operator<<(ostream& os, const Student& p)
{
    os << (const Person&) p << endl; // Casting is important
    os << "institute: " << p._institute;
    return os;
}

istream& operator>>(istream& is, Student& p)
{
    is >> p;
    return is;
}