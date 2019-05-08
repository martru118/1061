#include <iostream>
#include "person.h"
#include "student.h"

using namespace std;

int main()
{
  Person a("Mathilda", 2000, 01, 01);
  a.print_info();


  Student b("John", 2006, 01, 03);
  b.institute("UOIT");
  b.print_info();

  Person& c = b;
  c.print_info();

  return 0;
}
