#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void print_vector(const vector<int>& v){
	for (auto item: v)
		cout << item <<" ";
}

void read_data(vector<int>& v){
	for (int& item: v)
		cin >> item;
}

void filter_hot_days(const vector<int>& v_full_temperature, vector<int>& v_hot_temperature){
	int mean_temperature = accumulate(v_full_temperature.begin(), v_full_temperature.end(), 0) / v_full_temperature.size();
	
	for(int i = 0; i < v_full_temperature.size(); i++){
		if (v_full_temperature[i] > mean_temperature){
			v_hot_temperature.push_back(i);
		}
	}	
}

int main(){
	int k, n;
	cin >> n;
	vector<int> temperature(n);

	read_data(temperature);

	vector<int> hot_days;
	filter_hot_days(temperature, hot_days);
	cout << hot_days.size() << endl;

	print_vector(hot_days);

	return 0;
}