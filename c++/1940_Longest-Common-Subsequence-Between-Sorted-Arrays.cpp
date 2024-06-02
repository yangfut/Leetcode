class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        // O(M*N*logM) -> iteration + binary search
        vector<int> common_subseq;
        unordered_map<int,int> common_count;

        for(int ele : arrays[0]){
            bool isFound = true;
            for(int i = 1; i < arrays.size(); ++i){
                int idx = std::lower_bound(arrays[i].begin(), arrays[i].end(), ele) - arrays[i].begin();

                if(idx == arrays[i].size() || arrays[i][idx] != ele){
                    isFound = false;
                    break;
                }
                int val = arrays[i][idx];
                if(common_count.count(val)){
                    int shift = common_count[val];
                    if(idx+shift >= arrays[i].size() || arrays[i][idx+shift] != ele){
                        isFound = false;
                        break;
                    }
                }
            }

            if(isFound){
                common_subseq.push_back(ele);
                ++common_count[ele];
            }
        }
        return common_subseq;

    }
};