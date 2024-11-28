class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> count;
        int rowNum = 0;
        for(int ele : nums) ++count[ele];
        for(const auto &[num, times] : count) rowNum = max(rowNum, times);

        vector<vector<int>> re(rowNum, vector<int>());
        for(const auto &[num, times]: count){
            for(int j = 0; j < times; ++j){
                re[j].push_back(num);
            }
        }
        return re;
    }
};