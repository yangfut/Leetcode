class Solution {
private:
    bool backtrack(int x, int y, int current_x, int current_y, vector<vector<int>>& memo, int target){

        if(current_x == target || current_y == target || current_x+current_y == target) return true;

        if(current_x == x && current_y == y) return false;

        if(memo[current_x][current_y] != -1) return memo[current_x][current_y] == 1;
        
        memo[current_x][current_y] = 2; // Mark as visiting

        bool result = false;
        // fill x
        if(current_x != x) result |= backtrack(x, y, x, current_y, memo, target);
        // fill y
        if(current_y != y) result |= backtrack(x, y, current_x, y, memo, target);

        // pour x
        if(current_x > 0) result |= backtrack(x, y, 0, current_y, memo, target);
        // pur y
        if(current_y > 0) result |= backtrack(x, y, current_x, 0, memo, target);

        //pour y to x
        if(current_y > 0){
            int diff = min(current_y, x - current_x);
            result |= backtrack(x, y, current_x + diff, current_y - diff, memo, target);
        }
        //pour x to y
        if(current_x > 0){
            int diff = min(current_x, y - current_y);
            result |= backtrack(x, y, current_x - diff, current_y + diff, memo, target);
        }
        
        return memo[current_x][current_y] = result;
    }
public:
    bool canMeasureWater(int x, int y, int target) {
        vector<vector<int>> memo(x+1, vector(y+1, -1)); //-1: unvisited, 2: visiting
        return backtrack(x, y, 0, 0, memo, target);
    }
};