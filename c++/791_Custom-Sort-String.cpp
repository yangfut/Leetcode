class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> rank;
        for(int i = 0; i < order.length(); ++i){
            rank.emplace(order[i], i);
        }
        // padding rank
        int invalid_rank = order.length();
        for(char& c : s) {
            if(rank.count(c)) continue;
            rank.emplace(c, ++invalid_rank);
        }
        sort(s.begin(), s.end(), [&](const char& a, const char& b){
            return rank[a] < rank[b];
        });
        return s;
    }
};