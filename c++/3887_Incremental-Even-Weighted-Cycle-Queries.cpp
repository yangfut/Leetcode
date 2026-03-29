class Solution {
public:
    int find_parent(int x, vector<int>& parent, vector<int>& distance){
        if(parent[x] == x) return x;
        int root = find_parent(parent[x], parent, distance);
        distance[x] ^= distance[parent[x]];
        parent[x] = root;
        return root;
    }
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        vector<int> parent(n,-1);
        vector<int> distance(n, 0); // distance to root node
        int count = 0;
        for(int i = 0; i < parent.size(); ++i) parent[i] = i;

        // union find
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            int pu = find_parent(u, parent, distance);
            int pv = find_parent(v, parent, distance);

            if(pu == pv){
                // Create new cycle
                // Check if adding new edge, the cyclinic weight is even
                if((distance[u] ^ distance[v] ^ w) == 0) ++count;
            }else{
                parent[pv] = pu;
                // pu -> xu -> u -> v -> xv -> pv
                distance[pv] = distance[v] ^ distance[u] ^ w;
                ++count;
            }
        }
        return count;
    }
};