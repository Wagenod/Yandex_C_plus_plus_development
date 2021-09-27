#include <iostream>
#include <cmath>
#include <sstream>
#include <tuple>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Utils{
	public:
		static int gcd(int a, int b)
		 {

			while (a != b) {
			    if (a > b) {
			        int tmp = a;
			        a = b;
			        b = tmp;
			    }
			    b = b - a;
			}
			return a;
		}

		static tuple<int, int> updateNumbers(int numerator, int denominator){
			if (denominator < 0){
				numerator *= -1;
				denominator = abs(denominator);
			}

			int gcd;
			if (numerator){
				gcd = Utils::gcd(abs(numerator), denominator);
				return make_tuple(numerator/gcd, denominator/gcd);
			} 

			return make_tuple(0, 1);
		}
};

class Rational{

	private:
		int p; // numerator
		int q; // denominator

	public:
		Rational(){
			setNumAndDenom(0, 1);
		}

		Rational(int numerator, int denominator){
			setNumAndDenom(numerator, denominator);
		}

		void setNumAndDenom(const int& numerator, const int& denominator){
			if (!denominator)
				throw invalid_argument("Invalid argument");
			tie(p, q) = Utils::updateNumbers(numerator, denominator);
		}

		int Numerator() const { return p;}
	  	int Denominator() const { return q;}
};


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

istream& operator>> (istream& stream, Rational& r){
	
	if(stream){
		int p = 0, q = 0;
	    char delim;

	    stream >> p >> delim >> q;
	    if (stream && delim == '/') {
	        r.setNumAndDenom(p, q);
	    }

	}
	return stream;
}


bool operator< (const Rational& r1, const Rational& r2){
	return (r1 - r2).Numerator() < 0;
}


int main(){
	Rational rl, rr;
	char operation;
	
	try{
		cin >> rl >> operation >> rr;
		switch(operation){
			case '/':
				cout << rl / rr;
				break;
			case '*':
				cout << rl * rr;
				break;
			case '-':
				cout << rl - rr;
				break;
			case '+':
				cout << rl + rr;
				break;
			default:
				cout << "Operation " << operation << "is not definied";
				break;
		}
	} 
	catch (const invalid_argument& exc){
		cout << exc.what();
	}
	catch (const domain_error& exc){
		cout << exc.what();
	}
    return 0;
}