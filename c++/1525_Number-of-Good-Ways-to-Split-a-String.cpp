class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        unordered_set<char> collection;
        vector<int> left_count(n, 0);
        vector<int> right_count(n, 0);

        for(int idx = 0; idx < n; ++idx){
            collection.insert(s[idx]);
            left_count[idx] = collection.size();
        }

        collection.clear();

        for(int idx = n-1; idx >=0; --idx){
            collection.insert(s[idx]);
            right_count[idx] = collection.size();
        }

        int numOfGoodSplits = 0;

        for(int idx = 0; idx < n-1; ++idx){
            if(left_count[idx] == right_count[idx+1]) ++numOfGoodSplits;
        }

        return numOfGoodSplits;
    }
};

class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        // unordered_set<char> collection;
        int left_hash[26], right_hash[26];
        int left_dist = 0, right_dist = 0, numOfGoodSplits = 0;

        for(int idx = 0; idx < n; ++idx){
            ++right_hash[s[idx]-'a'];
            if(right_hash[s[idx]-'a'] == 1) ++right_dist;
        } 

        for(int idx = 0; idx < n; ++idx){
            ++left_hash[s[idx]-'a'];
            if(left_hash[s[idx]-'a'] == 1) ++left_dist;
            --right_hash[s[idx]-'a'];
            if(right_hash[s[idx]-'a'] == 0) --right_dist;
            
            if(left_dist == right_dist) ++numOfGoodSplits;
        }


        return numOfGoodSplits;
    }
};