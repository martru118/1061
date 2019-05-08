#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//find where the letters begin
int startOfWord(const string& substring)
{
  for (int i = 1; i < substring.size(); ++i) {
    if (isalnum(substring[i])) {
      return i;
      break;
    }
  }
}

//verify that the words match
bool bothMatch(const string& word, const string& compare)
{
  bool found = true;
  int firststr = startOfWord(word);

  //check the characters of both words
  for (int a = 0; a < compare.size(); ++a) {
    //symbols at the end
    if (isalnum(word[0])) {
      if ((word[a] != compare[a])) {
        found = false;
      }
    
    //symbols at the beginning
    } else {
      if (word[a+firststr] != compare[a]) {
        found = false;
      }
    }
  }

  return found;
}

int main(int argc, char const *argv[])
{
  ifstream f(argv[1]);
  string current;  //current word in the file
  int occurance = 0; //number of times a word appears

  //error handling
  if (!f.is_open() || argc < 3) {
    cerr << "Cannot open file..." << endl;

  //search for phrase
  } else {
    cout << "Reading " << argv[1] << "\n" << endl;

    //match text with input
    while (f >> current) {
      if (bothMatch(current, argv[2])) {
        occurance += 1;
      }
    }
  
    cout << "'" << argv[2] << "' was found " << occurance << " times." << endl;
  }

  f.close();

  return 0;
}
