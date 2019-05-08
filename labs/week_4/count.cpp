#include <iostream>

using namespace std;

void count(char* arr, int n, int* counts) {
    for (int i = 0; i < n; i++) {
        //first occurance of the character
        if (counts[i] == 0) {
            counts[i] = 1;

        for (int j = i+1; j < n; j++) {
            //for duplicates only
            if (arr[i] == arr[j]) {
                counts[i] += 1;
                counts[j] += 1;
            }
        }

        //display counts of each character
        cout << arr[i] << ": " << counts[i] << endl;
        }
    }
}
