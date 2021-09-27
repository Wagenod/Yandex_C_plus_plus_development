#include <iostream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

//const bool QUIET = true; // !QUIET = WORRIED

void come(vector<int>& queue, int k){
	queue.resize(queue.size() + k, 0);
}

void worry(vector<int>& queue, int k){
	queue[k] = 1;
}

void print_worry_count(vector<int>& queue){
	int worry_count = accumulate(queue.begin(), queue.end(), 0);
	cout << worry_count << endl;
}

void quiet(vector<int>& queue, int k){
	queue[k] = 0;
}

void print(const vector<int>& queue){
	for (auto i: queue)
		cout << i << " ";
	cout << endl;
}


int main(){
	// 1 - неспокойный 
	// 0 - спокойный
	int count_events;
	cin >> count_events;
	vector<int> queue;

	string event;
	int k;
	for(int i = 1; i <= count_events; i++){
		cin >> event;

		if (event == "WORRY_COUNT"){
			print_worry_count(queue);
		} else {
			cin >> k;

			if (event == "COME"){
				come(queue, k);
			} else if (event == "WORRY"){
				worry(queue, k);
			} else if (event == "QUIET"){
				quiet(queue, k);
			}
		}
		
		//print(queue);
	}

	return 0;
}