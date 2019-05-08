#include "vec.h"
#include "math.h"

using namespace std;

vec::vec() 
{
  _data = 0;
  _sz = 0;
}

vec::vec(int sz)
{
  _sz = sz;
  _data = new double[_sz];
}

vec::vec(double* a, int sz)
{
  _sz = sz;
  _data = new double[_sz];

  for (int i=0; i<_sz; ++i) {
    _data[i] = a[i];
  }
}

vec::vec(const vec& o)
{
  _sz = o._sz;
  _data = new double[_sz];

  for (int i=0; i<_sz; ++i) {
    _data[i] = o._data[i];
  }
}

const vec& vec::operator=(const vec& o)
{
  if (_data) delete [] _data;

  _sz = o._sz;
  _data = new double[_sz];

  for (int i=0; i<_sz; ++i) {
    _data[i] = o._data[i];
  }

  return *this;
}

vec::~vec()
{
  if (_data) delete [] _data;
}

std::ostream& operator<<(std::ostream& stream, const vec& o) { 
  for (int i=0; i<o._sz; ++i) {
    stream << o._data[i] << " ";
  }
  return stream;
}

std::istream& operator>>(std::istream& stream, vec& o) { 
  for (int i=0; i<o._sz; ++i) {
    stream >> o._data[i];
  }
  return stream;
}

const double& vec::operator[](int i) const
{
  return _data[i];
}

double& vec::operator[](int i)
{
    return _data[i];
}

const double& vec::operator()(int i) const
{
    return _data[i];
}

double& vec::operator()(int i)
{
    return _data[i];
}

vec::operator int() const {
  return _sz;
}

// bool vec::operator==(const vec& o) const
// {
//   if (_sz != o._sz) return false;

//   for (int i=0; i<_sz; ++i) {
//     if (_data[i] != o._data[i]) {
//       return false;
//     }
//   } 

//   return true;
// }

bool operator==(const vec& o1, const vec& o2)
{
  if (o1._sz != o2._sz) return false;

  for (int i=0; i<o1._sz; ++i) {
    if (o1._data[i] != o2._data[i]) {
      return false;
    }
  } 

  return true;
}