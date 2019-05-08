#ifndef __cat_h__
#define __cat_h__

#include <iostream>
#include <string>
#include "pet.h"

using namespace std;

class Cat : public Pet
{
  protected:
  string _color;
  
  public:
  Cat();
  Cat(const string& name, int age, int weight, const string& owner, const string& color);
  Cat(const Cat& c);  
  
  ~Cat();

  const Cat& operator=(const Cat& c);
  
  void speak();
  
  friend ostream& operator<<(ostream&, const Cat&);
};

#endif
