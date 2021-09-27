#include <iostream>
#include <vector>

using namespace std;

void Reverse(vector<int>& v){
	int tmp;
	int n = v.size();
	for (int i=0; i < n / 2; i++){
		tmp = v[i];
		v[i] = v[n - i - 1];
		v[n - i - 1] = tmp;
	}
}

int main(){
	vector<int> v = {2, 3, 5, 1, 8};
	Reverse(v);
	for (auto item: v){
		cout << item;
	}
	return 0;
}