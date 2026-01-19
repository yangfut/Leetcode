class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        int maxNum = -1;
        for(int num : arr) ++freq[num];
        for(auto& p : freq){
            if(p.first == p.second) maxNum = max(maxNum, p.first);
        }
        return maxNum;
    }
};