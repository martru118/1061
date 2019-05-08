#ifndef __KeyValue__
#define __KeyValue__

#include <iostream>
#include <string>

using namespace std;

class KeyValue
{
  protected:
  string key;
  int value;

  public:
  KeyValue(const string& key, const int& value)
  {
      this->key = key;
      this->value = value;
  }

  KeyValue(const KeyValue& kv)
  {
    key = kv.key;
    value = kv.value;
  }

  KeyValue& operator=(const KeyValue& kv)
  {
    key = kv.key;
    value = kv.value;
    return *this;
  }
  
  const string& get_key() const { return key; }
  const int& get_value() const { return value; }

  void set_key(const string& key)
  {
    this->key = key;
  }
  void set_value(const int& value)
  {
    this->value = value;
  }

  bool operator==(const string& key) const
  {
    return this->key == key;
  }
  
  friend ostream& operator<<(ostream& os, const KeyValue& kv)
  {
    os << "(" << kv.key << ", " << kv.value << ")";
    return os;
  }  
};

#endif
