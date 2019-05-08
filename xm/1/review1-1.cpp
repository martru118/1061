#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Question 4
int main() 
{
    ifstream f("words.txt");    //open file for reading
    if (!f.is_open()) {
        cout << "Cannot open file 'words.txt'" << endl;
    } else {

        //read each line of the file
        string line;
        while (getline(f, line)) {
            cout << line << endl;
        }
    }

    f.close();  //close the file
    
    return 0;
}