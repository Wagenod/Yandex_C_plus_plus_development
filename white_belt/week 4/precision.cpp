#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	ifstream in("input.txt");

	if (in){
		cout << setprecision(3) << fixed;

		double number;

		while (in >> number){
			cout << number << endl;
		}
	}
	return 0;
}