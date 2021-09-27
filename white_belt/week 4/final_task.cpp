#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

class Utils{
  public:

    static void checkDateFormatAndSkipDelim(stringstream& stream, const string& date_str){
      if (stream.fail() || stream.peek() != '-')
        throw runtime_error("Wrong date format: " + date_str);

      stream.ignore(1);      
    }

    static void checkMonthValue(const int& month){
      if (month < 1 || month > 12)
        throw runtime_error("Month value is invalid: " + to_string(month));
    }

    static void checkDayValue(const int& day){
      if (day < 1 || day > 31)
        throw runtime_error("Day value is invalid: " + to_string(day));
    }
};

class Date {
  public:
  
    Date (string& date_str){
    	stringstream stream(date_str);
    	stream >> year;
      Utils::checkDateFormatAndSkipDelim(stream, date_str);

    	stream >> month;
      Utils::checkDateFormatAndSkipDelim(stream, date_str);
      
    	stream >> day;
      if (stream.fail() || !stream.eof())
        throw runtime_error("Wrong date format: " + date_str);

      Utils::checkMonthValue(month);
      Utils::checkDayValue(day);
    }

    int GetYear() const {
      return year;
    }

    int GetMonth() const {
      return month;
    }

    int GetDay() const{
      return day;
    }
  
  private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs){
  if (lhs.GetYear() == rhs.GetYear()){
    if (lhs.GetMonth() == rhs.GetMonth()){
      return lhs.GetDay() < rhs.GetDay();
    } else {
      return lhs.GetMonth() < rhs.GetMonth();
    }
  } else {
    return lhs.GetYear() < rhs.GetYear();
  }
}


ostream& operator<< (ostream& stream, const Date& date){
      stream << setw(4) << setfill('0') << date.GetYear() << '-' 
            << setw(2) << setfill('0') << date.GetMonth() << '-'
            << setw(2) << setfill('0') << date.GetDay();
      return stream;
    }

class Database {
  public:
    void AddEvent(const Date& date, const string& event){
      calender[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event){
        if (calender.count(date) > 0 && calender[date].count(event) > 0){
            calender[date].erase(event);
            return true;
        }
        return false; 
    }

    int  DeleteDate(const Date& date){
      return calender.erase(date);
    }

    set<string> Find(const Date& date) const{
      if (calender.count(date) > 0){
        return calender.at(date);
      }
      return {};
    }
    
    void Print() const{
      for (const auto& item: calender){
        const Date date = item.first;
        if (date.GetYear() >= 0){
          for (const string& event: calender.at(date))
            cout << date << " " << event << endl;
        }
      }

    }

   private:
   	map<Date, set<string>> calender;

  };

int main() {
  Database db;
    
  string command_line;


  while (getline(cin, command_line)) {

    if (command_line.empty())
      continue;

  	stringstream str_stream(command_line);
  	string command_name, event_str, date_str;
  	str_stream >> command_name >> date_str >> event_str;

  	try{
      if (command_name == "Print"){
          db.Print();
      } else if (command_name == "Add"){
          db.AddEvent({date_str}, event_str);
      } else if (command_name == "Del" && !event_str.empty()){
          if (db.DeleteEvent({date_str}, event_str)){
              cout << "Deleted successfully" << endl;
          } else {
              cout << "Event not found" << endl;
          }
      } else if (command_name == "Del" && event_str.empty()){
          const int count = db.DeleteDate({date_str});
          cout << "Deleted " << count << " events" << endl;
      }else if (command_name == "Find"){
          for(const auto& event: db.Find({date_str}))
            cout << event << endl;
      } else if (!command_name.empty()){
          cout << "Unknown command: " << command_name << endl;
          return 0;
      }
  	} catch(const runtime_error& e){
  		  cout << e.what() << endl;
        return 0;
  	}
  }

  return 0;
}