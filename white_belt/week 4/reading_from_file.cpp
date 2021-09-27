#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string line = "";
	ifstream file;
	file.open("hello world.txt");

	if (file.is_open())
	{
		while (getline(file, line))
        {
            cout << line << endl;
        }
	}
	return 0;
}