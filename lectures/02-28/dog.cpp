#include "dog.h"

Dog::Dog()
  : Pet()
{}

Dog::Dog(const string& name, int age, int weight, const string& owner, const string& breed)
  : Pet(name, age, weight, owner), _breed(breed)
{}

Dog::~Dog()
{}

Dog::Dog(const Dog& c)
  : Pet(c)
{
  _breed = c._breed;
}

const Dog& Dog::operator=(const Dog& c)
{
  (Pet&) *this = (const Pet&) c;
  _breed = c._breed;
  return *this;
}


void Dog::speak()
{
  cout << "Woof" << endl;
}
  
ostream& operator<<(ostream& os, const Dog& c)
{
  os << (const Pet&) c;
  os << "Breed = " << c._breed << endl;
  
  return os;
}

