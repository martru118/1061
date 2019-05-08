#include "vec2.h"
#include "math.h"

using namespace std;

vec2::vec2() : x(0.0), y(0.0)
{
}

vec2::vec2(double c)
{
  x = c;
  y = c;
}

vec2::vec2(double x, double y)
{
  this->x = x; // Using this pointer to differentiate
  this->y = y; // between members x and y and
               // function arguments x and y.
}

vec2::vec2(const vec2& o)
{
  x = o.x;
  y = o.y;
}

vec2::~vec2()
{}

double vec2::length2() const
{
  return x*x + y*y;
}

double length2(const vec2& v)
{
  return v.x*v.x + v.y*v.y;
}
