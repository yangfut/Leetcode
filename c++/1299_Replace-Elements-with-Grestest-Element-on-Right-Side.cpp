class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int fwd_max = -1;
        int n = arr.size();
        for(int i=n-1; i>=0; --i){
            
            int org = arr[i];
            arr[i] = fwd_max;
            fwd_max = max(fwd_max, org);
        }
        return arr;
    }
};