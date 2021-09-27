#include <iostream>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination){
	for (string s: source){
		destination.push_back(s);
	}
	source.clear();
}

int main(){
	vector<string> s = {"world"};
	vector<string> d = {"hello"};
	MoveStrings(s, d);
	cout << "печать вектора источника s" << endl;
	for (auto w: s){
		cout << w << endl;
	}
	
	cout << "печать вектора назначения d (куда копировали)" << endl;
	for (auto w: d){
		cout << w << endl;
	}	
	
	return 0;
}