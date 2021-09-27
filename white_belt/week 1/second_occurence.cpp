#include <iostream>
#include <string>

using namespace std;

int main(){
	
	string s;
	cin >> s;
	
	int freq = 0;
	for(int i = 0; i < s.length(); i++){
		if (s[i] == 'f'){
			++freq;
			if (freq == 2){
				cout << i;
				return 0;	
			}
		}
	}
	
	if (freq == 1){
		cout << -1;
	} else if (freq == 0){
		cout << -2;
	}
	
	return 0;
}