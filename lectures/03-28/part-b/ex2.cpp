#include <iostream>

using namespace std;

int main()
{
  double distance;
  double time;
  double speed;

  try {
    cout << "Enter distance: ";
    cin >> distance;

    cout << "Enter time: ";
    cin >> time;

    if (time == 0) throw time;

    cout << "Lets see if this statement is executed." << endl;
  }
  catch(double e)
  {
    cout << "An error occured." << endl;
  }

  speed = distance / time;
  cout << "Speed is " << speed << endl;
  
  return 0;
}
