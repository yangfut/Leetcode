class Solution {
private:
    bool dfsHelper(string& output, unordered_map<int, vector<int>>& adjList, int idx, vector<int>& visited){
    
        if(visited[idx] == 1) return true; // Cycle detected
        if(visited[idx] == 2) return false; // Already processed

        visited[idx] = 1; // Mask as visiting
        for(int c : adjList[idx]){
            if(dfsHelper(output, adjList, c, visited)) return true;
        }
        visited[idx] = 2; // Mask as visited
        output.push_back(idx+'a');
        return false;
    }
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        vector<int> visited(26,-1); // 0: unvisited, 1: visiting, 2: visited
        for(string& word : words){
            for(char& c : word) visited[c-'a'] = 0;
        }

        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < n-1; ++i){
            const string& s1 = words[i];
            const string& s2 = words[i+1];
            int common_len = min(s1.length(), s2.length());
            int j;

            for(j = 0; j < common_len; ++j){
                if(s1[j] == s2[j]) continue;
                // current -> prerequisite (for DFS Topological Order)
                adjList[s2[j]-'a'].push_back(s1[j]-'a');

                // prerequisite -> current (for BFS Topological Order)
                // adjList[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }

            // s2 should be in lower order, so this is invliad
            if(j == common_len && s1.length() > s2.length()) return "";
        }
        string output;
        for(int i = 0; i < 26; ++i){
            if(visited[i] == 0){
                if(dfsHelper(output, adjList, i, visited)) return "";
            }
            
        }

        return output;
    }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size(), count = 0;
        int indegree[26];
        for(int i = 0; i < 26; ++i){
            indegree[i] = -1; // -1: invalid
        }

        for(string& word : words){
            for(char& c : word){
                if(indegree[c-'a'] == 0) continue;
                indegree[c-'a'] = 0;
                ++count;
            }
        }

        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < n-1; ++i){
            const string& s1 = words[i];
            const string& s2 = words[i+1];
            int common_len = min(s1.length(), s2.length());
            int j;

            for(j = 0; j < common_len; ++j){
                if(s1[j] == s2[j]) continue;
                // prerequisite -> current (for BFS Topological Order)
                adjList[s1[j]-'a'].push_back(s2[j]-'a');
                ++indegree[s2[j]-'a'];
                break;
            }

            // s2 should be in lower order, so this is invliad
            if(j == common_len && s1.length() > s2.length()) return "";
        }
        string output;
        deque<int> deq;
        for(int i = 0; i < 26; ++i){
            if(indegree[i] == 0){
                deq.push_back(i);
            }
        }

        while(!deq.empty()){
            int node = deq.front();
            deq.pop_front();
            output.push_back(node+'a');
            for(int next : adjList[node]){
                --indegree[next];
                if(indegree[next] == -1) return ""; // Cycle detected
                if(indegree[next] == 0){
                    deq.push_back(next);
                }
            }
        }

        if(output.length() != count) return ""; // Not all unique letters are included
        return output;
    }
};