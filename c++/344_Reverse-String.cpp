class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int i = 0; i <= (n-1-i); ++i){
            swap(s[i], s[n-1-i]);
        }
    }
};