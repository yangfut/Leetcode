class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < ((1 << k) + k-1)) return false;

        int d = 0, mask = (1 << k) - 1;
        unordered_set<int> collection;
        for(int i = 0; i < s.length(); ++i){
            
            d <<= 1;
            d &= mask;
            d |= (s[i] == '0') ? 0 : 1;
            if(i >= k-1){
                collection.insert(d);
                // cout << d << endl;
            }
        }

        return collection.size() == (1 << k);
    }
};