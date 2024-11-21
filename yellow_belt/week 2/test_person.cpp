#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>


using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};


// class Person {
// public:

//   Person(){
//     first_name_history = {};
//     last_name_history = {};
//     birth_year = -1;    
//   }

//   Person(const string& new_first_name, const string& new_last_name, int year){
//     first_name_history[year] = new_first_name;
//     last_name_history[year] = new_last_name;
//     birth_year = year;
//   }

//   void ChangeFirstName(int year, const string& first_name) {
//     // добавить факт изменения имени на first_name в год year
//     if (year >= birth_year)
//       first_name_history[year] = first_name;
//   }

//   void ChangeLastName(int year, const string& last_name) {
//     // добавить факт изменения фамилии на last_name в год year
//     if (year >= birth_year)
//       last_name_history[year] = last_name;
//   }

//   string GetNameByYear(int year, const map<int, string>& names) const{
//   	string name = "";

//     for (auto item: names){

//       if(item.first > year)
//         break;

//       name = item.second;
//     }
//     return name;
//   }

//   string GetFullName(int year) const{

//     if (year < birth_year)
//       return "No person";

//     string first_name = GetNameByYear(year, first_name_history);
//     string last_name = GetNameByYear(year, last_name_history);

//     if (first_name.empty() & last_name.empty()){
//       return "Incognito";
//     }

//     if (first_name.empty()){
//       return last_name + " with unknown first name";
//     } 

//     if (last_name.empty()){
//       return first_name + " with unknown last name";
//     }
//       return first_name + " " + last_name;

//   }

//   vector<string> GetNamesInOrder(int year, const map<int, string>& names) const{
//     vector<string> unique_names;

//     for(auto item: names){

//       if(item.first > year){
//         break;
//       }

//       if (unique_names.empty() || unique_names.back() != item.second)
//         unique_names.push_back(item.second);
//     }

//     return unique_names;
//   }

//   string GetFullNameWithHistory(int year) const{
//     // получить все имена и фамилии по состоянию на конец года year

//     if (year < birth_year)
//       return "No person";

//     const vector<string> first_names = GetNamesInOrder(year, first_name_history);
//     const vector<string> last_names = GetNamesInOrder(year, last_name_history);
 
//     if (first_names.empty() & last_names.empty()){
//       return "Incognito";
//     } else if (first_names.empty()){
//       return ConcatenateVector(last_names) + " with unknown first name";
//     } else if (last_names.empty()){
//       return ConcatenateVector(first_names) + " with unknown last name";
//     }
//     return ConcatenateVector(first_names) + " " + ConcatenateVector(last_names);
//   }

//   string ConcatenateVector(const vector<string>& v) const{
//     if (v.size() == 1)
//       return v[0];
    
//     string concat = v[v.size() - 1] + " (";

//     for (int i = v.size() - 2; i >= 0; i--){
//       if (i == 0)
//         concat += v[i] + ")";
//       else
//         concat += v[i] + ", ";
//     }

//     return concat;
//   }
// private:
//   map<int, string> first_name_history, last_name_history;
//   int birth_year;
// };


void TestFullName(){
  {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1900), "Incognito", "Incognito test");
    AssertEqual(person.GetFullName(1965), "Polina with unknown last name", "First name without last name");
    AssertEqual(person.GetFullName(1990), "Polina Sergeeva", "firstname + lastname");
  }


  {
    Person person;
    person.ChangeLastName(1956, "Ivanov");
    AssertEqual(person.GetFullName(1965), "Ivanov with unknown first name", "lastname without firstname");

  }

}


int main() {

  TestRunner tester;

  tester.RunTest(TestFullName, "test GetFullName");

  return 0;
}