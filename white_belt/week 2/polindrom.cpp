#include <iostream>
#include <string>

using namespace std;

bool IsPalindrom(string str){
	if (str.size() <=1)
		return true;
		
	int n = str.size();
	for (int i = 0; i < n/2; i++){
		if (str[i] != str[n - i - 1])
			return false;
	}
	
	return true;
}

int main(){
	
	string str;
	cin >> str;
	cout << IsPalindrom(str);
	return 0;
}