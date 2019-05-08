// filename = q1.cpp 
#include <iostream>
#include <fstream> 
#include <vector> 
using namespace std; 

void print_arr(const vector<int>& a) {
    vector<int>::const_iterator i;

    for (i = a.begin(); i != a.end(); ++i)
        cout << *i << ' ';

    cout << endl;
}

vector<int> read_arr(int termination)
{
    ifstream f("data.txt");
    int from_arr;   //current number in file
    vector<int> v;

    while(f >> from_arr) {
        if (from_arr == termination) {
            break;
        } else {
            v.push_back(from_arr);
        }
    }

    return v;
}

void inplace_rev_arr(vector<int>& a)
{
    vector<int>::reverse_iterator i;
    for (i = a.rbegin(); i != a.rend(); ++i) {
        cout << *i << ' ';
    }
    
    cout << endl;
}

int main()
{
    vector<int> a = read_arr(-1);

    print_arr(a);
    inplace_rev_arr(a);
    print_arr(a);

return 0;
}
