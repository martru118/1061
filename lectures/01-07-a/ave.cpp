// Write a program that takes non-negative integers from user and computes
// their average.  The program exits when the user enters -1.

#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int num, sum=0, counter=0;
    int current_smaller;
    int all_the_numbers[100]; // PROBLEM ---> dynamic memory, dynamic array

    while(true) {
        cout << "Enter a number: ";
        cin >> num;
        if (num < 0) break;
        
        sum += num;
        all_the_numbers[counter] = num;
        counter++;

        if (counter > 1) {
            if (num < current_smaller) {
                current_smaller = num;
            }
        }
        else {
            current_smaller = num;
        }
    }

    cout << "Average is " << (sum/static_cast<double>(counter)) << endl;
    cout << "The smallest number is " << current_smaller << endl;

    for (int i=0; i<counter; ++i) {
        cout << all_the_numbers[i] << endl;
    }

    return 0;
}