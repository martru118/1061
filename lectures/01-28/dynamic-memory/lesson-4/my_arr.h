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

my_arr* alloc_arr(int sz)
{
  my_arr* pv = new my_arr;
  pv->_a = new float[sz];
  pv->_sz = sz;
  return pv;
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
