#include "phone_number.cpp"


using namespace std;


int main(){

	PhoneNumber pn = PhoneNumber("+7-897-7657656");

	cout << pn.GetCountryCode() << endl;
	cout << pn.GetCityCode() << endl;
	cout << pn.GetInternationalNumber() << endl;

	return 0;
}