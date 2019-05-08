#include <iostream>
#include <cstring>

char find(char s[], int lens, char q[], int lenq)
{
  // s - string
  // lens - length of string s
  // q - query string
  // lenq - length of string q
  // return index at which query string is found 
  //       within string s, or -1 (if not found)

  char toFind[lenq] = {};

  for (int i = 0; i < lenq; i++) {
    toFind[i] = q[i];
  }

  for (int i = 0; i < lens; i++) {
    if (isalpha(s[i])) {
      
    }
  }

//split the query into letters
//see if the letters are in the string

}

int main()
{
  char s[] = "Its a beautiful world.";
  char q1[] = "world";
  char q2[] = "exam";

  std::cout << "Str:      " << s << std::endl;
  std::cout << "Query:    " << q1 << std::endl;
  std::cout << "Found at: " << find(s,strlen(s),q1,strlen(q1)) << std::endl;

  std::cout << "Str:      " << s << std::endl;
  std::cout << "Query:    " << q2 << std::endl;
  std::cout << "Found at: " << find(s,strlen(s),q2,strlen(q2)) << std::endl;
}
