#include <iostream>
#include <vector>

using namespace std;

vector<int> Reversed(const vector<int>& v){
	vector<int> result;
	for (int i = v.size() - 1; i >= 0; i--){
		result.push_back(v[i]);
	}
	return result;
}

int main(){
	vector<int> v = {2, 3, 5, 1, 8};
	vector<int> result = Reversed(v);
	for (auto item: result){
		cout << item;
	}
	return 0;
}