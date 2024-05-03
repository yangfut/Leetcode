class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        int n = triplets.size();
        unordered_set<int> result;
        for(int idx = 0; idx < n; ++idx){
            bool isMatch = false, isOver = false;
            int match[] = {0, 0, 0};
            for(int k = 0; k < 3; ++k){
                if(triplets[idx][k] > target[k]){
                    isOver = true;
                    break;
                }
                if(triplets[idx][k] == target[k]){
                    match[k] = 1;
                    isMatch = true;
                }
            }

            if(isMatch && !isOver){
                for(int k = 0; k < 3; ++k){
                    if(match[k]) result.insert(k);
                }
            }
        }

        return (result.size() == 3) ? true : false;
    }
};

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<int> arr(3, 0);
        for(int idx = 0; idx < n; ++idx){
            if(triplets[idx][0] <= target[0] && triplets[idx][1] <= target[1] && triplets[idx][2] <= target[2]){
                arr[0] = max(arr[0], triplets[idx][0]);
                arr[1] = max(arr[1], triplets[idx][1]);
                arr[2] = max(arr[2], triplets[idx][2]);
            }
        }
        return arr == target;
    }
};