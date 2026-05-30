class SnapshotArray {
public:
    vector<vector<int>> val;
    unordered_map<int,unordered_map<int,int>> id;
    int curr;
    SnapshotArray(int length) {
        curr = 0;
        val = vector<vector<int>>(length, vector<int>());
    }
    
    void set(int index, int value) {
        if(val[index].empty() || val[index].back() != curr) {
            val[index].push_back(curr);
        }
        
        id[curr][index] = value;
    }
    
    int snap() {
        return curr++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(val[index].begin(), val[index].end(), snap_id);
        if(it == val[index].begin()) return 0;

        int currId = *(prev(it));
        return id[currId][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

 class SnapshotArray {
public:
    vector<vector<pair<int,int>>> hist;
    int id = 0;
    SnapshotArray(int length) {
        hist = vector<vector<pair<int,int>>> (length, vector<pair<int,int>>{{0,0}});
    }
    
    void set(int index, int val) {
        auto [lastId, lastVal] = hist[index].back();
        if(lastId != id){
            hist[index].emplace_back(id, val);
        }else{
            hist[index].back().second = val;
        }
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(hist[index].begin(), hist[index].end(), make_pair(snap_id, INT_MAX));
        --it;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */