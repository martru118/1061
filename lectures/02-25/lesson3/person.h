#ifndef __person_h__
#define __person_h__

#include <iostream>
#include <string>

using namespace std;

class Person {
    protected:
    string _name;

    struct {
        int y; // yyyy
        int m; // mm
        int d; // dd
    } _dob;

    public:
    Person();
    Person(const string& name, int yyyy, int mm, int dd);
    Person(const Person& p);
    ~Person();

    const Person& operator=(const Person& p);

    void print_info();

    friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& os, Person& p);
};

#endif