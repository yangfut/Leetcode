class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size(), minv = INT_MAX;
        sort(arr.begin(), arr.end());

        vector<int> abs_values(n-1, 0);
        vector<vector<int>> answer;
        for(int idx = 0; idx < n-1; ++idx){
            abs_values[idx] = arr[idx+1] - arr[idx];
            minv = min(minv, abs_values[idx]);
        }

        for(int idx = 0; idx < n-1; ++idx){
            if(abs_values[idx] == minv) answer.push_back({arr[idx], arr[idx+1]});
        }

        return answer;
    }
};