#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char,int> BuildCharCounters(const string& word){
	map<char,int> letter_counter;
	for (const auto& letter: word)
		letter_counter[letter]++;
	return letter_counter;
}

void print(const map<char, int>& m){
	for (const auto& item: m)
		cout << item.first << " " << item.second;
}

int main(){
	int n;
	string word_1, word_2;
	map<char,int> counter_1, counter_2;

	cin >> n;
	for (int i = 1; i<= n; i++){
		cin >> word_1 >> word_2;
		counter_1 = BuildCharCounters(word_1);
		counter_2 = BuildCharCounters(word_2);
		if (counter_1 == counter_2){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}