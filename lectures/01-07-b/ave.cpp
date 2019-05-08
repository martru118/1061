// Write a program that computes average of non-negative 
// integers entered by a user.
// The programs breaks when user enters a -1.
//
// Find the smallest value greater than -1 entered by the
// user.

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  int num, sum=0, counter=0, current_smallest=2147483647;
 
  while(true) {
    cout << "Enter a number: ";
    cin >> num;

    if (num >= 0) {
      sum += num; // sum = sum + num;
      ++counter;  // counter = counter + 1
    }
    else break;

    // Will this ever work?
    if (num < current_smallest) {
      current_smallest = num;
    }

    #if 0
    //Andrew
    if (current_smallest == -1) current_smallest = num;
    else {
      if (num < current_smallest) {
        current_smallest = num;
      }
    }

    //Ian
    if (counter == 1) current_smallest = num;
    else {
      if (num < current_smallest) {
        current_smallest = num;
      }
    }
    #endif
    
  }
  
  cout << "sum = " << sum << endl;
  cout << "counter = " << counter << endl;
  cout << "ave = " << sum / static_cast<double>(counter) << endl;
  cout << "smallest = " << current_smallest << endl;
  
  return 0;
}
