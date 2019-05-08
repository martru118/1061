#include "str.h"

str::str() : _n(0), _buf(0)
{}

str::str(int n) : _n(n)
{
  _buf = new char[_n];
}

str::str(char ch) : _n(1)
{
  _buf = new char[_n];
  _buf[0] = ch;
}

str::str(const char* c_str)
{
  _n = strlen(c_str);
  _buf = new char[_n];
  for (int i=0; i<_n; ++i) _buf[i]=c_str[i];
}

str::~str()
{
  if (_buf) delete[] _buf;
}

ostream& operator<<(ostream& os, const str& s)
{
  if (!s.is_empty()) {
    for (int i=0; i<s.length(); ++i) {
      cout << s[i];
    }
  }
  else cout << "[null str]";
  
  return os;
}

istream& operator>>(istream& is, str& s)
{
  char ch;
  do {
    ch = is.get();
    if (ch == ' ' || ch == '\n') break;
    s = s + ch;
  } while(true);

  return is;
}

//assignment operator
const str& str::operator=(const str& s)
{
  str *equals;
  strcpy(equals->_buf, _buf);
  strcat(equals->_buf, s._buf);
  return *equals;
}

//concatenation operator for two strings
str operator+(const str& a, const str& b)
{
  str cat;
  cat._n = a._n + b._n;
  delete cat._buf;

  cat._buf = new char[cat._n];
  strcpy(cat._buf,a._buf);
  strcat(cat._buf,b._buf);

  return cat;
}
