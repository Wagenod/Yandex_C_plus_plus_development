#include <iostream>

using namespace std;

int Factorial(int number){
	if (number <= 1){
		return 1;
	}
	
	int factorial = 1;
	for (int i = 2; i <= number; i++){
		factorial *= i;
	}
	
	return factorial;
}

int main(){
	
	int num;
	cin >> num;
	cout << Factorial(num);
	return 0;
}