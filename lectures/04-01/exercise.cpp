#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::ostream;

//make an iterator for this class
class Arr
{
    protected:
    double m[10];

    public:
    Arr() {
        for (int i=0; i<10; ++i) m[i] = (rand() % 101);
    }

    double& operator[](int i) { return m[i]; }
    const double& operator[](int i) const { return m[i]; }

    friend ostream& operator<<(ostream& os, const Arr& a)
    {
        for (int i=0; i<10; ++i) os << a[i] << " ";
        return os;
    }
};

namespace student {
    class Arr {
        protected:
        double* m;
        int len;

        public:
    

        Arr(int len) {
            this->len = len;
            m = new double[len];
            for (int i=0; i<len; ++i) m[i] = (rand() % 101);
        }
        ~Arr() { delete[] m; }

        double& operator[](int i) { return m[i]; }
        const double& operator[](int i) const { return m[i]; }

        friend ostream& operator<<(ostream& os, const Arr& a)
        {
            for (int i=0; i<a.len; ++i) os << a[i] << " ";
            return os;
        }
    };
}

int main()
{
    srand(0);

    student::Arr a(10);
    a[0] = 1;
    a[3] = 9;
    cout << a << endl;

    vector<double> v;
    for (int i=0; i<10; ++i) {
    v.push_back(a[i]);
    }
    for (vector<double>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(), [](double a, double b)->bool{return a > b;});
    for (vector<double>::iterator i = v.begin(); i != v.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;



    return 0;
}