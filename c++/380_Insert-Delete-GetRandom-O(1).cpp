#include <set>
#include <stdlib.h> //rand()

class RandomizedSet {
public:
    //#1 Set
    /*
    unordered_set<int> s;

    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(s.find(val)!=s.end()) return false;
        s.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(s.find(val)==s.end()) return false;
        s.erase(val);
        return true;
    }
    
    int getRandom() {
        return *next(s.begin(), rand()%s.size());
    }
    */

    //#2 Map and Vector
    unordered_map<int, int>hash;
    vector<int>vec;

    RandomizedSet() {}
    
    bool insert(int val) {
        if(hash.count(val)) return false;
        vec.push_back(val);
        hash.insert({val, vec.size()-1});
        return true;
    }
    
    bool remove(int val) {
        if(!hash.count(val)) return false;
        int idx=hash[val];

        //Update hash for the last element
        hash[vec.back()]=idx;
        vec[idx]=vec.back();
        vec.pop_back();

        hash.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand()%vec.size();
        return vec[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */