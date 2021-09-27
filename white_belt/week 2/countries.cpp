#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;



void print(const map<char, int>& m){
	for (const auto& item: m)
		cout << item.first << " " << item.second;
}



int main(){
	int n;
	cin >> n;
	string operation_code;
	map<string,string> countries; // база данных стран и их столиц

	for (int i = 1; i <= n; i++){
		cin >> operation_code;
		if (operation_code == "CHANGE_CAPITAL"){ // CHANGE_CAPITAL country new_capital 
			string country, new_capital;
			cin >> country >> new_capital;
			if(countries.count(country) == 0){
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
				countries[country] = new_capital;
			} else if (countries.count(country) == 1){
				if (countries[country] == new_capital){
					cout << "Country " << country << " hasn't changed its capital" << endl;
				} else {
					cout << "Country " << country <<" has changed its capital from " << countries[country] << " to " << new_capital << endl;
					countries[country] = new_capital;
				}
			}
		} else if (operation_code == "RENAME"){ // RENAME old_country_name new_country_name
			string old_country_name, new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name | countries.count(old_country_name) == 0 | countries.count(new_country_name) == 1){
				cout << "Incorrect rename, skip" << endl;
			} else {
				auto it = countries.find(old_country_name);
				string capital = countries[old_country_name];
				countries.erase(old_country_name);
				countries[new_country_name] = capital;
				cout << "Country " << old_country_name << " with capital " << capital << " has been renamed to " << new_country_name << endl;
			}
		} else if (operation_code == "ABOUT"){ // ABOUT country
			string country;
			cin >> country;
			if (countries.count(country) == 0){
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}
		} else if (operation_code == "DUMP"){ // DUMP
			if (countries.empty()){
				cout << "There are no countries in the world" << endl;
			} else {
				for (const auto& pair: countries){
					cout << pair.first + "/" + pair.second;
				}
			}
			
		}
	}

}