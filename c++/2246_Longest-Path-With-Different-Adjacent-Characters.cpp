class Solution {
public:
    int dfs(int idx, vector<vector<int>>& adj, string& s, int& maxPath){

        if(adj[idx].empty()) return 1;

        int maxPath1 = 0;
        int maxPath2 = 0;
        int maxDepth = 0;
        for(int child : adj[idx]){

            int depth = dfs(child, adj, s, maxPath);

            // no pair of adjacent nodes shared the same character
            if(s[child] == s[idx]) continue;

            if(depth > maxPath1){
                maxPath2 = maxPath1;
                maxPath1 = depth;
            }else if(depth > maxPath2){
                maxPath2 = depth;
            }

            maxPath = max(maxPath, maxPath1 + maxPath2 + 1);
        }
        return maxPath1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; ++i){
            adj[parent[i]].push_back(i);
        }

        int maxPath = 1;
        dfs(0, adj, s, maxPath);
        return maxPath;
    }
};