class Solution {
public:
    void backtracking(string digits, vector<string> digStr, int idx, string& buffer, vector<string>& combination){
        if(idx==digits.length()){
            if(buffer.length()) combination.push_back(buffer);
            return;
        }

        int num = digits[idx]-'0';
        for(char c:digStr[num]){
            buffer.push_back(c);
        // for(int i=0; i<digStr[num].length();++i){
            // buffer.push_back(digStr[num][i]);
            backtracking(digits, digStr, idx+1, buffer, combination);
            buffer.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> digStr(10);
        digStr[2] = "abc";
        digStr[3] = "def";
        digStr[4] = "ghi";
        digStr[5] = "jkl";
        digStr[6] = "mno";
        digStr[7] = "pqrs";
        digStr[8] = "tuv";
        digStr[9] = "wxyz";

        vector<string> combination;
        string buffer;
        backtracking(digits, digStr, 0, buffer, combination);
        return combination;
    }
};