#ifndef __dog_h__
#define __dog_h__

#include <iostream>
#include <string>
#include "pet.h"

using namespace std;

class Dog : public Pet
{
  protected:
  string _breed;
  
  public:
  Dog();
  Dog(const string& name, int age, int weight, const string& owner, const string& breed);
  Dog(const Dog& c);  
  
  ~Dog();

  const Dog& operator=(const Dog& c);
  
  void speak();
  
  friend ostream& operator<<(ostream&, const Dog&);
};

#endif
