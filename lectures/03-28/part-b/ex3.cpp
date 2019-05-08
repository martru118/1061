#include <iostream>

using namespace std;


void func3(double& distance, double& time)
{
    cout << "Entering func3." << endl;

    cout << "Enter distance: ";
    cin >> distance;

    cout << "Enter time: ";
    cin >> time;

    if (time == 0) throw time;

    cout << "Exiting from func3." << endl;
}

void func2(double& d, double& t)
{
  cout << "Entering func2." << endl;
  func3(d, t);
  cout << "Exiting from func2." << endl;
}

void func1(double& d, double& t)
{
  cout << "Entering func1." << endl;
  func2(d, t);
  cout << "Exiting from func1." << endl;
}

int main()
{
  double distance;
  double time;
  double speed;

  func1(distance, time);
  
  speed = distance / time;
  cout << "Speed is " << speed << endl;
  
  return 0;
}
