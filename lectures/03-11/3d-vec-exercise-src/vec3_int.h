#ifndef __vec3_int_h__
#define __vec3_int_h__

#include <iostream>
using namespace std;

class vec3
{
  protected:
  int data[3];

  public:
  vec3() {}

  vec3(int x, int y, int z) {
    data[0] = x;
    data[1] = y;
    data[2] = z;
  }

  vec3(const vec3& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
  }

  const vec3& operator=(const vec3& v)
  {
    for (int i=0; i<3; ++i) {
      data[i] = v[i];
    }
    return *this;
  }
  
  int& operator[](int i) { return data[i]; }
  const int& operator[](int i) const { return data[i]; }

  void print();

  friend int find_max(const vec3& v);
};

void vec3::print()
{
  cout << "(" << data[0] << "," << data[1] << "," << data[2] << ")" << endl;
}

int find_max(const vec3& v)
{
    int m = v[0];
    if (m < v[1]) m = v[1];
    if (m < v[2]) m = v[2];
    return m;
}

#endif