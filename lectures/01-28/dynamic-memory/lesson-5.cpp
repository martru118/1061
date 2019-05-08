#include <iostream>

using namespace std;

struct vec {
  int* _data;
  size_t _sz;
};

void alloc_vec(vec& v, size_t sz)
{
  v._data = new int[sz];
  v._sz = sz;
}

void dealloc_vec(vec& v)
{
  delete [] v._data;
  v._data = 0;
}

void set_values(vec& v)
{
  for (int i=0; i<v._sz; ++i) {
    v._data[i] = rand();
  }
}

void prn_values(vec& v)
{
  for (int i=0; i<v._sz; ++i) {
    cout << v._data[i] << " ";
  }
  cout << endl;
}

int main(int argc, char** argv)
{
  if (argc != 2) {
    cerr << argv[0] << " <size>" << endl;
    return -1;
  }
  
  srand(0);
  
  size_t sz = atoi(argv[1]);

  vec v;
  alloc_vec(v, sz);
  set_values(v);
  cout << "v:" << endl;
  prn_values(v);

  vec v2;
  v2 = v;
  cout << "v2:" << endl;
  prn_values(v2);

  v2._data[3] = -1;
  cout << "v:" << endl;
  prn_values(v);
  cout << "v2:" << endl;
  prn_values(v2);

  dealloc_vec(v);
  cout << "v2:" << endl;
  prn_values(v2);
  v2._data[2] = 2;
  cout << "v2:" << endl;
  prn_values(v2);
  dealloc_vec(v2);
  
  return 0;
}
