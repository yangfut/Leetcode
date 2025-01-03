class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> arr(2, vector<int>());
        int offset = 1000;
        int hashmap[2001] = {0};

        for(int idx = 0; idx < nums1.size(); idx++){
            if(hashmap[nums1[idx]+offset] == 2) {
                hashmap[nums1[idx]+offset] = -1;
            }else if(hashmap[nums1[idx]+offset] == 0) {
                hashmap[nums1[idx]+offset] = 1;
            }
        }

        for(int idx = 0; idx < nums2.size(); idx++){
            if(hashmap[nums2[idx]+offset] == 1) {
                hashmap[nums2[idx]+offset] = -1;
            }else if (hashmap[nums2[idx]+offset] == 0){
                hashmap[nums2[idx]+offset] = 2;
            }
        }



        for(int idx = 0; idx <= 2*offset; idx++){
            if(hashmap[idx] == 1) {
                arr[0].push_back(idx-offset);
            }

            if(hashmap[idx] == 2) {
                arr[1].push_back(idx-offset);
            }
        }
        return arr;
    }
};

#define INPUT_MAX 1000
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> output(2, vector<int>());
        int hash[2*INPUT_MAX+1] = {0};
        int offset = 1000;
        
        // bucket sort
        for(int &ele : nums1){
            hash[ele+offset] |= 1; //bit0
        }

        for(int &ele:nums2){
            hash[ele+offset] |= 2; //bit1
        }

        for(int i = 0; i < (2*INPUT_MAX+1); ++i){
            if(hash[i] == 1){
                output[0].push_back(i-offset);
            }

            if(hash[i] == 2){
                output[1].push_back(i-offset);
            }
        }
        return output;

    }
};