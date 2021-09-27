#include <iostream>
#include <vector>
#include <string>

using namespace std;


const vector<int> DAYS_IN_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void dump(const vector<string>& daily_events){
	cout << daily_events.size() << " ";
	for (string deal: daily_events){
		cout << deal << " ";
	}
	cout << endl;
}

void next(vector<vector<string>>& month_deals, int next_month_number){
	const int month_num_days = month_deals.size();
	const int next_month_num_days = DAYS_IN_MONTH[next_month_number];

	if (month_num_days > next_month_num_days){
		for (int i = month_num_days - 1; i > next_month_num_days - 1; i--){
			month_deals[next_month_num_days - 1].insert(end(month_deals[next_month_num_days - 1]), 
														begin(month_deals[i]), 
														end(month_deals[i]));
		}
	month_deals.resize(DAYS_IN_MONTH[next_month_number], {});
	}
}

void add(vector<string>& daily_actions, string new_event){
	daily_actions.push_back(new_event);
}

void print(const vector<vector<string>>& v){
	for (int i=0; i<v.size(); i++){
		cout << i;
		for (auto item: v[i])
			cout << item << " ";
		cout << endl;
	}
}

int main(){
	int q, day_number;
	int month_number = 0; // номер месяца (0-январь, ..., 11 - декабрь)
	
	vector<vector<string>> current_month_deals(DAYS_IN_MONTH[month_number]); 
	string operation_code, event;
	cin >> q;

	for (int i = 0; i < q; i++){
		cin >> operation_code;
		if (operation_code == "NEXT"){
			month_number = (month_number + 1)%12;
			next(current_month_deals, month_number);
		} else if (operation_code == "DUMP"){
			cin >> day_number;
			dump(current_month_deals[day_number - 1]);
		} else if (operation_code == "ADD"){
			cin >> day_number >> event;
			add(current_month_deals[day_number - 1], event);
		}
		//print(current_month_deals);
	}

	return 0;
}