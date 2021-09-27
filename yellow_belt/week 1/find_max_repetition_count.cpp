#include <iostream> 
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

bool operator< (const Region& lhs, const Region& rhs){
  auto main_block_a = tie(lhs.std_name, lhs.parent_std_name, lhs.population);
  auto main_block_b = tie(rhs.std_name, rhs.parent_std_name, rhs.population);

   if (main_block_a == main_block_b){
      if (lhs.names.size() == rhs.names.size()){
          for (auto item: {Lang::DE, Lang::FR, Lang::IT}){
              string lang_val_lhs = (lhs.names.find(item) != lhs.names.end()) ? lhs.names.at(item):"";
              string lang_val_rhs = (rhs.names.find(item) != rhs.names.end()) ? rhs.names.at(item):"";
              if(lang_val_lhs < lang_val_rhs)
                return true;
          }
      }
      return lhs.names.size() < rhs.names.size();
    } else{
      return main_block_a < main_block_b;
    }
}

// Решение авторов (я не знал, что можно сравнивать словари и даже когда не полностью совпадают ключи)
// bool operator<(const Region& lhs, const Region& rhs) {
//   return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
//       tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
// }

int FindMaxRepetitionCount(const vector<Region>& regions){
	int maxCount = 0;
	map<Region, int> occur;
	for (const Region& r: regions){
		maxCount = max(maxCount, ++occur[r]);
	}
	return maxCount;

}

int main() {
  // cout << FindMaxRepetitionCount({
  //     {
  //         "Moscow",
  //         "Russia",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Russia",
  //         "Eurasia",
  //         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
  //         89
  //     }, {
  //         "Moscow",
  //         "Russia",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Moscow",
  //         "Russia",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Russia",
  //         "Eurasia",
  //         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
  //         89
  //     },
  // }) << endl;
  
  // cout << FindMaxRepetitionCount({
  //     {
  //         "Moscow",
  //         "Russia",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Russia",
  //         "Eurasia",
  //         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
  //         89
  //     }, {
  //         "Moscow",
  //         "Russia",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Moscow",
  //         "Toulouse",
  //         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         89
  //     }, {
  //         "Moscow",
  //         "Russia",
  //         { {Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
  //         31
  //     },
  // }) << endl;
  
  return 0;
}
