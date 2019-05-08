#ifndef __KeyValueTmpl__
#define __KeyValueTmpl__

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
    cout << "Foo" << key << endl;
    return this->key == key;
  }

  template <typename A, typename B>
  friend ostream& operator<<(ostream& os, const KeyValue<A,B>& kv);
};

template <typename U, typename V>
ostream& operator<<(ostream& os, const KeyValue<U,V>& kv)
{
  os << "(" << kv.key << ", " << kv.value << ")";
  return os;
}  


#endif
