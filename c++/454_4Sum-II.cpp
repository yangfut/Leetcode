class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mp;

        int count=0;
        //A+B = - (C+D)
        for(int &it1:nums1){
            for(int &it2:nums2){
                mp[it1+it2]++;
            }
        }

        for(int &it3:nums3){
            for(int &it4:nums4){
                if(mp.count(0-it3-it4)) count+=mp[0-it3-it4];
            }
        }
        return count;
    }
};