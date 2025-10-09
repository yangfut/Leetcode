class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0); //fill with [0, 1, 2, 3, ..., n-1]
        sort(indices.begin(), indices.end(), [&](int a, int b){
            return heights[a] > heights[b];
        });
        vector<string> sorted_names;
        sorted_names.reserve(n);
        for(int i : indices) sorted_names.push_back(names[i]);
        return sorted_names;
    }
};