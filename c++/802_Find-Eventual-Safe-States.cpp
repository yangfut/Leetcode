class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> edge(n);
        vector<int>outdegree(n);
        for(int i = 0; i < n; ++i) {
            outdegree[i] = graph[i].size();
            for(int j = 0; j < graph[i].size(); ++j){
                int node = graph[i][j];
                edge[node].push_back(i);
            }
        }
        
        // topological sort
        queue<int>q;
        for(int i = 0; i < n; ++i){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int safeNode = q.front();
            q.pop();
            ans.push_back(safeNode);
            for(int i = 0; i < edge[safeNode].size(); ++i){
                int node = edge[safeNode][i];
                --outdegree[node];
                if(outdegree[node] == 0){
                    q.push(node);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};