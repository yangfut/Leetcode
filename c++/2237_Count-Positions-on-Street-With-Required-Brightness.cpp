// https://leetcode.com/problems/count-positions-on-street-with-required-brightness/
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// Difference array / Prefix Sum: Make changes at boundaries, then axccumulate
class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> diff(n+1, 0);
        for(auto& lamp : lights){
            int st = max(lamp[0] - lamp[1], 0);
            int ed = min(lamp[0] + lamp[1] + 1, n);
            ++diff[st];
            --diff[ed];
        }

        int curr = 0, count = 0;
        for(int i = 0; i < n; ++i){
            curr += diff[i];
            if(curr >= requirement[i]) ++count;
        }
        return count;
    }
};

// sweep line algorithm: Image a vertical line sweep left-to-right across a coordindate system processing "events" as it encounter them
class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<pair<int,int>> intervals;
        intervals.reserve(lights.size() * 2);
        for(auto& lamp : lights){
            int pos = lamp[0], range = lamp[1];
            intervals.emplace_back(max(0, pos - range), 1); // coverage starts
            intervals.emplace_back(min(n, pos + range + 1), -1); // coverage ends
        }

        sort(intervals.begin(), intervals.end());

        int i = 0, curr = 0, count = 0;
        for(auto& p : intervals){
            while(i < p.first && i < n){
                if(curr >= requirement[i]) ++count;
                ++i;
            }

            curr += p.second;
        }

        while(i < n){
            if(curr >= requirement[i]) ++count;
            ++i;
        }
        return count;
    }
};