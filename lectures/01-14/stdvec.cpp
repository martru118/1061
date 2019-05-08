#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    // cout << "argc = " << argc << endl;
    // for (int i=0; i<argc; ++i) {
    //     cout << argv[i] << endl;
    // }

    if (argc < 2) return -1;
    else {
        cout << "Hello " << argv[1] << endl;
    }


    // int a[3]; // array of type int
    // // access the elements of a using [] operator
    // // elements are indexed between 0 and N. E.g., 0, 1, 2
    // a[0] = 3;
    // cout << "array:" << endl;
    // for (int i=0; i<3; ++i) {
    //     cout << a[i] << endl;
    // }

    // cout << "vector:" << endl;
    // vector<int> v; // vector of type int
    // v.resize(3);

    // v[0] = 3;
    // v[1] = 4;
    // v[2] = 10; 

    // // for (int i=0; i<10000; ++i) {
    // //     cout << v.size() <<  " " << v.capacity() << endl;
    // //     v.push_back(i);
    // // }

    // // //v.reserve(100);
    // // cout << "size = " << v.size() << endl;
    // // cout << "capacity = " << v.capacity() << endl;

    // // v.push_back(1);
    // // cout << "size after 1 = " << v.size() << endl;
    // // cout << "capacity after 1 = " << v.capacity() << endl;

    // // v.push_back(11);
    // // cout << "size after 11 = " << v.size() << endl;
    // // cout << "capacity after 11 = " << v.capacity() << endl;

    // // v.push_back(122);
    // // cout << "size after 122 = " << v.size() << endl;
    // // cout << "capacity after 122 = " << v.capacity() << endl;

    // // v.push_back(-23);
    // // cout << "size after -23 = " << v.size() << endl;
    // // cout << "capacity after -23 = " << v.capacity() << endl;

    // for (int i=0; i<v.size(); ++i) {
    //     cout << v[i] << endl;
    // }

    return 0;
}