//Seizure Cipher —— PART 3
#include <iostream>
#include <fstream>

using namespace std; 

/*
$ ./cf -e 3 < f1.txt > f2.txt
$ cat f1.txt | ./cf -e 3 > f2.txt
*/
string encrypt(string text, int shift) 
{ 
	string ciphertext = "";
    int ascii;  //decimal value of char after shift

    //65 is ascii for 'A'
    //90 is ascii for 'Z'

    //assume the input is always uppercase
	for (int a = 0; a < text.length(); a++) {
        if (isupper(text[a])) {
            ascii = int(text[a]) + shift;
            if (ascii < 65) {
                //wrap backwards from A to Z
                ciphertext += char(91 - (65 - ascii));
            } else if (ascii > 90) {
                //wrap forwards from Z to A
                ciphertext += char(64 + (ascii - 90));
            } else {
                //character is between A to Z
                ciphertext += char(ascii);
            }

        //for spaces and punctuation
        } else {
            ciphertext += text[a];
        }
	}

	return ciphertext; 
} 

/*
$ ./cf -d 3 < f2.txt > f3.txt
$ cat f2.txt | ./cf -d 3 > f3.txt
*/
string decrypt(string text, int shift) 
{
    string plaintext = "";
    int revert = 26 - shift;   //resets shift

    //undo encryption
	for (int a = 0; a < text.length(); a++) {
        if (isupper(text[a])) {
            //calculate the ascii value of the encrypted character
            plaintext += char(int(text[a] + revert - 65)%26 + 65);
        
        //for unencrypted characters
        } else {
            plaintext += text[a];
        }
	}

    return plaintext;
}

int main(int argc, char const *argv[]) 
{ 
    string sentence;

    //Enter plaintext message
    if (argv[1][1] == 'e') {
        ifstream f("in.txt");

        if (!f.is_open()) {
            cerr << "Cannot open file...\n";
        } else {
            while (getline(f, sentence)) {
                cout << encrypt(sentence, atoi(argv[2]));
            }
        }

        f.close();
    } else if (argv[1][1] == 'd') {
        ifstream f("encrypted.txt");

        if (!f.is_open()) {
            cerr << "Cannot open file...\n";
        } else {
            while (getline(f, sentence)) {
                cout << decrypt(sentence, atoi(argv[2]));
            }
        }

        f.close();
    }
	
    return 0; 
}
