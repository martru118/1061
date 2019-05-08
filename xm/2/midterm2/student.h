#ifndef __student_h__
#define __student_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Course {
  string _code;
  int _marks;
};

class Student
{
  protected:
  string _name;   //name of student
  vector<Course> _courses;  //stores both the course code and the marks

  public:
  Student() {}
  Student(const string& name);
  Student(const Student& o);    //copy constructor
  
  const Student& operator=(const Student& o);
  
  void add_course(const string& course_code);
  void set_marks(const string& course_code, int marks);

  int get_marks(const string& course_code);

  friend ostream& operator<<(ostream& os, const Student& s);
  friend istream& operator>>(istream& is, Student& s);
};

#endif
