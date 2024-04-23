
// DFS with caching
// Beats 47% in runtime and 28% in memory
class Solution {
public:
    bool dfsHelper(vector<vector<int>>& graph, vector<bool>& visited, int ref_a, int ref_b, int start){
        // touch the vertix at the other side of edge so this edge causes a loop(remove it!)
        if(start == ref_b) return true; 

        visited[start] = true;
        for(int next : graph[start]){
            if(visited[next]) continue;
            if(graph[next].size() == 1) continue;
            cout << next << " " << start << endl;
            if(next == ref_b && start == ref_a) continue;
            if(dfsHelper(graph, visited, ref_a, ref_b, next)) return true;
        }

        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>graph(n+1);
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // conduct DFS to selected edges and remove it if both vertices are touched
        for(int idx = n-1; idx >=0; --idx){
            int a = edges[idx][0];
            int b = edges[idx][1];

            if(graph[a].size() == 1 || graph[b].size() == 1) continue;
            vector<bool> visited(n+1, false);
            if(dfsHelper(graph, visited, a, b, a)) return edges[idx];
        }

        // should never be here
        return {};
    }
};

// Union Find
// Beats 82% in runtime and 63% in memory

class Solution {
public:
    int findParent(vector<int>& parent, int node){
        // the parent node parent[node] == node
        int par = parent[node];
        while(par != parent[par]){
            par = parent[par];
        }
        return par;
    }

    // return false if union can't complete
    bool unionFunc(vector<int>& parent, vector<int>& rank, int node1, int node2){
        int par1 = findParent(parent, node1);
        int par2 = findParent(parent, node2);

        if(par1 == par2) return false;

        if(rank[par1] >= rank[par2]){
            rank[par1] += rank[par2];
            parent[par2] = par1;
        }else{
            rank[par2] += rank[par1];
            parent[par1] = par2; 
        }
        return true;
    }

    // Union Find
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);
        // At the beginning, every node are disconnected so the parent of each node is itself
        for(int i=0; i<n+1; ++i){
            parent[i] = i;
        }

        for(int idx=0; idx<n; ++idx){
            if(!unionFunc(parent, rank, edges[idx][0], edges[idx][1])){
                return edges[idx];
            }
        }

        // should never be here
        return {};
    }
};