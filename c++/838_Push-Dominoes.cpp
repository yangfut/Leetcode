class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length();
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);

        int last_r_idx = (s[0] == 'R') ? 0 : -1;
        for(int i = 1; i < n; ++i){
            prefix[i] = last_r_idx;

            if(s[i] == 'R') last_r_idx = i;
            if(s[i] == 'L') last_r_idx = -1;
        }
        int last_l_idx = (s[n-1] == 'L') ? n-1 : -1;
        for(int i = n-2; i >=0; --i){
            suffix[i] = last_l_idx;

            if(s[i] == 'L') last_l_idx = i;
            if(s[i] == 'R') last_l_idx = -1;
        }

        for(int i = 0; i < n; ++i){
            if(s[i] == 'L' || s[i] == 'R') continue;

            int ll = suffix[i];
            int rr = prefix[i];

            if(rr == -1 && ll == -1) s[i] = '.';
            else if(rr == -1) s[i] = 'L';
            else if(ll == -1) s[i] = 'R';
            else if(i - rr < ll - i) s[i] = 'R';
            else if(i - rr > ll - i) s[i] = 'L';
            else s[i] = '.';
        }
        return s;
    }
};