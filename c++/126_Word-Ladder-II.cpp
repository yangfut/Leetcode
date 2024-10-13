class Solution {
    unordered_map<string, int> dist;
    vector<vector<string>> ans;
    string b;

    void dfs(string &s, vector<string> &temp){
        
        if(s == b){
            ans.push_back(vector<string>(temp.rbegin(), temp.rend()));
            return;
        }

        int curr_dist = dist[s];
        for(int i = 0; i < s.length(); ++i){
            char org = s[i];
            string next = s;
            for(char c = 'a'; c <= 'z'; ++c){
                next[i] = c;
                if(dist.find(next) != dist.end() && dist[next]+1 == curr_dist){
                    temp.push_back(next);
                    dfs(next, temp);
                    temp.pop_back();
                }
            }
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        wordSet.erase(beginWord);
        if(!wordSet.count(endWord)) return ans;
        b = beginWord;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;

        // BFS search
        while(!q.empty()){
            
            string s = q.front();
            int curr_dist = dist[s];
            q.pop();
            if(s == endWord) break;

            for(int i = 0; i < s.length(); ++i){
                char org = s[i];
                for(char c = 'a'; c <= 'z'; ++c){
                    s[i] = c;
                    if(wordSet.find(s) != wordSet.end()){
                        wordSet.erase(s);
                        q.push(s);
                        dist[s] = curr_dist + 1;
                    }
                }
                s[i] = org; 
            }
        }

        vector<string> temp = {endWord};
        dfs(endWord, temp);
        return ans;
    }
};