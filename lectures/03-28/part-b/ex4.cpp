#include <iostream>
#include <exception>

using namespace std;

class TimeZero
{
  protected:
  string msg;
  double distance;

  public:
  TimeZero(double distance) : msg("User entered time = 0.") { this->distance = distance; }
  const string& get_msg() { return msg; }
  const double& get_d() { return distance; }
};

class TimeNeg
{
  protected:
  string msg;

  public:
  TimeNeg() : msg("User entered time < 0.") {}
  const string& get_msg() { return msg; }
};


void func3(double& distance, double& time)
{
    cout << "Entering func3." << endl;

    cout << "Enter distance: ";
    cin >> distance;

    cout << "Enter time: ";
    cin >> time;

    if (time == 0) throw TimeZero(distance);
    if (time < 0) throw TimeNeg();
    if (distance < 0) throw distance;

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

  try {
    func1(distance, time);
  }
  catch (TimeZero e) {
    cout << e.get_msg() << endl;
    cout << e.get_d() << endl;
  }
  catch (TimeNeg e) {
    cout << e.get_msg() << endl;
  }
  catch(...) {
    cout << "Bad things are happening." << endl;
  }
    
  speed = distance / time;
  cout << "Speed is " << speed << endl;
  
  return 0;
}
