class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> record;
    unordered_map<string, unordered_map<string, pair<int,int>>> time_collection;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id] = {stationName, t};    
    }
    
    void checkOut(int id, string stationName, int t) {
        int travelTime = t - record[id].second;
        string startStation = record[id].first;
        record.erase(id);
        
        auto &p = time_collection[startStation][stationName];
        p.first += travelTime;
        p.second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        if(time_collection[startStation].find(endStation) == time_collection[startStation].end()){
            return 0.0;
        }

        auto &data = time_collection[startStation][endStation];
        return static_cast<double>(data.first) / (data.second);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */