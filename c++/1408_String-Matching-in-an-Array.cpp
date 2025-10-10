class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });
        vector<string> ans;
        for(int i = 0; i < words.size()-1; ++i){
            for(int j = words.size()-1; j > i; --j){
                if(words[j].find(words[i]) != string::npos) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        string all;
        vector<string> ans;
        for(string& w : words) all += w + " ";
        for(string& w : words){
            if(all.find(w, all.find(w)+1) != string::npos){
                ans.push_back(w);
            }
        }
        return ans;
    }
};