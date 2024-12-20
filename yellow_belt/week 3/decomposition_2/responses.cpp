#include "responses.h"
#include <iostream>


using namespace std;




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