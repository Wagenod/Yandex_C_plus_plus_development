#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	ifstream file;
	file.open("data.txt");

	if (file.is_open())
	{
		file >> num1;
		file.ignore(2);
		file >> num2;
	}
	cout << num1;
	cout << num2;
	return 0;
}