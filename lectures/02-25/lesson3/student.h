#ifndef __student_h__
#define __student_h__

#include "person.h"

class Student : public Person
{
    protected:
    string _institute;
    
    public:
    Student();
    Student(const string& name, int yyyy, int mm, int dd);
    Student(const Student& p);
    ~Student();

    void institute(const string& ins);
    const string& institute() const; 

    const Student& operator=(const Student& p);

    void print_info(); // Overriding/overloading

    friend ostream& operator<<(ostream& os, const Student& p);
    friend istream& operator>>(istream& os, Student& p);
};

#endif