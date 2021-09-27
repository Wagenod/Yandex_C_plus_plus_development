#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	double a, b, c;
	cin >> a >> b >> c;
	if (!a && !b){
		cout << " ";
	} else if (!a && b){ 
		cout << -double(c)/b;
	} else{
		double D = pow(b,2) - 4*a*c;
		if (D < 0) {
			cout << "";
		} else {
			double x1 = (-b + sqrt(D))/(2*a);
			double x2 = (-b - sqrt(D))/(2*a);
			if (x1 == x2){ cout << x1;}
			else {cout << x1 << " "<< x2;}
		}		
	}	
	return 0;
}