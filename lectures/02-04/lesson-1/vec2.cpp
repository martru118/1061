#include "vec2.h"
#include "math.h"

using namespace std;

vec2::vec2() : x(0.0), y(0.0) // This is called the initializer-list.
                              // We can use it to initialize the member data.
{}

vec2::vec2(double c)
{
  this->x = c;
  this->y = c;
}

vec2::vec2(double x, double y)
{
  this->x = x;
  this->y = y;
}

vec2::vec2(const vec2& o) // The copy constructor.
                          // const keyword indicates that
                          // we are not allowed to modify the 
                          // passed reference, which makes sense
                          // it is unwise to modify o when copying it.
{
  x = o.x;
  y = o.y;
}

vec2::~vec2() // This is called when an instance is destroyed
              // 1. Goes out of scope
              // 2. delete is called (in case of dynamic allocations)
{}

vec2& vec2::operator=(const vec2& o) // The assignment operator.
                                     // const keyword indicates that
                                     // we are not allowed to modify the 
                                     // passed reference, which makes sense
                                     // it is unwise to modify o when copying it.
{
  x = o.x;
  y = o.y;
  return *this;     // this is a pointer that points to this instance of vec2.
                    // here, we are return a reference, so we need an object.
                    // we use the de-reference operator * to do so.
}

double vec2::length()
{
  return sqrt(x*x + y*y);
}
