#include <vector>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int empty = -1;
        int k = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == val){
                ++k;
                if(empty == -1) empty = i;
            }else if(empty != -1){
                nums[empty++] = nums[i];
            }
        }
		return nums.size() - k;
    }
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ed = 0;
        for(int st = 0; st < nums.size(); ++st){
            if(nums[st] == val) continue;
            nums[ed++] = nums[st];
        }
        return ed;
    }
};