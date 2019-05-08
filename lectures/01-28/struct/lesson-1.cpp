#include <iostream>

using namespace std;

struct car {
  int _cylinders;
  int _cc;
  bool _turbo;
};

void prn_car(car& c)
{
  cout << "Cylinders = " << c._cylinders << endl;
  cout << "CC = " << c._cc << endl;
  cout << "Turbo = " << boolalpha << c._turbo << noboolalpha << endl;
}


int main()
{
  car c;
  c._cc = 185;
  c._cylinders = 4;
  c._turbo = true;

  // This won't work
  // cout << "c = " << c << endl;

  // But this would
  prn_car(c);
  
  return 0;
}
