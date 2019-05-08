#include <iostream>
#include <vector>
using namespace std;

int main()
{
  double accum = 0.0;
  vector<int> v;
  double num;
  char c;
    
  do {

    cout << "Enter a number (. to exit): ";
    cin >> c;
    if (c != '.') {
      cin.putback(c);

      cin >> num;
      accum = accum + num;
      v.push_back(-num);
    }
    else {
      break;
    }
      
  } while (true);

  cout << endl <<  "Items stored: " << v.size() << endl;

  for (int i=0; i<v.size(); ++i) {
    cout << "Item at " << i << " is " << v[i] << endl;
  }
  
  return 0;
}




