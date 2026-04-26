class TimeMap {
public:
    class Node{
    public:
        vector<pair<int, string>> pair_vec;
        int prev;
        Node(){
            prev = 0;
        }
    };
    
    map<string, Node*> map;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        pair<int,string> p;
        p.first=timestamp;
        p.second=value;

        if(map.count(key)){
            map[key]->pair_vec.push_back(p);
        }else{
            Node *node = new Node();
            node->pair_vec.push_back(p);
            map[key] = node;
        }
    }
    
    string get(string key, int timestamp) {
        if(!map.count(key)) return "";
        if(map[key]->pair_vec[0].first>timestamp) return "";

        int low = map[key]->prev;
        int high = map[key]->pair_vec.size()-1;
        while(low<high){
            int mid = low + (high-low)/2;
            if(map[key]->pair_vec[mid].first == timestamp) return map[key]->pair_vec[mid].second;
            else if(map[key]->pair_vec[mid].first > timestamp) high = mid;
            else low = mid+1;
        }
        if(map[key]->pair_vec[low].first>timestamp) --low;
        map[key]->prev = low;
        return map[key]->pair_vec[low].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

 class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if(!mp.count(key)) return "";
        vector<pair<int, string>>& val = mp[key];
        
        int hi = val.size();
        int lo = 0;
        // BS for >= result
        while(lo < hi){
            int md = lo + ((hi - lo) / 2);
            int mdTimeStamp = val[md].first;
            if(mdTimeStamp == timestamp) return val[md].second;
            else if(mdTimeStamp > timestamp) hi = md;
            else if(mdTimeStamp < timestamp) lo = md+1;
        }
        
        if(lo == 0) return "";
        return val[lo-1].second;

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */