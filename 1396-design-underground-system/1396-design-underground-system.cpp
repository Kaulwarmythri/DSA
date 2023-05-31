class UndergroundSystem {
    unordered_map<int, pair<string , int>> startsNTimes;
    unordered_map<string, pair<long long, int>> travelTimes;
public:
    UndergroundSystem() {
        startsNTimes.clear();
        travelTimes.clear();
    }
    
    void checkIn(int id, string stn, int t) {
        if(startsNTimes.find(id) != startsNTimes.end()) return;
        
        startsNTimes[id] = {stn, t};
    }
    
    void checkOut(int id, string stn, int t) {
        auto info = startsNTimes[id];
        
        string key = info.first + ":" + stn;
        
        if(travelTimes.find(key) != travelTimes.end()) {
            travelTimes[key].first += t - info.second;
            travelTimes[key].second++;
        } else {
            travelTimes[key] = {t - info.second, 1};
        }
        startsNTimes.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + ":" + endStation;
        
        auto &info = travelTimes[key];
        
        return (double) info.first / (double) info.second;
    }
};