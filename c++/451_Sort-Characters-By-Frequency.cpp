class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,int>> maxheap;
        unordered_map<char,int> freq;
        for(char &c : s){
            ++freq[c];
        }

        for(auto &[_char, _freq] : freq){
            maxheap.push({_freq, _char});
        }

        string res;
        while(!maxheap.empty()){
            auto &p = maxheap.top();
            for(int i = 0; i < p.first; ++i) res += p.second;
            maxheap.pop();
        }
        return res;
    }
};