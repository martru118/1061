#include <iostream>
#include <fstream>

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

void save_text(const char* filename, car& c)
{
  ofstream ftext(filename);
  ftext << c._cylinders << endl;
  ftext << c._cc << endl;
  ftext << c._turbo << endl;
  ftext.close();
}

void load_text(const char* filename, car& c)
{
  ifstream ftext(filename);
  ftext >> c._cylinders;
  ftext >> c._cc;
  ftext >> c._turbo;
  ftext.close();
}

void save_binary(const char* filename, car& c)
{
  // static_cast won't work.  try.

  ofstream fbin(filename, ios::binary);
  fbin.write(reinterpret_cast<char*>(&c), sizeof(c) /*12 for us*/);
  fbin.close();
}

void load_binary(const char* filename, car& c)
{
  // static_cast won't work.  try.

  ifstream fbin(filename, ios::binary);
  fbin.read((char*)&c, sizeof(c));
  fbin.close();
}

int main()
{
  car c;
  c._cc = 185;
  c._cylinders = 4;
  c._turbo = true;
  cout << "c:" << endl;
  prn_car(c);

  // Notice that memory is rounded to the nearest multiple of 4
  // for the sake of efficiency.
  cout << "\nAmount of memory c takes = " << sizeof(c) << endl;
  
  save_text("car.txt", c);
  car c1;
  load_text("car.txt", c1);
  cout << "\nc1:" << endl;
  prn_car(c1);

  save_binary("car.bin", c);
  car c2;
  load_binary("car.bin", c2);
  cout << "\nc2:" << endl;
  prn_car(c2);
  
  return 0;
}
