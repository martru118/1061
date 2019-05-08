// filename = q1.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> read_arr_s(const string& termination)
{
    ifstream f("words.txt");
    string from_arr;
    vector<string> s;

    while(f >> from_arr) {
        if (from_arr == "END" || from_arr == "end") {
            break;
        } else {
            s.push_back(from_arr);
        }
    }

    return s;
}

void draw_top_justified(const vector<string>& a)
{
    cout << "Top justified: " << endl;
    string justified = "";

    for (int i = 0; i != a.size(); ++i) {
        for (int j = 0; j < a[i].length(); ++j) {
            justified += a[j][i];
        }

        cout << justified << endl;
    }
    
}

void draw_bottom_justified(const vector<string>& a)
{
    cout << "Bottom justified: " << endl;

    vector<string>::const_iterator i;

}

int main()
{
    vector<string> a = read_arr_s("END");

    draw_top_justified(a);
    //draw_bottom_justified(a);
    return 0;
}
