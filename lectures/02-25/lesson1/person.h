#include <iostream>
#include <string>

using namespace std;

    struct DOB {
        int y; // yyyy
        int m; // mm
        int d; // dd
    };


class Person {
    protected:
    string _name;

    DOB _dob;

    public:
    Person();
    Person(const string& name, int yyyy, int mm, int dd);
    Person(const Person& p);
    ~Person();

    const Person& operator=(const Person& p);

    friend ostream& operator<<(ostream& os, const Person& p);
    friend istream& operator>>(istream& os, Person& p);
};