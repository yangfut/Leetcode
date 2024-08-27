class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>count;
        
        for(int num : nums){
            count[num]++;
        }

        int ans = 0;
        for(auto it : count){
            int freq = it.second;
            
            if(freq > 1){
                ans += (freq * (freq-1))/2;
            }
            
        }
        return ans;
    }
};