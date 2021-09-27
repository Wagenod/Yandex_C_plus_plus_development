#include <iostream>
#include <vector>

using namespace std;

int main(){
	
	int n, whole, rem;
	vector<int> bin;
	cin >> n;

	do {
		bin.push_back(n % 2);
		n = n / 2;
	} while (n >= 1);
	
	for (int idx = bin.size() - 1; idx >= 0; idx--){
		cout << bin[idx];
	}
	
	return 0;
}