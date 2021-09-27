#include <iostream>
#include <string>
#include <vector>

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

vector<string> PalindromFilter(vector<string> words, int minLength){
	vector<string> result;
	
	for(auto word: words){
		if (IsPalindrom(word) && word.size() >= minLength){
			result.push_back(word);
		}
	}
	return result;
}

int main(){
	/*vector<string> v = {"lol","pop", "sdsd"};
	vector<string> r = PalindromFilter(v);
	for (auto w: r){
		cout << w << endl;
	}*/
	return 0;
}