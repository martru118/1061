#include <iostream>
#include <vector>
#include <map>
#include <list>

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

 StudentRecord(int n, const string& f, const string& l) {
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
 inline const string& get_f() const { return first; }
 inline const string& get_l() const { return first; }

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

int main()
{
 StudentRecord* r1 = new StudentRecord(100, "Jane", "Smith");
 r1->add_grade("csci1060u", 98);
 r1->add_grade("csci1061u", 47);
 r1->add_grade("csci1040u", 99);
 cout << *r1 << endl;

 StudentRecord* r2 = new StudentRecord(104, "Adam", "Hammersmith");
 r2->add_grade("csci1060u", 80);
 r2->add_grade("csci1061u", 67);
 r2->add_grade("csci1040u", 9);
 cout << *r2 << endl;

 list<StudentRecord*> l;
 l.push_back(r1);
 l.push_back(r2);

 // Master database
 typedef list<StudentRecord*>::iterator list_i;
 for (list_i i = l.begin(); i != l.end(); ++i) {
   cout << **i << endl;
 }

 // Lets make an index over student numbers
 map<int, StudentRecord*> index1;
 index1[r1->get_student_number()] = r1;
 index1[r2->get_student_number()] = r2;

 // Lets print to check
 typedef map<int, StudentRecord*>::iterator map_i;
 for (map_i i = index1.begin(); i != index1.end(); ++i) {
   cout << "Student Number: " << i->first << endl;
   cout << "\t" << *(i->second) << endl;
 }

 // Lets do a search on student number
 map_i o = index1.find(1334);
 if (o == index1.end()) {
   cout << "Item not found." << endl;
 }
 else {
   cout << "Item found" << endl;
   cout << "\t" << *(o->second) << endl;
 }

 //Lets create an index on first and last names
 typedef multimap<string, StudentRecord*> Index_str;
 typedef multimap<string, StudentRecord*>::iterator Itr_str;
 Index_str index_f;
 Index_str index_l;

 index_f.insert(pair<string, StudentRecord*>(r1->get_f, r1));
 index_l.insert(pair<string, StudentRecord*>(r2->get_l, r2));

 for (Itr_str i = index_f.begin(); i != index_l.end(); ++i) {
   cout << i->first << endl;
   cout << "\t" << *(i->second) << endl;
 }

 pair<  //a pair of two multimaps
    multimap<string, StudentRecord*>::iterator, 
    multimap<string, StudentRecord*>::iterator
    > ret;
 ret = index_f.equal_range("Jane");

 for (multimap<string, StudentRecord*>::iterator i = ret.first; 
      i != ret.second; 
      ++i) {
   cout << i->first << endl;
   cout << "\t" << *(i->second) << endl;
 }

 // Clear memory
 for (list_i i = l.begin(); i != l.end(); ++i) {
   delete *i;
 }

 return 0;
}