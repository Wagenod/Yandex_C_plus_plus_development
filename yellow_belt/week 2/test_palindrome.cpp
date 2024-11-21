#include <iostream>
#include <cmath>
#include <sstream>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <string>
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

bool IsPalindrom(string str){
  if (str.size() <=1)
    return true;
    
  int n = str.size();
  for (int i = 0; i < n/2; i++){
    if (str[i] != str[n - i - 1])
      return false;
  }
  
  return true;
}


void Test(){
  {
    AssertEqual(IsPalindrom(""), true, "Empty string");
    AssertEqual(IsPalindrom("a"), true, "One character string");
    AssertEqual(IsPalindrom("level"), true, "Palindrom");
    AssertEqual(IsPalindrom("abc"), false, " Not Palindrom");
    AssertEqual(IsPalindrom("le vel"), false, "string with space in center");
    AssertEqual(IsPalindrom(" level"), false, "string with space at the begin");
    AssertEqual(IsPalindrom("level "), false, "string with space at the end");
    AssertEqual(IsPalindrom("meveml"), false, "meveml");
    AssertEqual(IsPalindrom("levelm"), false, "levelm");
    AssertEqual(IsPalindrom("levmnvel"), false, "levmnvel");
    AssertEqual(IsPalindrom("LEVvel"), false, "LEVvel");
    AssertEqual(IsPalindrom("levVEL"), false, "levVEL");
    AssertEqual(IsPalindrom("levvel"), true, "levvel");
  }
}

int main(int argc, char const *argv[])
{
  TestRunner tester;
  tester.RunTest(Test, "Test 1");
  return 0;
}