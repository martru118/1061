#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "count.h"

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting." << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  if (n < 10 || n > 10000) {
    cerr << "Usage: " << argv[0] << " <count>" << endl;
    cerr << "\t<count> is an integer between 10 and 10000\n";
    cerr << "\tExiting.";
    return -2;
  }

  srand(time(NULL));

  char* arr = new char[n];    //array to store characters
  int* counts = new int[n];   //array to store counts

  for (int i=0; i<n; ++i) {
    //generate random uppercase letters from A - Z
    arr[i] = char(rand() % (90 - 65 + 1) + 65);
  }

  for (int i=0; i<n; ++i) {
    cout << arr[i] << ' ';
  }
  cout << endl;

  //count the occurances of each character
  count(arr, n, counts);

  delete[] arr;
  delete[] counts;

  return 0;
}
