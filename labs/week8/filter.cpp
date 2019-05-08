#include <iostream>
using namespace std;

class Filter  //base class
{
  protected:
    string _name;

  public:  
    Filter(const string& name) : _name(name) {}
    virtual ~Filter() {};

    virtual string apply(const string& input) = 0;

    string get_name() { return _name; }
};

class Capitalize: public Filter
{
  public:
  Capitalize(): Filter("Capitalize") {}
  ~Capitalize() override = default;

  string apply(const string& input) {
    string output = "";

    for (int a = 0; a < input.size(); a++) {
      //check for lowercase letters
      if (islower(input[a])) {
        output += toupper(input[a]);
      
      //insert non-lowercase words
      } else {
        output += input[a];
      }
    }

    return output;
  }
};

class CapitalizeFirstLetter: public Filter
{
  public:
  CapitalizeFirstLetter(): Filter("CapitalizeFirstLetter") {}
  ~CapitalizeFirstLetter() override = default;

  string apply(const string& input) {
    string output = input;  //make input modifiable

    if (islower(output[0])) {
      //make very first letter capitalized
      output[0] = toupper(input[0]);
    }
    return output;
  }
};

class CapitalizeFirstLetterOfEveryWord: public Filter
{
  public:
  CapitalizeFirstLetterOfEveryWord(): Filter("CapitalizeFirstLetterOfEveryWord") {}
  ~CapitalizeFirstLetterOfEveryWord() override = default;

  string apply(const string& input) {
    string output = input;

    for (int a = 0; a < input.size(); a++) {
      //capitalize very first letter
      output[0] = toupper(input[0]);

      //apply capitalization to any other words
      if (output[a] == ' ' && islower(output[a+1])) {
        output[a+1] = toupper(input[a+1]);
      }
    }
    return output;
  }
};

class Obenglobish: public Filter
{
  public:
  Obenglobish(): Filter("Obenglobish") {}
  ~Obenglobish() override = default;

  string apply(const string& input) {
    string output = "";
    const string ob = "ob";

    for (int a = 0; a < input.size(); a++) {
      //check for vowels
      if (tolower(input[a]) == 'a') {
        output += ob + input[a];
      } else if (tolower(input[a]) == 'e') {
        output += ob + input[a];
      } else if (tolower(input[a]) == 'i') {
        output += ob + input[a];
      } else if (tolower(input[a]) == 'o') {
        output += ob + input[a];
      } else if (tolower(input[a]) == 'u') {
        output += ob + input[a];

      //insert remaining consonants
      } else {
        output += input[a];
      }
    }
    return output;
  }
};

class ReverseString: public Filter
{
  public:
  ReverseString(): Filter("ReverseString") {}
  ~ReverseString() override = default;

  string apply(const string& input) {
    string output = "";

    //insert strings starting from the back of the string
    for (int a = input.size()-1; a >= 0; a--) {
      output += input[a];
    }
    return output;
  }
};

class ToSmall: public Filter
{
  public:
  ToSmall(): Filter("ToSmall") {}
  ~ToSmall() override = default;

  string apply(const string& input) {
    string output = "";

    for (int a = 0; a < input.size(); a++) {
      //check for uppercase letters
      if (isupper(input[a])) {
        output += tolower(input[a]);
      } else {
        output += input[a];
      }
    }
    return output;
  }
};

class Randomize: public Filter
{
  public:
  Randomize(): Filter("Randomize") {}
  ~Randomize() override = default;

  string apply(const string& input) {
    srand(time(NULL));
    string output = "";

    //arrange characters in a random order
    for (int a = 0; a < input.size(); a++) {
      output += input[rand() % input.size()];
    }
    return output;
  }
};

int main()
{
  const int num_filters = 7;
  Filter* filters[num_filters];

  filters[0] = new Capitalize();
  filters[1] = new CapitalizeFirstLetter();
  filters[2] = new CapitalizeFirstLetterOfEveryWord();
  filters[3] = new Obenglobish();
  filters[4] = new ReverseString();
  filters[5] = new ToSmall();
  filters[6] = new Randomize();
    
  string input;
  cout << "Enter string: ";  getline(cin, input);

  cout << "Input string: " << input << endl;
  for (int i=0; i<num_filters; ++i) {
    cout << "Filter name:  " << filters[i]->get_name() << endl;
    cout << "Output:       " << filters[i]->apply(input) << endl; 
  }

  for (int i=0; i<num_filters; ++i) delete filters[i];
}
