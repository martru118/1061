#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Video
{
    protected:
    string _title;
    int _xres, _yres;
    float _duration;
};

class Serial : public Video
{
    protected:
    int _num_episodes;
};

// Read videos/serials from istream into an array
vector<string> getVid() {
    
}
// Write video/serials stored in an array to ostream
// Search the array and find the matching items and write those to ostream

int main(int argc, char** argv)
{
    return 0;
}