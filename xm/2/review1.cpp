//Midterm Exam 2 -- Review
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

void strcopy(char* s, char* d) {
    char* p = s;
    char* q = d;

    while (*p) {
        *(q++) = *(p++);
    }

    q = 0;
}

void revstrcopy(char* s, char* d) {
    char rev;
    int j = strlen(s) - 1;
    
    for (int i = 0; i < j; i++, j--) {
        rev = s[i];
        s[i] = s[j];
        s[j] = rev;
    }

    for (int i = 0; i < 12; i++) {
        d[i] = rev;
    }

}

int main() 
{
    char s[] = "Hello world";
    char d[12];
    revstrcopy(s, d);

    cout << d << endl;
}
