#include <vector>
#include <unordered_map>

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        // total pairs where i < j
        long long total_pairs = static_cast<long long>(n) * (n-1) / 2;
        long long good_pairs = 0;
        unordered_map<int,int> diff_count;
        for(int i = 0; i < n; ++i){
            int val = i - nums[i];
            good_pairs += diff_count[val];
            ++diff_count[val];
        }

        return total_pairs - good_pairs;
    }
};