//Seizure Cipher —— PART 1
#include <iostream>

using namespace std; 

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

int main() 
{ 
	int shift;
    string message;

    cout << "Enter plaintext message: ";
    getline(cin, message);
    cout << "Enter shift +/- 26: ";
    cin >> shift;

    //resulting text
    string caesar = encrypt(message, shift);
    string plain = decrypt(caesar, shift);

    cout << "Ciphertext: " << caesar << endl;   //display encrypted text
    cout << "Plaintext: " << plain << endl;     //display decrypted text
	
    return 0; 
}
