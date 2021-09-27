#include <iostream>
#include <map>
#include <string>

using namespace std;


int main(){
	map<int, string> m = {{3, "three"}, {2, "two"}, {1, "one"}};

	map::iterator entry = m.find(2);
	if (entry != end(m))
	{
	    auto const value = entry->second;
	    m.erase(entry);
	    m.insert({5, value});
	}
	for (const auto& pair: m){
		cout << pair.first;
	}
}