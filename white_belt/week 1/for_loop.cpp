#include <iostream>

using namespace std;

int main(){
	int A, B;
	cin >> A >> B;
	
	if (!B){
		cout << "Impossible";
	} else{
		cout << A/B;
	}

	return 0;
}
