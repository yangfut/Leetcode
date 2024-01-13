class Solution {
public:
    Solution(vector<int>& nums) {
        original = nums;
        n = nums.size();
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = original;
        for(int i=n-1; i>0; i--){
            int j=rand()%(i+1); //%0 is undefined-behavior(UB)
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }

private:
    vector<int> original;
    int n;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */