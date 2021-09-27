#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;




class Person {
public:

  Person(const string& new_first_name, const string& new_last_name, int year){
    first_name_history[year] = new_first_name;
    last_name_history[year] = new_last_name;
    birth_year = year;
  }

  void ChangeFirstName(int year, const string& first_name) {
    // добавить факт изменения имени на first_name в год year
    if (year >= birth_year)
      first_name_history[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
    // добавить факт изменения фамилии на last_name в год year
    if (year >= birth_year)
      last_name_history[year] = last_name;
  }

  string GetNameByYear(int year, const map<int, string>& names) const{
  	string name = "";

    for (auto item: names){

      if(item.first > year)
        break;

      name = item.second;
    }
    return name;
  }

  string GetFullName(int year) const{

    if (year < birth_year)
      return "No person";

    string first_name = GetNameByYear(year, first_name_history);
    string last_name = GetNameByYear(year, last_name_history);

    if (first_name.empty() & last_name.empty()){
      return "Incognito";
    }

    if (first_name.empty()){
      return last_name + " with unknown first name";
    } 

    if (last_name.empty()){
      return first_name + " with unknown last name";
    }
      return first_name + " " + last_name;

  }

  vector<string> GetNamesInOrder(int year, const map<int, string>& names) const{
    vector<string> unique_names;

    for(auto item: names){

      if(item.first > year){
        break;
      }

      if (unique_names.empty() || unique_names.back() != item.second)
        unique_names.push_back(item.second);
    }

    return unique_names;
  }

  string GetFullNameWithHistory(int year) const{
    // получить все имена и фамилии по состоянию на конец года year

    if (year < birth_year)
      return "No person";

    const vector<string> first_names = GetNamesInOrder(year, first_name_history);
    const vector<string> last_names = GetNamesInOrder(year, last_name_history);
 
    if (first_names.empty() & last_names.empty()){
      return "Incognito";
    } else if (first_names.empty()){
      return ConcatenateVector(last_names) + " with unknown first name";
    } else if (last_names.empty()){
      return ConcatenateVector(first_names) + " with unknown last name";
    }
    return ConcatenateVector(first_names) + " " + ConcatenateVector(last_names);
  }

  string ConcatenateVector(const vector<string>& v) const{
    if (v.size() == 1)
      return v[0];
    
    string concat = v[v.size() - 1] + " (";

    for (int i = v.size() - 2; i >= 0; i--){
      if (i == 0)
        concat += v[i] + ")";
      else
        concat += v[i] + ", ";
    }

    return concat;
  }
private:
  map<int, string> first_name_history, last_name_history;
  int birth_year;
};


/**void print(const Person& person){
  cout << "\n\n\n-------------begin------------" << endl << "first_names: " << endl;
  for (const auto& item: person.first_name_history){
    cout << item.first << ": " << item.second << endl;
  }

  cout << "\n\nlast_names:" << endl; 
  for (const auto& item: person.last_name_history){
    cout << item.first << ": " << item.second << endl;
  }

  cout << "-------------end-------------\n\n\n";
}**/

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}