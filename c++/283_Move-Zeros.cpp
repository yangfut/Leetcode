class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        int z = 0, nz = 0;
        while(nz < n){
            
            while(nz < n && nums[nz] == 0) ++nz;
            while(z < n && nums[z] != 0) ++z;

            if(nz < n && z < nz) swap(nums[z], nums[nz]);
            ++nz;
        }
    }
};