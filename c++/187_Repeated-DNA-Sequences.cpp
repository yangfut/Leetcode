class Solution {
private:
    int encode_DNA(char c){
        return (c == 'A') ? 0 : (c == 'C') ? 1 : (c == 'G') ? 2 : 3;
    }
    string decode_DNA(int val) {
        string output_str(10, ' ');
        for(int i = 9; i >= 0; --i) {
            output_str[i] = (val & 3) == 0 ? 'A' : (val & 3) == 1 ? 'C' : (val & 3) == 2 ? 'G' : 'T';
            val >>= 2;
        }
        return output_str;
    }
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<int> output;
        unordered_set<int> seen;

        int n = s.length();
        if(n < 10) return vector<string>();

        //A: 00, C:01, G:10, T:11
        int curr = 0;
        int mask = (1 << 20) - 1; // 20-bit mask for storing the encoded value
        for(int i = 0; i < n; ++i){
            curr = (curr << 2 | encode_DNA(s[i])) & mask;

            if(i >= 9){
                if(seen.count(curr)){
                    output.insert(curr);
                }else{
                    seen.insert(curr);
                }
            }
        }
        vector<string> ans;
        for(int val : output){
            ans.push_back(decode_DNA(val));
        }
        return ans;
    }
};