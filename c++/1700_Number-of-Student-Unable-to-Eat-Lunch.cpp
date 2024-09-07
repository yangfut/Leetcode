class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        pair<int, int> std = make_pair(0,0);
        for(int st : students){
            if(st == 0) std.first++;
            else std.second++;
        }

        for(int s : sandwiches) {
            if(s == 0){
                if(std.first == 0) break;
                std.first--;
            } else {
                if(std.second == 0) break;
                std.second--;
            }
        }
        return std.first + std.second;
    }
};