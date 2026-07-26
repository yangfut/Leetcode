class Solution {
public:
    bool canConstruct(string s, int k) {
        // twos: twoes >= k
        // ones: ones <= twoes
        int freq[26], twoes = 0, ones = 0;
        for(char& c : s) ++freq[c-'a'];
        for(int f : freq){
            if(f == 0) continue;
            twoes += (f / 2);
            ones += (f % 2);
        }
        if(ones > k || (ones + 2*twoes) < k) return false;
        return true;
    }
};