class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string serializedStr;
        for(string &s : strs){
            serializedStr += s;
            serializedStr += '\0';
        }
        return serializedStr;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        string temp;
        for(char &c : s){
            if(c == '\0'){
                strs.push_back(temp);
                temp.clear();
            }else{
                temp += c;
            }
        }
        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));