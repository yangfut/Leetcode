class Solution {
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
        if(a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) ++freq[num];

        vector<pair<int,int>> freqVect(freq.begin(), freq.end());

        sort(freqVect.begin(), freqVect.end(), cmp);
        
        vector<int> output;
        for(const auto& p:freqVect){
            output.insert(output.end(), p.second, p.first);
        }
        
        return output;
    }
};