class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        vector<int> vec(nums1.size());
        for(int i = 0; i < nums2.size(); ++i) map[nums2[i]] = i;
        for(int i = 0; i < nums1.size(); ++i) vec[i] = map[nums1[i]];
        return vec;
    }
};