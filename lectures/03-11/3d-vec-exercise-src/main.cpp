#include "vec3.h"
#include "vec3-int.h"
#include "vec3-string.h"
#include "vec3-template.h"


using namespace std;

class Person
{
public:
  string name;
  int age;
};

int main()
{
  vec3 v(1,2,3);
  v.print();
  cout << find_max(v) << endl;

  vec3_int v2(10,-3,33);
  v2.print();
  cout << find_max(v2) << endl;

  vec3_string v3("Hello","World","Canada");
  v3.print();
  cout << find_max(v3) << endl;

  vec3_template<int> v4(2,3,4);
  v4.print();
  cout << find_max(v4) << endl;

  vec3_template<char> v5('0','A','z');
  v5.print();
  cout << find_max(v5) << endl;

  vec3_template<string> v6("CSCI","453","334");
  v6.print();
  cout << find_max(v6) << endl;

  Person p1("John", 31);
  Person p2("Jill", 32);
  Person p3("Mack", "39");
  vec3_template<Person> v7(p1,p2,p3);
  v7.print();
  cout << find_max(v7) << endl;
  
  
  return 0;
}
