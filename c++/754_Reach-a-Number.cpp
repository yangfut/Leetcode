class Solution {
public:
    int reachNumber(int target) {
        int tar = abs(target), sum = 0;
        for(int i = 1; i <= (2*tar); ++i){
            sum += i;
            if(sum >= tar && (sum-tar) % 2 == 0) return i;
        }

        // should never be here
        return -1;
    }
};