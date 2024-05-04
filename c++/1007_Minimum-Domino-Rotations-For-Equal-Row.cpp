class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Return the minimum number of rotations so that all the values in tops are the same, 
        // or all the values in bottoms are the same.

        // find common number from tops[i] and bottoms[i]
        int a = tops[0], b = bottoms[0], n = tops.size();
        if(n == 1) return 0;

        for(int idx = 1; idx < n; ++idx){
            if(a != -1){
                if(!(a == tops[idx] || a == bottoms[idx])) a = -1;
            }

            if(b != -1){
                if(!(b == tops[idx] || b == bottoms[idx])) b = -1;
            }
            // No common numbers in either tops[i] or bottoms[i]
            if(a == -1 && b == -1) return -1;
        }

        int top_a = 0, top_b = 0, bot_a = 0, bot_b = 0;
        for(int idx = 0; idx < n; ++idx){
            if(tops[idx] == a) ++top_a;
            if(tops[idx] == b) ++top_b;
            if(bottoms[idx] == a) ++bot_a;
            if(bottoms[idx] == b) ++bot_b;
        }

        return n - max(max(top_a, top_b), max(bot_a, bot_b));
    }
};