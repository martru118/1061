#ifndef __vec3_int_h__
#define __vec3_int_h__

#include <iostream>
using namespace std;

class vec3_int
{
  protected:
  int data[3];

  public:
  vec3_int() {}

  vec3_int(int x, int y, int z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
  }

  vec3_int(const vec3_int& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
  }

  const vec3_int& operator=(const vec3_int& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
    return *this;
  }
  
  int& operator[](int i) { return data[i]; }
  const int& operator[](int i) const { return data[i]; }

  void print();  

  friend int find_max(const vec3_int& v);
};

void vec3_int::print()
{
  cout << "(" << data[0] << "," << data[1] << "," << data[2] << ")" << endl;
}

int find_max(const vec3_int& v)
{
    int m = v[0];
    if (m < v[1]) m = v[1];
    if (m < v[2]) m = v[2];
    return m;
}

#endif
