#include <vector>

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff_arr(n, 0);
        for(vector<int>& shift : shifts){
            int st = shift[0], ed = shift[1];
            // Apply the difference
            diff_arr[st] = (shift[2] == 0) ? diff_arr[st] - 1 : diff_arr[st] + 1;

            // Remove the difference
            if(ed+1 < n){
                diff_arr[ed+1] = (shift[2] == 0) ? diff_arr[ed+1] + 1 : diff_arr[ed+1] - 1;
            }
        }

        int netShift = 0;
        for(int i = 0; i < n; ++i){
            netShift += diff_arr[i];
            int currPos = s[i] - 'a';
            int newPos = (currPos + netShift) % 26;
            if(newPos < 0) newPos += 26;
            s[i] = newPos + 'a';
        }
        return s;
    }
};