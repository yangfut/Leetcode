class Solution {
public:
    bool isVowel(char& c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), sum = 0;
        vector<int> preSum(n+1, 0);
        for(int i = 0; i < n; ++i){
            if(isVowel(words[i].front()) and isVowel(words[i].back())) sum++;
            preSum[i+1] = sum;
        }

        vector<int> res;
        for(auto& q : queries){
            int leftIdx = q[0];
            int rightIdx = q[1];
            res.push_back(preSum[rightIdx+1] - preSum[leftIdx]);
        }
        return res;
    }
};