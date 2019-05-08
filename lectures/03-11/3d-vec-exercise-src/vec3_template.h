#ifndef __vec3_template_h__
#define __vec3_template_h__

#include <iostream>
using namespace std;
template <typename T>

class vec3_template
{
    protected:
    T data[3];

    public:
    vec3_template() {}

    vec3_template(T x, T y, T z) {
      /*
      For this to work, 
      */

        data[0] = x;
        data[1] = y;
        data[2] = z;
    }

    vec3_template(const vec3_template& v)
    {
        for (int i=0; i<3; ++i) {
        data[i] = v[i];
        }
    }

    const T& operator=(const vec3_template& v)
    {
        for (int i=0; i<3; ++i) {
        data[i] = v[i];
        }
        return *this;
    }
    
    T& operator[](int i) { return data[i]; }
    const T& operator[](int i) const { return data[i]; }

    void print();

    template <typename T>
    friend double find_max(const vec3_template& v);
};

template <typename T>
void vec3_template<T>::print()
{
    cout << "(" << data[0] << "," << data[1] << "," << data[2] << ")" << endl;
}

template <typename T>
double find_max(const vec3_template& v)
{
    double m = v[0];
    if (m < v[1]) m = v[1];
    if (m < v[2]) m = v[2];
    return m;
}

#endif