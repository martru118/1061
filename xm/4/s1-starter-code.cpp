#include <iostream>
#include <vector>
#include <string>
// Add headers as needed
#include <algorithm>

using namespace std;

// Do not change the gen_random function function
string gen_random(int len)
{
  static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

  char* s = new char[len+1];
      
  for (int i = 0; i < len; ++i) {
    s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
  }
  s[len] = 0;

  string str(s);
  delete [] s;
  
  return str;
}

// Add function here if needed

void sort(vector<string>& v, bool order, int letter_position)
{
  string swap;   //used to swap indexes

  //order 0 means descending, order 1 means ascending
  if (order == 1) {
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (static_cast<int>(v[i][letter_position]) < static_cast<int>(v[j][letter_position])) {
          //swap the strings
          swap = v[i];
          v[i] = v[j];
          v[j] = swap;
        }
      }
    }

  } else {
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        if (static_cast<int>(v[i][letter_position]) > static_cast<int>(v[j][letter_position])) {
          //swap the strings
          swap = v[i];
          v[i] = v[j];
          v[j] = swap;
        }
      }
    }
  }
}

// Do not change the main function
int main()
{
  // Setting up data
  srand(0);
  vector<string> v;
  int len = 5;
  for (int i=0; i<5; ++i) {
    v.push_back(gen_random(len));
  }
  
  // Printing our data
  cout << "Checking data" << endl;
  typedef vector<string>::iterator Itr_v;
  for (Itr_v i = v.begin(); i != v.end(); ++i) {
    cout << "\t" << *i << endl;
  }

  // We assume that the letters starts at 0
  int letter_position = 0;
  bool order = true;
  cout << "Sorting using letter position: " << letter_position << endl;
  cout << "Order ascending: " << order << endl;
  sort(v, order, letter_position);
  typedef vector<string>::iterator Itr_v;
  for (Itr_v i = v.begin(); i != v.end(); ++i) {
    cout << "\t" << *i << endl;
  }

  order = false;
  cout << "Sorting using letter position: " << letter_position << endl;
  cout << "Order ascending: " << order << endl;
  sort(v, order, letter_position);
  typedef vector<string>::iterator Itr_v;
  for (Itr_v i = v.begin(); i != v.end(); ++i) {
    cout << "\t" << *i << endl;
  }

  // We assume that the letters starts at 0
  letter_position = 3;
  order = true;
  cout << "Sorting using letter position: " << letter_position << endl;
  cout << "Order ascending: " << order << endl;
  sort(v, order, letter_position);
  typedef vector<string>::iterator Itr_v;
  for (Itr_v i = v.begin(); i != v.end(); ++i) {
    cout << "\t" << *i << endl;
  }

  order = false;
  cout << "Sorting using letter position: " << letter_position << endl;
  cout << "Order ascending: " << order << endl;
  sort(v, order, letter_position);
  typedef vector<string>::iterator Itr_v;
  for (Itr_v i = v.begin(); i != v.end(); ++i) {
    cout << "\t" << *i << endl;
  }
  
  return 0;
}
