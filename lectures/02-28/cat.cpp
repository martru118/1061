#include "cat.h"

Cat::Cat()
  : Pet()
{}

Cat::Cat(const string& name, int age, int weight, const string& owner, const string& color)
  : Pet(name, age, weight, owner), _color(color)
{}

Cat::~Cat()
{}

Cat::Cat(const Cat& c)
  : Pet(c)
{
  _color = c._color;
}

const Cat& Cat::operator=(const Cat& c)
{
  (Pet&) *this = (const Pet&) c;
  _color = c._color;
  return *this;
}


void Cat::speak()
{
  cout << "Meow" << endl;
}
  
ostream& operator<<(ostream& os, const Cat& c)
{
  os << (const Pet&) c;
  os << "Color = " << c._color << endl;
  
  return os;
}

