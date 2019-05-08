#include <vector>
#include "key-value.h"

int main()
{
  vector<KeyValue> v;
  v.push_back(KeyValue("Bob", 32));
  v.push_back(KeyValue("Dan", 34));
  v.push_back(KeyValue("Jane", 42));

  for (vector<KeyValue>::iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << endl;
  }

  cout << "Enter name: ";
  string query;
  cin >> query;
  vector<KeyValue>::iterator i;
  for (i = v.begin(); i != v.end(); ++i) {
    if (*i == query) break;
  }
  if (i != v.end()) {
    cout << "Record found: " << *i << endl;
  }
  else {
    cout << "No matching record found" << endl;
  }
  
  return 0;
}