#include <iostream>
using std::cout; 
using std::endl;

int make_zero(int x)
{
	return 0;
}


int square(int x)
{
	return x*x;
}

int neg(int x)
{
  return -x;
}

int do_some_process(int x, int (*process)(int))
{ 
  return process(x);
}

int main()
{
  cout << do_some_process(2, square) << endl;
  cout << do_some_process(2, neg) << endl;
  return 0;
}

//void glutMouseFunc(void (*func)(int button, int state, int x, int y));
