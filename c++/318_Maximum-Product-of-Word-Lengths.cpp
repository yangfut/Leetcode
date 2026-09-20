class Solution {
public:
    int getBits(string& s){
        int bits = 0;
        for(char& c : s){
            int offset = c - 'a';
            bits |= 1 << offset;
        }
        return bits;
    }
    int maxProduct(vector<string>& words) {
        int maxP = 0;
        int n = words.size();
        vector<int> hash(n);
        for(int i = 0; i < n; ++i){
            hash[i] = getBits(words[i]);
        }

        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                int v1 = hash[i];
                int v2 = hash[j];
                if((v1 & v2) == 0){
                    // No collision
                    int size1 = words[i].length();
                    int size2 = words[j].length();
                    maxP = max(maxP, size1*size2);
                }
            }
        }
        return maxP;
    }
};