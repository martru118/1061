#include <iostream>
#include <vector>

using namespace std;

void prn(vector<int>& a)
{
    for (int i=0; i<a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<int> union1(vector<int>& a, vector<int>& b)
{
    // a = set 1, vector of integers
    // b = set 2, vector of integers
    // returns vector of integers

    vector<int> d;
        
    for (int i = 0; i < a.size(); i++) {
        d.push_back(a[i]);
    }

    for (int i = 0; i < a.size(); i++) {
        if (exist(a, b)) {
            continue;
        } else {
            d.push_back(b[i]);
        }
    }

    return d;
}

bool exist(vector<int> a, vector<int> b) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (a[i] == b[j]) {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> a;
    a.push_back(3); a.push_back(1); a.push_back(4); a.push_back(2);
    //a[3, 1, 4, 2]
    
    vector<int> b;
    b.push_back(5); b.push_back(1);
    //b[5, 1]

    vector<int> c = union1(a, b);

    cout << "a: "; prn(a);
    cout << "b: "; prn(b);
    cout << "c: "; prn(c);
    
    return 0;
}
