#include <iostream>

using namespace std;

float gen_rand()
{
  return  static_cast<float>(rand()) / RAND_MAX;
}

void prn(float* a, int sz)
{
  for (int i=0; i<sz; ++i) {
    cout << a[i] << " ";
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
  
  float* a = new float[sz]; // allocating dynamic memory
  for (int i=0; i<sz; ++i) {
    a[i] = gen_rand();
  }
  prn(a, sz);
  
  delete [] a; // de-allocate

  return 0;
}
