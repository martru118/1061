#include "student.h"

using namespace std;

Student::Student()
{
    _name = "";
    _courses = {};

}

Student::Student(const string& name)
{
    //set the name of the student
    this->_name = name;
}

Student::Student(const Student& o)
{
    //copy constructor
    _name = o._name;
    _courses = o._courses;
}

const Student& Student::operator=(const Student& o)
{
    //similar to copy constructor
    _name = o._name;
    _courses = o._courses;
    return *this;
}

void Student::add_course(const string& course_code)
{
    Course c;

    c._code = course_code;
    c._marks = 0;
}

void Student::set_marks(const string& course_code, int marks)
{
    Course c;

    c._code = course_code;
    c._marks = marks;
}

int Student::get_marks(const string& course_code)
{
    //return the marks from the index of the vector
    //corresponding to the course_code

    for (int i = 0; i < _courses.size(); i++) {
        //find the course code within the courses vector
        if (_courses[i]._code == course_code) {
            return _courses[i]._marks;
        }
    }
}

/*
ostream& operator<<(ostream& os, const Student& s) 
{
    
}
istream& operator>>(istream& is, Student& s)
{

}
*/