class MyHashMap {
public:
    unordered_map<int, int> table;

    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        table[key] = value;    
    }
    
    int get(int key) {
        if(!table.count(key)) return -1;

        return table[key];
    }
    
    void remove(int key) {
        table.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */