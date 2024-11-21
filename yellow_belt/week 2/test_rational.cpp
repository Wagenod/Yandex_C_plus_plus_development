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




// class Utils{
// 	public:
// 		static int gcd(int a, int b)
// 		 {

// 			while (a != b) {
// 			    if (a > b) {
// 			        int tmp = a;
// 			        a = b;
// 			        b = tmp;
// 			    }
// 			    b = b - a;
// 			}
// 			return a;
// 		}

// 		static tuple<int, int> updateNumbers(int numerator, int denominator){
// 			if (denominator < 0){
// 				numerator *= -1;
// 				denominator = abs(denominator);
// 			}

// 			int gcd;
// 			if (numerator){
// 				gcd = Utils::gcd(abs(numerator), denominator);
// 				return make_tuple(numerator/gcd, denominator/gcd);
// 			} 

// 			return make_tuple(0, 1);
// 		}
// };

// class Rational{

// 	private:
// 		int p; // numerator
// 		int q; // denominator

// 	public:
// 		Rational(){
// 			setNumAndDenom(0, 1);
// 		}

// 		Rational(int numerator, int denominator){
// 			setNumAndDenom(numerator, denominator);
// 		}

// 		void setNumAndDenom(const int& numerator, const int& denominator){
// 			if (!denominator)
// 				throw invalid_argument("Invalid argument");
// 			tie(p, q) = Utils::updateNumbers(numerator, denominator);
// 		}

// 		int Numerator() const { return p;}
// 	  	int Denominator() const { return q;}
// };


// ==
bool operator== (const Rational& lr, const Rational& rr){
	return (lr.Numerator() == rr.Numerator()) && (lr.Denominator() == rr.Denominator()); 
}

//+
Rational operator+ (const Rational& lr, const Rational& rr){
	return Rational(lr.Numerator()*rr.Denominator() + rr.Numerator()*lr.Denominator(), 
					lr.Denominator()*rr.Denominator());
}

//-

Rational operator- (const Rational& lr, const Rational& rr){
	return Rational(lr.Numerator()*rr.Denominator() - rr.Numerator()*lr.Denominator(), 
					lr.Denominator()*rr.Denominator());
}

//*
Rational operator* (const Rational& lr, const Rational& rr){
	return Rational(lr.Numerator()*rr.Numerator(), lr.Denominator()*rr.Denominator());
}

// /
Rational operator/ (const Rational& lr, const Rational& rr){
	if (!rr.Numerator())
		throw domain_error("Division by zero");
	return Rational(lr.Numerator()*rr.Denominator(), lr.Denominator()*rr.Numerator());
}

// <<

ostream& operator<< (ostream& stream, const Rational& r){
	stream << r.Numerator() << "/" << r.Denominator();
	return stream;
}

// istream& operator>> (istream& stream, Rational& r){
	
// 	if(stream){
// 		int p = 0, q = 0;
// 	    char delim;

// 	    stream >> p >> delim >> q;
// 	    if (stream && delim == '/') {
// 	        r.setNumAndDenom(p, q);
// 	    }

// 	}
// 	return stream;
// }


bool operator< (const Rational& r1, const Rational& r2){
	return (r1 - r2).Numerator() < 0;
}


void Test(){
	{
		Rational r;
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "0/1", "0/1 Rational number");
	}

	{
		Rational r(10, 4);
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "5/2", "10/4 = 5/2");
	}

	{
		Rational r(-3, 7);
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "-3/7", "-3/7 = -3/7");
	}


	{
		Rational r(3, -7);
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "-3/7", "3/-7 = -3/7");
	}

	{
		Rational r(-3, -7);
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "3/7", "-3/-7 = 3/7");
	}

	{
		Rational r(0, -7);
		ostringstream os;
		os << r;
		AssertEqual(os.str(), "0/1", "0/-7 = 0/1");
	}
}


int main(){

	TestRunner tester;
	tester.RunTest(Test, "Test");



	// Rational rl, rr;
	// char operation;
	
	// try{
	// 	cin >> rl >> operation >> rr;
	// 	switch(operation){
	// 		case '/':
	// 			cout << rl / rr;
	// 			break;
	// 		case '*':
	// 			cout << rl * rr;
	// 			break;
	// 		case '-':
	// 			cout << rl - rr;
	// 			break;
	// 		case '+':
	// 			cout << rl + rr;
	// 			break;
	// 		default:
	// 			cout << "Operation " << operation << "is not definied";
	// 			break;
	// 	}
	// } 
	// catch (const invalid_argument& exc){
	// 	cout << exc.what();
	// }
	// catch (const domain_error& exc){
	// 	cout << exc.what();
	// }
    return 0;
}