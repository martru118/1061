// filename = q2.cpp
#include <iostream>

void print_checker_pattern(int height, int width);

int main()
{
    using std::cout;
    using std::cin;

    int height, width;
    cout << "Enter height: "; cin >> height;
    cout << "Enter width: "; cin >> width;

    print_checker_pattern(height, width);

return 0;
}

void print_checker_pattern(int height, int width)
{
    using std::cout;
    using std::string;
    using std::endl;

    string pattern = "";
    string tile = "W_";

    //display pattern
    for (int t = 0; t < height*width; ++t) {
        pattern += tile;
        cout << pattern[t];

        //format pattern
        if ((t+1) % width == 0) {
            cout << endl;
        }
    }
}