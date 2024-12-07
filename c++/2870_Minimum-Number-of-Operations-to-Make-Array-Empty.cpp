class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int &ele : nums){
            freq[ele]++;
        }

        int ops = 0;
        for(const auto &[_, _times] : freq){
            if(_times == 1) return -1;

            // 4: 1+1(2,2)
            // 5: 1+1(3,2)
            // 6: 2(3,3)
            ops += _times / 3 + (_times % 3 != 0);
        }
        return ops;
    }
};