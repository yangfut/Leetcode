class EventManager {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            // Pick smallest event ID for same priority
            // Pick highest priority for different priority
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> maxHeap;
    unordered_map<int, int> priority;

    EventManager(vector<vector<int>>& events) {
        for(auto& event : events){
            int eventId = event[0];
            int currPriority = event[1];
            priority[eventId] = currPriority;
            maxHeap.push({currPriority, eventId});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        priority[eventId] = newPriority;
        maxHeap.push({newPriority, eventId});
    }
    
    int pollHighest() {
        // lazy
        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();
            
            int eventId = top.second;
            int pri = top.first;
            if(priority[eventId] == pri) {
                priority.erase(eventId);
                return eventId;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */