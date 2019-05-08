#include <iostream>
#include <exception>

using namespace std;

class TimeZero
{
  protected:
  string msg;

  public:
  TimeZero() : msg("Time cannot be 0.") {}
  const string& get_msg() { return msg; }
};

class DistanceNeg
{
  protected:
  string msg;

  public:
  DistanceNeg() : msg("Distance cannot be less than 0.") {}
  const string& get_msg() { return msg; }
};

class TimeNeg
{
  protected:
  string msg;

  public:
  TimeNeg() : msg("Time cannot be less than 0.") {}
  const string& get_msg() { return msg; }
};

void func2(double& distance, double& time)
{
    cout << "Enter distance: ";
    cin >> distance;

    cout << "Enter time: ";
    cin >> time;

    if (time == 0) throw TimeZero();
    if (distance < 0) throw DistanceNeg();
    if (time < 0) throw TimeNeg();
}

void func1(double& d, double& t) {
  func2(d, t);
}

int main()
{
  double distance, time;

  try {
    func1(distance, time);
  }
  catch(TimeZero e) {
    cout << e.get_msg() << endl;
    exit(0);
  }
  catch(DistanceNeg e) {
    cout << e.get_msg() << endl;
    exit(0);
  }
  catch(...) {
    cout << "Bad things are happening." << endl;
    exit(0);
  }
    
  double speed = distance / time;
  cout << "Speed is " << speed << endl;
  
  return 0;
}
