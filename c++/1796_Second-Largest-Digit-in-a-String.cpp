
#include <string>
#include <vector>

class Solution {
public:
    int secondHighest(string s) {
		if(s.size()==1)return -1;
        vector<int>numMap(10, 0);
        int counter = 0;
        int val;
        for(char &ele : s){
            if(isdigit(ele)){
                val = int(ele) - '0';
                ++numMap[val];
            }
        }

        for(int idx = 9; idx >= 0; --idx){
            if(numMap[idx] == 0){
                continue;
            }else{
                ++counter;
                if(counter == 2) return idx;
            }
        }
        return -1;
    }
};
