#include <iostream>

using namespace std;

int main(){
	float N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	if (N <= A){
		cout << N << endl;
	} else if (N > A && N <= B){
		cout << N*(1 - X/100);
	} else{
		cout << N*(1-Y/100);
	}
	
	return 0;
}