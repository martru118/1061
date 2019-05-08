#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
    public:
    int x;
    int y;

    public:
    Item() {
        x = rand() % 10;
        y = rand() % 10;
    }

    friend ostream& operator<<(ostream& os, const Item& i) {
        os << i.x << ", " << i.y;
        return os;
    }
};

bool cmpx(Item a, Item b)
{
    return a.x < b.x;
}

bool cmpy(Item a, Item b)
{
    return a.y < b.y;
}

int main()
{
    srand(time(NULL));

    vector<Item> v;
    v.resize(10);

    vector<Item>::iterator i;
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << "Sorting based on x:" << endl;
    sort(v.begin(), v.end(), cmpx);
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << endl;

    cout << "Sorting based on y:" << endl;
    sort(v.begin(), v.end(), cmpy);
    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << endl;
    }

    cout << endl;

    cout << "Sorting based upon x+y using lambda functions:" << endl;
    sort(v.begin(), 
        v.end,
        [](Item a, Item b)->bool {
            return (a.x + a.y) < (b.x + b.y);
        }
    );
    /*
    for (i = v.begin(), i != v.end(), ++i) {
        cout << *i << endl;
    }
    */

    for (auto i:v) {
        cout << i << endl;
    }

    return 0;
}