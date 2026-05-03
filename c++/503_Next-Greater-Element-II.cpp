class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int k = 0; k < 2; ++k){
            for(int i = n-1; i >= 0; --i){
                int val = nums[i];
                while(!st.empty() && val >= st.top()) st.pop();
                nge[i] = st.empty() ? -1 : st.top();
                st.push(val);
            }
        }
        return nge;
    }
};