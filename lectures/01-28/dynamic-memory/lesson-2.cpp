#include <iostream>

using namespace std;

struct my_arr {
  float* _a;
  int _sz;
};

float gen_rand()
{
  return  static_cast<float>(rand()) / RAND_MAX;
}

void prn(my_arr& v)
{
  for (int i=0; i<v._sz; ++i) {
    cout << v._a[i] << " ";
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    cerr << argv[0] << " <size of array>" << endl;
    return -1;
  }

  int sz = atoi(argv[1]);
  if (sz < 1) {
    cerr << "size of array must be greater than 0" << endl;
    return -2;
  }

  srand(0);

  my_arr v;
  v._a = new float[sz];
  v._sz = sz;
  cout << "Size of v is " << sizeof(v) << endl;  
  cout << sizeof(int) << endl;
  cout << sizeof(float*) << endl;

  for (int i=0; i<v._sz; ++i) {
    v._a[i] = gen_rand();
  }
  prn(v);
  
  delete [] v._a;

  return 0;
}
