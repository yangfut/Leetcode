class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int threshold = n/3;
        unordered_map<int, int> count;
        for(const int &ele : nums){
            count[ele]++;
        }
        vector<int> output;
        for(const auto &it : count){
            if(it.second > threshold) output.push_back(it.first);
        }
        return output;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int lcount = 0, rcount = 0, n = nums.size();
        int lval = INT_MIN, rval = INT_MIN;

        // find top 2 majority elements
        for(int i = 0; i < n; ++i){
            if(lcount == 0 && nums[i] != rval){
                lcount = 1;
                lval = nums[i];
            }else if(rcount == 0 && nums[i] != lval){
                rcount = 1;
                rval = nums[i];
            }else if(nums[i] == lval){
                ++lcount;
            }else if(nums[i] == rval){
                ++rcount;
            }else{
                --lcount;
                --rcount;
            }
        }

        // check these elements satisfy n/3 times
        lcount = 0, rcount = 0;
        int mm = (n/3)+1;
        vector<int> ans;
        for(int i = 0; i < n; ++i){
            if(nums[i] == lval) ++lcount;
            if(nums[i] == rval) ++rcount;
        }
        if(lcount >= mm) ans.push_back(lval);
        if(rcount >= mm) ans.push_back(rval);
        return ans;
    }
};