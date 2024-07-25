class Solution {
    void convertToMappedNum(vector<int>& mapping, vector<int>& nums, vector<int>& temp_nums){
        for(int i = 0; i < nums.size(); ++i){
            int temp = nums[i];
            int ten = 1;
            do{
                int digit = temp % 10;
                temp_nums[i] += (mapping[digit]*ten);
                ten *= 10;
                temp /= 10;
            }while(temp != 0);
        }
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> temp_nums(nums.size(), 0);
        vector<int> temp_idx(nums.size(), 0);

        // convert nums to mapped values
        convertToMappedNum(mapping, nums, temp_nums);

        // initialize indices
        for(int i = 0; i < nums.size(); ++i) temp_idx[i] = i;

        // relative sort
        sort(temp_idx.begin(), temp_idx.end(), [&temp_nums](int a, int b){
            if(temp_nums[a] < temp_nums[b]) return true;
            else if(temp_nums[a] > temp_nums[b]) return false;
            else return a < b; // Maintain relative order
        });

        for(int i = 0; i < nums.size(); ++i){
            // take temp_nums as output vector
            temp_nums[i] = nums[temp_idx[i]];
        }

        return temp_nums;
    }
};