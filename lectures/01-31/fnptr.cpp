#include <iostream>
using std::cout; 
using std::endl;

int negate(int x)
{
	return -x;
}


int square(int x)
{
	return x*x;
}

int main(int argc, char** argv)
{

  int (*b)(int, char**);

  int (*a)(int); // a variable to store a function pointer

  a = &negate; // or a = square; the `&` is optional
  cout << a(9) << endl;
        
  return 0;
}
