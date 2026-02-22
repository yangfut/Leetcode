class Solution {
public:
    string maximumXor(string s, string t) {
        int count[2] = {0,0};
        for(char& c : t) count[c-'0'] += 1;
        string output;
        output.reserve(s.size());
        for(char& c : s){
            int bit = c - '0';
            int complement = 1 - bit;

            if(count[complement]){
                --count[complement];
                output.push_back('1');
            }else{
                --count[bit];
                output.push_back('0');
            }
        }
        return output;
    }
};

class Solution {
public:
    string maximumXor(string s, string t) {
        int count[2] = {0,0};
        for(char& c : t) count[c-'0'] += 1;
        string output;
        output.reserve(s.size());
        for(char& c : s){
            char res = c;
            if(c == '0'){
                if(count[1]){
                    --count[1];
                    res = '1';
                }else{
                    --count[0];
                    res = '0';
                }
            }


            if(c == '1'){
                if(count[0]){
                    --count[0];
                    res = '1';
                }else{
                    --count[1];
                    res = '0';
                }
            }

            output.push_back(res);
        }
        return output;
    }
};