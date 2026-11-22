class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        vector<bool> reachable(n,false);
        reachable[0] = true;
        // To complete O(1) search, we need to count the reachable stands in the window
        int cnt = 0;
        for(int i = 1; i < n; ++i){
            int rightmost = i - minJump;
            if(rightmost >= 0 && reachable[rightmost]){
                ++cnt;
            }

            int leftmost = i - maxJump - 1;
            if(leftmost >= 0 && reachable[leftmost]){
                --cnt;
            }

            reachable[i] = (s[i] == '0' && cnt > 0) ? true : false;
        }
        return reachable.back();
    }
};