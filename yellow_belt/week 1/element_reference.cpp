#include <iostream> 
#include <map>
#include <exception>

using namespace std;

template <typename KeyT, typename ValueT> ValueT& GetRefStrict (map<KeyT, ValueT>& m, KeyT key);


template <typename KeyT, typename ValueT>
ValueT& GetRefStrict (map<KeyT, ValueT>& m, KeyT key){
	if(m.count(key)==0)
		throw runtime_error("This is runtime error!");

	return m.at(key);
}


int main(){

	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 1);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}