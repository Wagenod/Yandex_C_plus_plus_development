#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


int main(){
	int N;
	int64_t sum = 0;
	vector<int> t, hot_days;
	cin >> N;

	for (int i=0; i<N; i++){
		int value;
		cin >> value;
		sum += value;
		t.push_back(value);
	}

	int avg_temp = sum/static_cast<int>(t.size());

	for (int day_idx=0; day_idx < t.size(); day_idx++){
		if (t[day_idx] > avg_temp){
			hot_days.push_back(day_idx);
		}
	}

	cout << hot_days.size() << endl;
	for(const auto& item: hot_days)
		cout << item << " ";

	return 0;
}