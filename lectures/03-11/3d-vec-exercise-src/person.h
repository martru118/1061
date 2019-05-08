#ifndef __person_h__
#define __person_h__

#include <iostream>
using namespace std;

class Person
{
  protected:
  string name;
  int age;

  public:
  Person() {}

  Person(const string& n, int a) {
      this->name = n;
      this->age = a;
  }

  //default constructor for the template recipe
  Person(const Person& p) {
      *this = p;    //piggyback off operator=()
  }

  bool operator<(const Person& p) {
      return !(*this < p);
  }

  friend ostream& operator<<(ostream& os, const Person& p)
  {
      os << p.name << ", " << p.age;
      return os;
  }

  Person& operator=(const Person& p) {
      name = p.name;
      age = p.age;
      return *this;
  }

  void print();  

  friend int find_max(const Person& v);
};

void Person::print()
{
  cout << "(" << name << "," << age << ")" << endl;
}

int find_max(const Person& p)
{
    int maxAge = p.age;
}

#endif