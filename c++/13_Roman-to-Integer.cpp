class Solution {
public:
    int romanDict(char c){
        if(c == 'I')
            return 1;
        else if (c == 'V')
            return 5;
        else if (c == 'X')
            return 10;
        else if (c == 'L')
            return 50;
        else if (c == 'C')
            return 100;
        else if (c == 'D')
            return 500;
        else 
            return 1000;
    }
    int doSubtract(char aPrev, char aCurr){
        if (aPrev == 'I'){
            if (aCurr == 'V' || aCurr == 'X')
                return -2;
        } else if (aPrev == 'X'){
            if (aCurr == 'L' || aCurr == 'C')
                return -20;
        } else if (aPrev == 'C'){
            if (aCurr == 'D' || aCurr == 'M')
                return -200;
        }
        return 0;
    }
    
    int romanToInt(string s) {
        if (s.size() == 1)
            return romanDict(s[0]);
        
        int sum = 0;
        int prev = 0;
        for(int curr = 0;curr < s.size(); curr++){
            sum += romanDict(s[curr]);
            sum += doSubtract(s[prev], s[curr]);
            prev = curr;
        }
        return sum;
    }
};
