#include "pet.h"

Pet::Pet()
  : _name(""), _age(0), _weight(0), _owner("")
{}

Pet::Pet(const string& name, int age, int weight, const string& owner)
  : _name(name), _age(age), _weight(weight), _owner(owner)
{}

Pet::~Pet()
{}

Pet::Pet(const Pet& p)
{
  _name = p._name;
  _age = p._age;
  _weight = p._weight;
  _owner = p._owner;
}

const Pet& Pet::operator=(const Pet& p)
{
  _name = p._name;
  _age = p._age;
  _weight = p._weight;
  _owner = p._owner;

  return *this;
}


void Pet::speak()
{
  cout << "I don\'t know how to speak." << endl;
}

ostream& operator<<(ostream& os, const Pet& p)
{
  os << "Name   = " << p._name << endl;
  os << "Age    = " << p._age << endl;
  os << "Weight = " << p._weight << endl;
  os << "Owner  = " << p._owner << endl;

  return os;
}

