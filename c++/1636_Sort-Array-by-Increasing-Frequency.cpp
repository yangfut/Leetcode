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

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) ++freq[num];

        vector<pair<int,int>> freqVect(freq.begin(), freq.end());
        sort(freqVect.begin(), freqVect.end(), [](const auto& a, const auto& b){
            return (a.second == b.second) ? a.first > b.first : a.second < b.second;
        });
        vector<int> res;
        res.reserve(nums.size());
        for(auto& [num, count] : freqVect){
            res.insert(res.end(), count, num);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num : nums) ++freq[num];
        
        // [&] lambda capture everything by reference
        // [] lambda capture nothing
        // [-] lambda capture everything by copied value
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b){
            return (freq[a] == freq[b]) ? a > b : freq[a] < freq[b];
        });
        return nums;
    }
};