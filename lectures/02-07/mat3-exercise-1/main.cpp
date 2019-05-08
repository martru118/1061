#include <iostream>
#include "mat3.h"

using namespace std;


int main()
{
  double arr[] = {1.1, 23.3, 4.5, 3};

  Mat3 v1(2);
  cout << v1 << endl;

  Mat3 v2(arr, 4);
  cout << v2 << endl;
  
  v1 = v2;
  cout << v1 << endl;
  cout << boolalpha << (v1 == v2) << endl;

  cout << v1[0] << endl;
  cout << v1(0) << endl;

  v1[0] = 3;
  v1(2) = 6;
  cout << v1 << endl;

  int x = v1;
  cout << x << endl;

  cout << boolalpha << (v1 == v2) << endl;

  return 0;
}

// The following operators cannot be overloaded
//
// ?: (conditional)
// . (member selection)
// .* (member selection with pointer-to-member)
// :: (scope resolution)
// sizeof (object size information)
// typeid (object type information)
// static_cast (casting operator)
// const_cast (casting operator)
// reinterpret_cast (casting operator)
// dynamic_cast (casting operator)