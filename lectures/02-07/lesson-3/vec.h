#include <iostream>

class vec {
protected:
  double* _data;
  int _sz;
  
public:
  vec();
  vec(int sz);
  vec(double* a, int sz);
  vec(const vec& o);
  ~vec();
  
public:
  const vec& operator=(const vec& o);
  friend std::ostream& operator<<(std::ostream& stream, const vec& o);
  friend std::istream& operator>>(std::istream& stream, vec& o);

public:
  // bool operator==(const vec& o) const;
  friend bool operator==(const vec& o1, const vec& o2);

public:
  const double& operator[](int i) const;
  double& operator[](int i);

  const double& operator()(int i) const;
  double& operator()(int i);

  operator int() const;
};
