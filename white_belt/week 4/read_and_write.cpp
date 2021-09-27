#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	ifstream in("input.txt");
	ofstream out("output.txt");


	if (in){
		string line;

		while(getline(in, line)){
			out << line << endl;
		}
	}

	return 0;
}