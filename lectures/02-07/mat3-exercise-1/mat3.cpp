#include "mat3.h"
#include "math.h"

using namespace std;

Mat3::Mat3() 
{
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      if (i == j) { _data[i][j] = 1.0; }
      else { _data[i][j] = 0.0; }
    }
  }
}

Mat3::Mat3(double* a)
{
  int k = 0;
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      _data[i][j] = a[k++];
    }
  }
}

Mat3::Mat3(const Mat3& o)
{
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      _data[i][j] = o._data[i][j];
    }
  }
}

const Mat3& Mat3::operator=(const Mat3& o)
{
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      _data[i][j] = o._data[i][j];
    }
  }

  return *this;
}

Mat3::~Mat3()
{
}

std::ostream& operator<<(std::ostream& stream, const Mat3& o) { 
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      stream << _data[i][j] << " ";
    }
    stream << endl;
  }

  return stream;
}

std::istream& operator>>(std::istream& stream, Mat3& o) { 
  for (int i=0; i<3; ++i) {
    for (int j=0; j<3; ++j) {
      stream >> _data[i][j];
    }
  }

  return stream;
}

const double& Mat3::operator()(int i, int j) const
{
    return _data[i][j];
}

double& Mat3::operator()(int i, int j)
{
    return _data[i][j];
}

Mat3::operator int() const {
  return _sz;
}

// bool Mat3::operator==(const Mat3& o) const
// {
//   if (_sz != o._sz) return false;

//   for (int i=0; i<_sz; ++i) {
//     if (_data[i] != o._data[i]) {
//       return false;
//     }
//   } 

//   return true;
// }

bool operator==(const Mat3& o1, const Mat3& o2)
{
  if (o1._sz != o2._sz) return false;

  for (int i=0; i<o1._sz; ++i) {
    if (o1._data[i] != o2._data[i]) {
      return false;
    }
  } 

  return true;
}