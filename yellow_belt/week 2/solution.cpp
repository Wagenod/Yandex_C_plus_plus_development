#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
    string operation_code;
    is >> operation_code;
    if (operation_code == "NEW_BUS"){
        q.type = QueryType::NewBus;
        is >> q.bus;
        int stop_count;
        is >> stop_count;
        q.stops.clear();
        for(int i=0; i<stop_count; i++){
          string stop;
          is >> stop;
          q.stops.push_back(stop);
        }
    } 
    else if (operation_code == "BUSES_FOR_STOP"){
        q.type = QueryType::BusesForStop;
        is >> q.stop;
    } 
    else if (operation_code == "STOPS_FOR_BUS"){
        q.type = QueryType::StopsForBus;
        is >> q.bus;
    } 
    else if (operation_code == "ALL_BUSES"){
        q.type = QueryType::AllBuses;
    }

  return is;
}

struct BusesForStopResponse {
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.buses.size() == 0) {
      os << "No stop" << endl;
  } else {
      for (const string& bus : r.buses) {
          os << bus << " ";
      }
      os << endl;
  }
  return os;
}

struct StopsForBusResponse {
    string bus;
    vector<string> stops;
    map<string, vector<string>> stops_to_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
    if (r.stops.size() == 0) {
        os << "No bus" << endl;
    } else {
        for (const string& stop : r.stops) {
            os << "Stop " << stop << ": ";
            if (r.stops_to_buses.at(stop).size() == 1) {
                os << "no interchange";
            } else {
                for (const string& other_bus : r.stops_to_buses.at(stop)) {
                    if (r.bus != other_bus) {
                       cout << other_bus << " ";
                    }
                }
            }
            os << endl;
        }
    }
  return os;
}

struct AllBusesResponse {
    map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
    if (r.buses_to_stops.size() == 0) {
        os << "No buses" << endl;
    } else {
        for (const auto& bus_item : r.buses_to_stops) {
            os << "Bus " << bus_item.first << ": ";
            for (const string& stop : bus_item.second) {
                os << stop << " ";
            }
            os << endl;
        }
    }
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      for (const string& stop: stops){
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
      }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
      if (stops_to_buses.count(stop) == 0) {
          return {};
      } else {
          return {stops_to_buses.at(stop)};
      }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
      if (buses_to_stops.count(bus) == 0) {
          return {{}, {}};
      } else {}
      return {bus, buses_to_stops.at(bus), stops_to_buses};
  }

  AllBusesResponse GetAllBuses() const {
    return {buses_to_stops};
  }

private:
  map<string, vector<string>> buses_to_stops, stops_to_buses;
};




int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }

  }
        
  return 0;
}