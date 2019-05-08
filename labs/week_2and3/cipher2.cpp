//Seizure Cipher —— PART 2
#include <iostream>
#include <fstream>

using namespace std; 

//$ ./cf -e 3 f1.txt f2.txt
string encrypt(string text, int shift, string filename) 
{ 
    ofstream e(filename, ios::app);
    int ascii;  //decimal value of char after shift

    //65 is ascii for 'A'
    //90 is ascii for 'Z'

    if (!e.is_open()) {
        return "Cannot open file...\n";
    } else {
        //assume the input is always uppercase
        for (int a = 0; a < text.length(); a++) {
            if (isupper(text[a])) {
                ascii = int(text[a]) + shift;
                if (ascii < 65) {
                    //wrap backwards from A to Z
                    e << char(91 - (65 - ascii));
                } else if (ascii > 90) {
                    //wrap forwards from Z to A
                    e << char(64 + (ascii - 90));
                } else {
                    //character is between A to Z
                    e << char(ascii);
                }

            //for spaces and punctuation
            } else {
                e << text[a];
            }
        }
    }

    e.close();
} 

//$ ./cf -d 3 f2.txt f3.txt
string decrypt(string text, int shift, string filename) 
{
    ofstream d(filename, ios::app);
    int revert = 26 - shift;   //resets shift

    if (!d.is_open()) {
        return "Cannot open file...";
    } else {
        //undo encryption
        for (int a = 0; a < text.length(); a++) {
            if (isupper(text[a])) {
                //calculate the ascii value of the encrypted character
                d << char(int(text[a] + revert - 65)%26 + 65);
            
            //for unencrypted characters
            } else {
                d << text[a];
            }
        }
    }

    d.close();
}

int main(int argc, char const *argv[])
{
    ifstream f(argv[3]);   //open file for reading
    string sentence;

    //encrypt file
    if (!f.is_open()) {
        cerr << "Cannot open file...\n";

    } else {
        while (getline(f, sentence)) {
            if (argv[1][1] == 'e') {
                encrypt(sentence, atoi(argv[2]), argv[4]);
            } else if (argv[1][1] == 'd') {
                decrypt(sentence, atoi(argv[2]), argv[4]);
            }
        }
    }

    f.close();

    return 0;
}
