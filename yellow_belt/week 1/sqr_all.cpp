#include <iostream> 
#include <vector>
#include <map>
#include <utility>

using namespace std;

template <typename T> vector<T> Sqr(const vector<T> v);
template <typename FirstT, typename SecondT> pair<FirstT, SecondT> Sqr(const pair<FirstT, SecondT>& p1);
template <typename KeyT, typename ValueT> map<KeyT, ValueT> Sqr(const map<KeyT, ValueT> m);
template <typename T> T Sqr(T val);
template <typename FirstT, typename SecondT> pair<FirstT, SecondT> operator* (const pair<FirstT, SecondT>& p1, const pair<FirstT, SecondT>& p2);

template <typename T>
vector<T> Sqr(const vector<T> v){
	vector<T> new_vec;
	for (const T& item: v)
		new_vec.push_back(Sqr(item));
	return new_vec;
}

template <typename FirstT, typename SecondT>
pair<FirstT, SecondT> operator* (const pair<FirstT, SecondT>& p1, const pair<FirstT, SecondT>& p2){
	return make_pair(p1.first*p2.first, p1.second*p2.second);
}

template <typename FirstT, typename SecondT>
pair<FirstT, SecondT> Sqr(const pair<FirstT, SecondT>& p1){
	return p1*p1;
}


template <typename T>
T Sqr(T val){
	return val*val;
}


template <typename KeyT, typename ValueT>
map<KeyT, ValueT> Sqr(const map<KeyT, ValueT> m){
	map<KeyT, ValueT> new_m;
	for(const pair<KeyT, ValueT>& item: m)
		new_m[item.first] = Sqr(item.second);
	return new_m;
}



int main(){

	vector<map<int, pair<int, int>>> v = {{{1, {1, 3}}}, {{2, {4, 5}}}, {{3, {6, 7}}}};
	cout << "vector of maps:";
	for (const auto& m : Sqr(v)) {
	  for(const auto& p: m){
	  	cout << p.first << ":{" << p.second.first << "," << p.second.second << "}" << endl; 
	  }
	}

	const map<int, int> maps{ {1,2},{2,3} };
	auto res = Sqr(maps);

	// Пример вызова функции
	vector<int> v2 = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v2)) {
	  cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	  cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}