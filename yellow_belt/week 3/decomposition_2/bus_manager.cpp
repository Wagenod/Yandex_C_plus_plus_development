
#include "bus_manager.h"

using namespace std;

// BusManager::BusManager(){
// 	buses_to_stops = {};
// 	stops_to_buses = {};
// }

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
      for (const string& stop: stops){
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
      }
}


BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
      if (stops_to_buses.count(stop) == 0) {
          return {};
      } else {
          return {stops_to_buses.at(stop)};
      }
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
      if (buses_to_stops.count(bus) == 0) {
          return {{}, {}};
      } else {}
      return {bus, buses_to_stops.at(bus), stops_to_buses};
}

AllBusesResponse BusManager::GetAllBuses() const {
    return {buses_to_stops};
}
