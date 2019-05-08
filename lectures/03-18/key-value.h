#ifndef __KeyValue__
#define __KeyValue__

#include <iostream>
#include <string>

using namespace std;

template <typename U, typename V>
class KeyValue
{
  protected:
  U key;
  V value;

  public:
  KeyValue(const U& key, const V& value)
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
  
  const U& get_key() const { return key; }
  const V& get_value() const { return value; }

  void set_key(const U& key)
  {
    this->key = key;
  }
  void set_value(const V& value)
  {
    this->value = value;
  }

  bool operator==(const U& key) const
  {
    return this->key == key;
  }
  
  //friend functions must have their own 
  //takes an argument of type keyvalue
  template <typename A, typename B>
  friend ostream& operator<<(ostream& os, const KeyValue<A,B>& kv)
  {
    os << "(" << kv.key << ", " << kv.value << ")";
    return os;
  }  
};

#endif