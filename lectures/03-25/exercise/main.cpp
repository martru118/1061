#include <iostream>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class StudentRecord
{
  protected:
  int number;
  string first;
  string last;
  vector<pair<string,int> > grades;

  public:
  StudentRecord() {
  }

  StudentRecord(const int& n, const string& f, const string& l) {
    number = n;
    first = f;
    last = l;
  }

  StudentRecord(const StudentRecord& r) {
    *this = r;
  }
  
  StudentRecord& operator=(const StudentRecord& r) {
    number = r.number;
    first = r.first;
    last = r.last;
    grades = r.grades;
    return *this;
  }

  inline int get_student_number() const { return number; }
  inline const string& get_fname() const { return first; }
  inline const string& get_lname() const { return last; }
  
  void add_grade(string c, int g) {
    grades.push_back(pair<string,int>(c, g));
  }

  friend ostream& operator<<(ostream& os, const StudentRecord& r) {
    os << r.number << " " << r.first << " " << r.last << " [";

    vector<pair<string,int> >::const_iterator i;
    for (i = r.grades.begin(); i != r.grades.end(); ++i) {
      os << i->first << " " << i->second;
      if (i < r.grades.end()-1) os << ", ";
    }
    os << "]";
  
    return os;
  }
    
};

int load_items(istream& is, vector<string>& items)
{
  string tmp;

  while(true) {
    if (is.eof()) break;
    is >> tmp;
    if (is.fail()) break;
    if (tmp.size() < 1) continue;

    items.push_back(tmp);
  }

  return items.size();
}

string pick_random(vector<string>& items)
{
  return items[rand() % items.size()];
}

int pick_grade()
{
  return (rand() % 40) + 59;
}

StudentRecord* make_student(vector<string>& names, vector<string>& courses)
{
  static int student_number = 100;

  StudentRecord* sr = new StudentRecord(student_number, pick_random(names), pick_random(names));

  int num_courses = rand() % 10;
  for (int i = 0; i < num_courses; ++i) {
    sr->add_grade(pick_random(courses), pick_grade());
  }

#ifdef DEBUG  
  cout << "Created student: " << *sr << endl;
#endif
  
  ++student_number;

  return sr;
}



int main()
{
  typedef vector<string>::const_iterator Itr_vs;
  typedef list<StudentRecord*>::iterator Itr_l;
  typedef map<int, StudentRecord*>::iterator Itr_n;
  typedef map<string, StudentRecord*>::iterator Itr_s;
  typedef pair<string, StudentRecord*> Pair_n_and_sr;

  srand(0);

  ifstream name_file("names.txt");
  vector<string> names;
  names.reserve(15000);
  cout << load_items(name_file, names) << " loaded." << endl;
  name_file.close();

  ifstream course_file("courses.txt");
  vector<string> courses;
  cout << load_items(course_file, courses) << " loaded." << endl;
  course_file.close();
  
#ifdef _VERBOSE_
  cout << "Names:" << endl;
  for (Itr_vs i = names.begin(); i != names.end(); ++i) {
    cout << "\t" << *i << endl;
  }
  cout << "Courses:" << endl;
  for (Itr_vs i = courses.begin(); i != courses.end(); ++i) {
    cout << "\t" << *i << endl;
  }
#endif

  // Uncomment the following to see what happens
  //
  // cout << pick_random(names) << endl;
  // cout << pick_random(courses) << endl;
  // StudentRecord* r1 = make_student(names, courses);
  // cout << *r1 << endl;
  // delete r1;

  // Master DB
  cout << "Master DB" << endl;

  int num_students = 10000;
  list<StudentRecord*> l;
  for (int i=0; i<num_students; ++i) l.push_back(make_student(names, courses));

#ifdef _VERBOSE_
  for (Itr_l i = l.begin(); i != l.end(); ++i) {
    cout << **i << endl;
  }
#endif

  cout << "Master DB Done" << endl;

  cout << "Setup Student Number Index" << endl;
  map<int, StudentRecord*> index_n;
  for (Itr_l i = l.begin(); i != l.end(); ++i) {
    index_n[(*i)->get_student_number()] = *i; 
  }
  cout << "Setup Student Number Index Done" << endl;

#ifdef _SEARCH_SN_
  cout << "Searching students using student numbers" << endl;
  cout << "Enter student number: ";
  int q;
  cin >> q;
  Itr_n found = index_n.find(q);
  if (found == index_n.end()) {
    cout << "Student number " << q << "\n\tNot found." << endl;
  }
  else {
    cout << "Student number " << q << " found." << endl;
    cout << "\t" << *(found->second) << endl;
  }
#endif

  cout << "Setup Student Name Indices" << endl;
  multimap<string, StudentRecord*> index_f, index_l;
  for (Itr_l i = l.begin(); i != l.end(); ++i) {
      index_f.insert( Pair_n_and_sr( (*i)->get_fname(), *i ) );
      index_l.insert( Pair_n_and_sr( (*i)->get_lname(), *i ) );
  }
  cout << "Setup Student Name Indices Done." << endl;
  
#ifdef _SEARCH_NAMES_
  cout << "Search on Student First Name" << endl;
  cout << "Enter student first name: ";
  string q1;
  cin >> q1;
  pair<Itr_s, Itr_s> ret = index_f.equal_range(q1);
  if (ret.first == ret.second) {
    cout << "No student with first name " << q1 << "\n\tFound" << endl;
  }
  else {
    for ( Itr_s i = ret.first; i != ret.second; ++i) {
       cout << i->first << endl;
       cout << "\t" << *(i->second) << endl;
    }
  }

  cout << "Search on Student Last Name" << endl;
  cout << "Enter student last name: ";
  cin >> q1;
  ret = index_l.equal_range(q1);
  if (ret.first == ret.second) {
    cout << "No student with last name " << q1 << "\n\tFound" << endl;
  }
  else {
    for ( Itr_s i = ret.first; i != ret.second; ++i) {
       cout << i->first << endl;
       cout << "\t" << *(i->second) << endl;
    }
  } 
#endif

  cout << "Before sorting:" << endl; 
  for (auto i : l) cout << *i << endl;

  cout << "After sorting:" << endl; 
  // Write right here.
  vector<StudentRecord*> vtmp(l.begin(), l.end());
  sort(vtmp.begin(), vtmp.end(), 
    [](StudentRecord* a, StudentRecord* b)->bool 
    { return a->get_lname() < b->get_lname(); } 
  );
  for (auto i : vtmp) cout << *i << endl;
  
  for (Itr_l i = l.begin(); i != l.end(); ++i) delete *i;

  return 0;
}