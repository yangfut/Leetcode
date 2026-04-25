class LogSystem {
public:
    vector<pair<string, int>> log;
    unordered_map<string, int> granMap = {
        {"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}
    };

    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        log.emplace_back(timestamp, id);
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> output;
        int len = granMap[granularity];
        string s = start.substr(0, len);
        string e = end.substr(0, len);
        for(auto& [t, id] : log){
            string validTime = t.substr(0, len);
            if(validTime >= s && validTime <= e) output.push_back(id);
        }
        return output;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */

 class LogSystem {
public:
    multimap<string, int> log;
    unordered_map<string, int> granMap = {
        {"Year", 4}, {"Month", 7}, {"Day", 10}, {"Hour", 13}, {"Minute", 16}, {"Second", 19}
    };

    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        log.insert({timestamp, id});
    }
    
    vector<int> retrieve(string start, string end, string granularity) {
        vector<int> output;
        int len = granMap[granularity];
        string s = start.substr(0, len);
        string e = end.substr(0, len) + "~";
        auto sIter = log.lower_bound(s);
        auto eIter = log.upper_bound(e);
        while(sIter != eIter){
            output.push_back(sIter->second);
            ++sIter;
        }
        return output;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(start,end,granularity);
 */