#include <iostream> 
#include <tuple>
#include <string>

using namespace std;

tuple<int, string, bool> my_func(){
	int a = 1;
	string b = "C++";
	bool c = false;

	return {a, b, c};
}

int main(){

	int number;
	string lang;
	bool status;

	tie(number, lang, status) = my_func();

	cout << number << "-" << lang << "-" << status;
	return 0;
}