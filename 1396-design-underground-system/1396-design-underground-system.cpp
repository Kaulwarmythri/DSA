class UndergroundSystem {
    unordered_map<string, pair<long long, int>> travelTimes;
    
    unordered_map<int, pair<string,int>> startStations;
public:    
    UndergroundSystem() {
        travelTimes.clear();
        startStations.clear();
    }
    void checkIn(int id, string stn, int t) {
        
        if(startStations.find(id) != startStations.end()) return;
        
        startStations[id] = {stn, t};
    }
    
    void checkOut(int id, string stn, int t) {
        auto& info = startStations[id];

        string key = info.first + ":" + stn;
        
        int time = t - info.second;
        
        if(travelTimes.find(key) != travelTimes.end()) {
            
            auto& oldTimes = travelTimes[key];
            oldTimes.first += time;
            oldTimes.second++;
            
        } else
            travelTimes[key] = {time, 1};
        
        startStations.erase(id);
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        
        string key = startStation + ":" + endStation;
        
        auto& info = travelTimes[key];
        
        double avg = (double)info.first / (double)info.second;
        
        return avg;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */