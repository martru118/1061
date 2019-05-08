#ifndef fredrick
#define fredrick

#include <iostream>
#include <string>

using namespace std;

class Pet
{
  protected:
  string _name;
  int _age;
  int _weight;
  string _owner;

  public:
  Pet();
  Pet(const string& name, int age, int weight, const string& owner);
  Pet(const Pet& p);
  ~Pet();

  const string& get_name() const { return _name; }
  int get_age() const { return _age; }
  int get_weight() const { return _weight; }
  const string& get_owner() const { return _owner; }

  void set_name(const string& name) { _name = name; }
  void set_age(int age) { _age = age; }
  void set_weight(int weight) { _weight = weight; }
  void set_owner(const string& owner) { _owner = owner; }
  
  const Pet& operator=(const Pet& p);
  
  virtual void speak();
  
  friend ostream& operator<<(ostream&, const Pet&);
};

#endif
