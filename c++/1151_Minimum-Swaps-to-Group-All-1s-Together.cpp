class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int cnt = 0, wSize = 0;
        for(int d : data) if(d == 1) ++wSize;
        for(int i = 0; i < wSize; ++i) if(data[i] == 1) ++cnt;
        int minSwap = wSize - cnt;
        for(int i = wSize; i < n; ++i){
            if(data[i-wSize] == 1) --cnt;
            if(data[i] == 1) ++cnt;
            minSwap = min(minSwap, wSize - cnt);
        }
        return minSwap;
    }
};