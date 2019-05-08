#include <iostream>
#include "person.h"
#include "student.h"

using namespace std;

int main()
{
  Person a("Mathilda", 2000, 01, 01);
  cout << a << endl;
  cout << "** " << __FILE__ << ":" << __LINE__ <<  " **" << endl;

  Student b("John", 2006, 01, 03);
  b.institute("UOIT");
  cout << b << endl;
  cout << "** " << __FILE__ << ":" << __LINE__ <<  " **" << endl;

  // Student c;
  // c = b;
  // cout << "Printing c" << endl; 
  // cout << c << endl;

  return 0;
}
