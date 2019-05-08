#include <iostream>
#include "person.h"
#include "student.h"
#include "util.h"

using namespace std;

int main()
{
  Student s("John", 2006, 01, 03);
  s.institute("UOIT");
  s.print_info();

  PRN_LN // Macro defined in util.h
  Person a;
  a = s;
  a.print_info();

  PRN_LN
  Person& b = s;
  b.print_info();

  PRN_LN
  Person c = s;
  c.print_info();

  PRN_LN
  Person* d = &s;
  d->print_info();

  // PRN_LN
  // Student t = a; // Try this, you should get an error.

  return 0;
}
