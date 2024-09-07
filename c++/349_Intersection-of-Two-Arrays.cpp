class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // #1 hash table(TC:O(N+M), OC:O(N))
        // unordered_set<int> uni;
        // vector<int> ans;
        // for(int num : nums1) uni.insert(num);
        // for(int num : nums2) {
        //     if(uni.count(num)){
        //         ans.push_back(num);
        //         uni.erase(num);
        //     }
        // }

        // #2 sorting(TC:O(NlogN+MlogN), OC:O(K))
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();

        while(i < n && j < m) {
            // compare values first
            if(nums1[i] > nums2[j]) ++j;
            else if(nums1[i] < nums2[j]) ++i;
            else{
                // check the intersection is unique
                if(ans.size() == 0 || ans.back() < nums1[i]){
                    ans.push_back(nums1[i]);
                }
                ++i;
                ++j;
            }
        }

        return ans;
    }
};