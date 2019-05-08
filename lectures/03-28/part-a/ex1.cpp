#include <iostream>
#include <exception>

using namespace std;

int main()
{
  double numerator, denominator;

  cout << "Enter a number: ";
  cin >> numerator;

  try {
    cout << "Enter another number: ";
    cin >> denominator;

    if (denominator == 0) { throw denominator;  }
  }
  catch (double d) {
    cout << "Something bad is happening: " << d << endl;
    exit(-1);
  }
    
  double answer = numerator / denominator;
  cout << numerator << " divided by " << denominator << " is ";
  cout << answer << "." << endl; 
  
  return 0;
}
