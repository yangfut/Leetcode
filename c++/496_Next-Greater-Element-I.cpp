class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //Monotonic stack(monotonic decreasing from the back side)
        stack<int>st;
        unordered_map<int,int>map;
        vector<int>res(nums1.size());
        
        for(int i=0;i<nums1.size();++i) map[nums1[i]]=i;
        for(int i=nums2.size()-1;i>=0;--i){
            
            //Create monotonic descreasing order in stack
            //Pop element if nums[i] is greater to keep the order in decreasing
            while(!st.empty()&&nums2[i]>nums2[st.top()]) st.pop();

            if(map.count(nums2[i])){
                int idx_nums1 = map[nums2[i]];
                res[idx_nums1] = st.empty()?-1:nums2[st.top()];
            }
            st.push(i);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>nge(nums2.size(), -1);
        unordered_map<int,int> toNum2Idx;
        
        stack<int> st;
        for(int i = nums2.size()-1; i >= 0; --i){
            
            toNum2Idx[nums2[i]] = i;

            while(!st.empty() && nums2[i] > nums2[st.top()]){
                st.pop();
            }

            nge[i] = st.empty() ? -1 : nums2[st.top()];
            st.push(i);
        }
        vector<int> ans;
        for(int i = 0; i < nums1.size(); ++i){
            int j = toNum2Idx[nums1[i]];
            ans.push_back(nge[j]);
        }
        return ans;
    }
};