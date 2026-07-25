class Solution {
public:
    vector<int> findBuildings(vector<int>& h) {
        vector<int> ans;
        int n = h.size(), prev = INT_MIN;
        for(int i = n-1; i >= 0; --i){
            if(h[i] > prev) ans.push_back(i);
            prev = max(h[i], prev);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};