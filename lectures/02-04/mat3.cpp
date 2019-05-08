#include "mat3.h"

Mat3::Mat3()
{
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            _data[i][j] = 0.0;
        }
    }
    _data[0][0] = _data[1][1] = _data[2][2] = 1.0;
}

Mat3::Mat3(double a[])
{
    _data = a;

    int c = 0;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            _data[i][j] = a[c++];
        }
    }
}

Mat3::Mat3(const Mat3& o)
{
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            _data[i][j] = o._data[i][j];
        }
    }
}

Mat3& Mat3::operator=(const Mat3& o)
{
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            _data[i][j] = o._data[i][j];
        }
    }

    return *this;
}