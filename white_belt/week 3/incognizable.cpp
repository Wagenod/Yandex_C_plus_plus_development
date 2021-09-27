
#include <iostream>
#include <string>


using namespace std;

struct Incognizable{
	int param1 = 0;
	int param2 = 0;
};


int main(){
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};
	return 0;
}