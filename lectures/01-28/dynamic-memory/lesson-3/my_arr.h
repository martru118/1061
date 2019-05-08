#ifndef __my_arr_h__
#define __my_arr_h__

#include <iostream>

using namespace std;

struct my_arr {
  float* _a;
  int _sz;
};

float gen_rand()
{
  return  static_cast<float>(rand()) / RAND_MAX;
}

void prn_arr(my_arr& v)
{
  for (int i=0; i<v._sz; ++i) {
    cout << v._a[i] << " ";
  }
  cout << endl;
}

// Option 1
// my_arr* alloc_arr(int sz)
// {
//   my_arr pv;
//   pv._a = new float[sz];
//   pv._sz = sz;
//   return &pv; // (address to the local variable, bad, some compilers should complain)
// }

// Option 2
my_arr* alloc_arr(int sz)
{
  my_arr* pv = new my_arr;
  pv->_a = new float[sz];
  pv->_sz = sz;
  return pv; // (returning address to memory allocated on the heap) 
}

void gen_arr(my_arr& v)
{
  for (int i=0; i<v._sz; ++i) {
    v._a[i] = gen_rand();
  }
}

void dealloc_arr(my_arr** pv)
{
  delete [] (*pv)->_a;
  delete (*pv);
  *pv = 0;
}

#endif
