#include "sum_reverse_sort.h"

#include <iostream>
#include <algorithm>

using namespace std;


int Sum(int x, int y){
	return x + y;
}

string Reverse(string s){
	string reversed_str = "";

	for (int idx=s.size()-1; idx>=0; idx--)
		reversed_str += s[idx];
	
	return reversed_str;
}

void Sort(vector<int>& nums){
	sort(nums.begin(), nums.end());
}
