class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s += s;

        // two target strings
        // "0101010101" -> even index is zero and odd index is one
        // "1010101010" -> even index is one and odd index is zero

        int diff = 0;
        // get the difference
        for(int idx = 0; idx < n; ++idx){
            
            char c = (idx%2 == 0) ? '0' : '1';
            // compare with target 0
            if(s[idx] != c) ++diff;
        }
        int minv = min(diff, n-diff);

        // sliding window
        for(int idx = 1; idx < n; ++idx){
            char prefix_c = ((idx-1)%2 == 0) ? '0' : '1';
            char postfix_c = ((idx+n-1)%2 == 0) ? '0' : '1';

            // Type-1 operation: remove prefix element and add postfix element
            if(s[idx-1] != prefix_c) --diff;
            if(s[idx+n-1] != postfix_c) ++diff;

            // compare the result between start_with_zero and start_with_one
            minv = min(minv, diff);
            minv = min(minv, n - diff);
        }

        return minv;

    }
};