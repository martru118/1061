#include <iostream>

class Mat3 {
protected:
  double _data[3][3];
  
public:
  Mat3();
  Mat3(double* a);
  Mat3(const Mat3& o);
  ~Mat3();
  
public:
  const Mat3& operator=(const Mat3& o);
  friend std::ostream& operator<<(std::ostream& stream, const Mat3& o);
  friend std::istream& operator>>(std::istream& stream, Mat3& o);

public:
  // bool operator==(const Mat3& o) const;
  friend bool operator==(const Mat3& o1, const Mat3& o2);

public:
  const double& operator()(int i, int j) const;
  double& operator()(int i, int j);

  operator int() const;
};
