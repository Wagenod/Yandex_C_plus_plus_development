#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
	int n;
	cin >> n;
	map<string, vector<string>> bus_stop, stop_bus;

	for (int i = 1;i <= n; i++){
		string operation_code;
		cin >> operation_code;
		if (operation_code == "NEW_BUS"){ // NEW_BUS bus stop_count stop1 stop2 ...
			
			string bus, stop;
			int stop_count;

			cin >> bus >> stop_count;

			for (int stop_i = 1; stop_i <= stop_count; stop_i++){
				cin >> stop;
				bus_stop[bus].push_back(stop);
				stop_bus[stop].push_back(bus);
			}

		} else if (operation_code == "BUSES_FOR_STOP"){  // BUSES_FOR_STOP stop
			string stop;
			cin >> stop;
			if (stop_bus.count(stop) == 0){
				cout << "No stop" << endl;
				continue;
			}

			for (const auto& bus: stop_bus[stop])
				cout << bus << " ";

			cout << endl;

		} else if (operation_code == "STOPS_FOR_BUS"){ // STOPS_FOR_BUS bus
			string bus;
			cin >> bus;		
			if (bus_stop.count(bus) == 0){
				cout << "No bus" << endl;
				continue;
			}

			for (const auto& stop: bus_stop[bus]){
				string buses_by_stop = "";
				for (const auto& item :stop_bus[stop]){
					if (item != bus)
						buses_by_stop += " " + item;
				}
				if (buses_by_stop != ""){
					cout << "Stop " << stop << ":" << buses_by_stop << endl;
				} else {
					cout << "Stop " << stop << ": " << "no interchange" << endl;
				}
			}

		} else if (operation_code == "ALL_BUSES"){ // ALL_BUSES
			if (bus_stop.empty()){
				cout << "No buses" << endl;
				continue;
			} 

			for (const auto& pair: bus_stop){
				cout << "Bus " << pair.first << ":";
				for (const auto& stop: pair.second)
					cout << " " << stop;
				cout << endl;
			}
		}
	}
	return 0;
}