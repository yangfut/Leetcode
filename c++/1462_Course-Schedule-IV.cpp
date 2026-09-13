class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // 1. Collect all edges from nodes
        // 2. Run BFS with 0-dependency nodes and decreement indegree for it's downstream nodes
        // 3. During the operation, inhert isPreq from the parent node u to child node v
        
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<vector<bool>> isPreq(n,vector<bool>(n));
        vector<int> indegree(n);
        for(auto& p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[u].push_back(v);
            ++indegree[v];
        }

        queue<int>q;
        for(int i = 0; i < n; ++i){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                for(int i = 0; i < n; ++i){
                    if(isPreq[u][i]){
                        isPreq[v][i] = true;
                    }
                }
                isPreq[v][u] = true;
                --indegree[v];
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        vector<bool> ans(queries.size(), false);
        for(int j = 0; j < queries.size(); ++j){
            int u = queries[j][0];
            int v = queries[j][1];
            if(isPreq[v][u]){
                ans[j] = true;
            }
        }
        return ans;
    }
};