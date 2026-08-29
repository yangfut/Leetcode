// TC: O(N), SC:O(1)
// Beats 100% in Time and 99.18% in Memory
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int currSize = 1;
        // 1: up, 0: invalid, -1: down
        int dir = 0, nextDir = 0;
        int maxSize = currSize;
        for(int i = 1; i < n; ++i){
            int diff = arr[i] - arr[i-1];
            if(diff < 0) nextDir = -1;
            else if(diff > 0) nextDir = 1;
            else nextDir = 0;

            if(nextDir == 0) currSize = 0;
            if(nextDir + dir != 0) currSize = 1;
            dir = nextDir;
            ++currSize;
            maxSize = max(maxSize, currSize);
        }
        return maxSize;
    }
};


// TC: O(N), SC:O(N)
// Beats 14% in Time and 10% in Memory
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int wSize = 1;
        // 1: up, 0: invalid, -1: down
        int dir = 0, nextDir = 0;
        deque<int> deq;
        deq.push_back(arr.front());
        int maxSize = deq.size();
        for(int i = 1; i < n; ++i){
            int diff = arr[i] - deq.back();
            if(diff < 0) nextDir = -1;
            else if(diff > 0) nextDir = 1;
            else nextDir = 0;

            if(nextDir == 0) while(!deq.empty()) deq.pop_front();
            if(nextDir + dir != 0) while(deq.size() > 1) deq.pop_front();
            dir = nextDir;
            deq.push_back(arr[i]);
            maxSize = max(maxSize, (int)deq.size());
        }
        return maxSize;
    }
};