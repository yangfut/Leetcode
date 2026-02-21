// https://leetcode.com/problems/brightest-position-on-street/
class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        vector<pair<int,int>> events;
        for(auto& lamp : lights){
            int pos = lamp[0], range = lamp[1];
            events.emplace_back(pos - range, 1); //interval starts
            events.emplace_back(pos + range + 1, -1); // interval ends
        }

        sort(events.begin(), events.end());

        int maxBr = 0, currBr = 0, maxPos;
        for(auto& p : events){
            currBr += p.second;
            if(currBr > maxBr){
                maxPos = p.first;
                maxBr = currBr;
            }
        }
        return maxPos;
    }
};