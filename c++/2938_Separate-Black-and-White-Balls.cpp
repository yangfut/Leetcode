class Solution {
public:
    long long minimumSteps(string s) {
        int maj = 0;
        for(char c : s){
            if(c == '0') --maj;
            else ++maj;
        }

        // always pick the fewer one
        char tar = (maj < 0) ? '1' : '0';
        long long steps = 0;
        int cnt = 0, n = s.length();
        for(int i = 0; i < s.length(); ++i){
            if(s[i] != tar) continue;
            if(tar == '0'){
                steps += i - cnt;
            }else{
                steps += (n-1-cnt-i);
            }
            ++cnt;
        }
        return steps;

    }
};

class Solution {
public:
    long long minimumSteps(string s) {
        // find bad pairs - zeros at left, ones at right
        long long steps = 0;
        int ones = 0;
        for(char c : s){
            if(c == '1'){
                ++ones;
            }else{
                steps += ones;
            }
        }
        return steps;
    }
};