#include <string>
class Solution {
public:
    int titleToNumber(string columnTitle) {
        string::reverse_iterator rit;
        int value = 0;
        int powMap[7];
        powMap[0] = 1;

        for(int idx = 1; idx < 7; idx++){
            powMap[idx] = powMap[idx-1]*26;
        }

        int index = 0;
        for(rit = columnTitle.rbegin(); rit != columnTitle.rend(); rit++){
            value += (powMap[index]) * ((int)*rit - 64);
            index++;
        }
        return value;
    }
};