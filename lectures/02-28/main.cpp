#include <iostream>
#include "pet.h"
#include "cat.h"
#include "dog.h"


using namespace std;

int main()
{
  Pet a("Hana", 6, 14, "Michael");
  Cat b("Grace", 7, 15, "Ben", "Gray and White");
  Pet c("Felix", 4, 6, "Ian");
  Dog d("Dobby", 3, 45, "Smith", "Labrador");

  cout << "With Pet array" << endl;
  Pet arr1[4];
  arr1[0] = a;
  arr1[1] = b;
  arr1[2] = c;
  arr1[3] = d;  
  for (int i=0; i<4; ++i) {
    arr1[i].speak();
  }

  cout << "With Pet Pointer array" << endl;
  Pet* arr2[4];
  arr2[0] = &a;
  arr2[1] = &b;
  arr2[2] = &c;
  arr2[3] = &d;
  for (int i=0; i<4; ++i) {
    arr2[i]->speak();
  }
  

  
  

  // Pet a;
  // cout << a << endl;

  // Pet b("Hana", 6, 14, "Michael");
  // cout << b << endl;
  // b.speak();

  // Cat c("Hana", 6, 14, "Michael", "Tiger color");
  // cout << c << endl;
  // c.speak();

  // Pet d;
  // cout << d << endl;
  // d = b;
  // cout << d << endl;

  // Cat e;
  // cout << e << endl;
  // e = Cat("Grace", 7, 15, "Ben", "Gray and White");
  // cout << e << endl;
  
  return 0;
}
