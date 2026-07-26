class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=gas.size()-1, ed=0;
        int sum=gas[st]-cost[st];
        while(ed<st){
            if(sum<=0){
                st--;
                sum+=gas[st]-cost[st];
            }else{
                sum+=gas[ed]-cost[ed];
                ed+=1;
            }
        }
        return (sum>=0)?st:-1;
    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), sum = 0;
        vector<int> remain(n);
        for(int idx = 0; idx < n; ++idx) {
            remain[idx] = gas[idx] - cost[idx];
            sum += remain[idx];
        }

        if(sum < 0) return -1;

        // if the current index is the proper starting index, then all the traversal must be greater than zero
        // otherwise, pick the index next to the negative sum

        int startIdx = 0; 
        sum = 0;
        for(int idx = 0; idx < n; ++idx){
            sum += remain[idx];
            if(sum < 0){
                startIdx = idx + 1;
                sum = 0;
            }
        }

        return startIdx;

    }
};

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st = 0, ed = 0, n = gas.size(), curr = 0;
        // true: go right; false: go left
        bool dir = true; 
        do{
            if(dir) curr += (gas[ed] - cost[ed]);
            else curr += (gas[st] - cost[st]);

            // next direction
            if(curr < 0) {
                --st;
                if(st < 0) st = n-1;
                dir = false;
            } else {
                ++ed;
                if(ed == n) ed = 0;
                dir = true;
            } 
        }while(st != ed);
        return (curr >= 0) ? st : -1;
    }
};