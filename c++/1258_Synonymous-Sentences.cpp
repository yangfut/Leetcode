class Solution {
public:
    string find(string& child, unordered_map<string, string>& parent){
        if(parent[child] != child) parent[child] = find(parent[child], parent);
        return parent[child];
    }
    vector<string> parse_sentence(string& text){
        text += ' ';
        vector<string> output;
        string word = "";
        for(char& c : text){
            if(c == ' ') {
                output.push_back(word);
                word = "";
            }else{
                word += c;
            }
        }
        text.pop_back();
        return output;
    }
    string create_sentence(vector<string>& words){
        string output;
        for(string& w : words){
            output += w;
            output += " ";
        }
        output.pop_back();
        return output;
    }
    void dfs(int idx, vector<string>& words, vector<string>& ans, unordered_map<string, string>& parent, unordered_map<string, vector<string>>& group){
        if(idx == words.size()) {
            ans.push_back(create_sentence(words));
            return;
        }

        // Pick
        string& word = words[idx];
        if(parent.count(word)){
            string root = find(word, parent);
            for(auto& syn : group[root]){
                words[idx] = syn;
                dfs(idx+1, words, ans, parent, group);
            }
            words[idx] = word;
        }else{
            // Not Pick
            dfs(idx+1, words, ans, parent, group);
        }

    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        unordered_map<string, string> parent;
        // Initialize union find
        for(auto& syn : synonyms){
            if(!parent.count(syn[0])) parent[syn[0]] = syn[0];
            if(!parent.count(syn[1])) parent[syn[1]] = syn[1];
            
            // unite both two nodes
            string p0 = find(syn[0], parent);
            string p1 = find(syn[1], parent);
            parent[p1] = p0;
        }
        unordered_map<string, vector<string>> group;
        for(auto& p : parent){
            string root = find(p.second, parent);
            if(!group.count(root)) group[root].push_back(root);
            if(root != p.first) group[root].push_back(p.first);
        }
        for(auto& g : group) sort(g.second.begin(), g.second.end());
        vector<string> words = parse_sentence(text);
        vector<string> ans;
        dfs(0, words, ans, parent, group);
        return ans;
    }
};