class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 1) return;
        // n element sort + reorder with two pointers
        int n = nums.size();
        int m = (n+1)/2;
        nth_element(nums.begin(), nums.begin()+m, nums.end());
        vector<int> left(nums.begin(), nums.begin()+m);
        vector<int> right(nums.begin()+m, nums.end());
        
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0){
                nums[i] = left.back();
                left.pop_back();
            }else{
                nums[i] = right.back();
                right.pop_back();
            }
        }
        
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool pattern = true;
        for(int i = 0; i < nums.size()-1; ++i){
            // In wiggle pattern, you only need to find the local maximum number in these three numbers
            if (pattern != (nums[i] <= nums[i+1])){
                swap(nums[i], nums[i+1]);
            }
            pattern = !pattern;
        }
    }
};