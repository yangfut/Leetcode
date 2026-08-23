class Solution {
public:
    bool is_valid(int m, vector<int>& weights, int days){
        int used_days = 1, load = 0;
        for(int w : weights){
            if(load + w > m){
                ++used_days;
                load = 0;
            }
            load += w;
        }
        return used_days <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lhs = 1;
        int rhs = 0;
        for(int w : weights) {
            lhs = max(lhs, w);
            rhs += w;
        }

        while(lhs < rhs){
            int m = lhs + (rhs - lhs) / 2;
            if(is_valid(m, weights, days)){
                rhs = m;
            }else{
                lhs = m + 1;
            }
        }
        return lhs;
    }
};