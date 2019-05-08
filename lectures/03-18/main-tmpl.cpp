#include <vector>
#include "key-value-tmpl.h"

class StudentRecord
{
 protected:
 string first;
 string last;
 vector<KeyValue<string,int> > grades;

 public:
 StudentRecord() {
 }

 StudentRecord(const string& f, const string& l) {
   first = f;
   last = l;
 }

 StudentRecord(const StudentRecord& r) {
   *this = r;
 }

 StudentRecord& operator=(const StudentRecord& r) {
   first = r.first;
   last = r.last;
   grades = r.grades;
   return *this;
 }

 void add_grade(string c, int g) {
   grades.push_back(KeyValue<string,int>(c, g));
 }

 friend ostream& operator<<(ostream& os, const StudentRecord& r) {
   os << r.first << " " << r.last << " [";

   vector<KeyValue<string,int> >::const_iterator i;
   for (i = r.grades.begin(); i != r.grades.end(); ++i) {
     os << *i;
     if (i < r.grades.end()-1) os << ", ";
   }
   os << "]";

   return os;
 }

};

int main()
{
 // KeyValue<int, string> k1(1, "hello");

 // KeyValue<string, string> k2("world", "earth");

 // cout << "k1: " << k1 << endl;
 // cout << "k2: " << k2 << endl;

 StudentRecord r1("Jane", "Smith");
 r1.add_grade("csci1060u",98);
 r1.add_grade("csci1061u",47);
 r1.add_grade("csci1040u",99);
 cout << r1 << endl;

 KeyValue<int, StudentRecord> sr1(100, r1);
 cout << sr1 << endl;

 return 0;
}