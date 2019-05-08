class Mat3
{
public:
    double _data[3][3];
    double* _data;

public:
    Mat3();
    Mat3(double a[]);
    Mat3(const Mat3& o);

    Mat3& operator=(const Mat3& o);
};