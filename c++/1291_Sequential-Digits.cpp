class Solution {
    void solve(vector<int> &res, string s, int low, int high){
        int num = stoi(s);
        if(num > high) return;

        if(num >= low && num <= high){
            res.push_back(num);
        }

        int last_digit = s.back() - '0';
        if(last_digit < 9){
            // increment one for all digits
            solve(res, s + char(last_digit + 1 + '0'), low, high);
        }
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int i = 1; i <= 9; i++){
            solve(res, to_string(i), low, high);
        }

        sort(res.begin(), res.end());
        return res;
    }
};