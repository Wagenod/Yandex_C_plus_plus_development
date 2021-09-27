#include <iostream>
#include <sstream>
using namespace std;


void EnsureEqual(const string& l, const string& r){
	if (l != r)
		throw runtime_error(l + " != " + r);
}

int main(){

	try {
    	EnsureEqual("C++ White", "C++ White");
    	EnsureEqual("C++ White", "C++ Yellow");
  	} catch (runtime_error& e) {
    	cout << e.what() << endl;
  	}
	return 0;
}