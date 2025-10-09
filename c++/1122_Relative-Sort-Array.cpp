class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int count[1001];
        vector<int> ans;
        ans.reserve(arr1.size());

        for(int num : arr1) ++count[num];
        for(int num : arr2) {
            while(count[num]){
                ans.push_back(num);
                --count[num];
            }
        }

        for(int i = 0; i < 1001; ++i){
            while(count[i]){
                ans.push_back(i);
                --count[i];
            }
        }

        return ans;
    }
};