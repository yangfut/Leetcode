class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int sign = 1;
        int diff = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] % 2 == 1) sign = -sign;
            if(i % 6 == 5) sign = -sign;
            diff += sign * nums[i];
        }

        return diff;
    }
};

class Solution {
public:
    void swapPlayer(int& activeScore, int& inactiveScore, int& count){
        swap(activeScore, inactiveScore);
        ++count;
    }
    int scoreDifference(vector<int>& nums) {
        int activeScore = 0, inactiveScore = 0, count = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] % 2 == 1) swapPlayer(activeScore, inactiveScore, count);
            if(i % 6 == 5) swapPlayer(activeScore, inactiveScore, count);

            activeScore += nums[i];
        }

        if(count % 2 == 0) return activeScore - inactiveScore;
        return inactiveScore - activeScore;
    }
};