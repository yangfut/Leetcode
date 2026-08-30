class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // #1 BFS
        // 1. Create edges for x and y
        // 2. edges[x].push_back(y) and edge[y].push_back(x)
        // 2. Execute BFS and check if node is visited
        unordered_map<int, vector<int>> edges;
        int n = stones.size();
        for(int i = 0; i < n; ++i){
            int xi = stones[i][0];
            int yi = stones[i][1];
            edges[xi].push_back(~yi);
            edges[~yi].push_back(xi);
        }

        unordered_map<int,int> visited;
        for(auto edge: edges) visited[edge.first] = -1;

        queue<int> q;
        int cnt = 0;
        for(auto p : edges){
            if(visited[p.first] == 1) continue;
            // Mark as visited
            visited[p.first] = 1;
            q.push(p.first);
            while(!q.empty()){
                int edge = q.front(); q.pop();
                for(int adj : edges[edge]){
                    if(visited[adj] == 1) continue;
                    visited[adj] = 1;
                    q.push(adj);
                }
            }
            ++cnt;
        }
        return n - cnt;
        // #2 Union Find
        // 1. Flatten the array into 1 dimension
        // 2. Create groups[i] and each group has their own root. Count the valid group numbers
        // 3. When brige one into another, total group number--
        
    }
};

class Solution {
public:
    int find(int i, unordered_map<int,int>&group){
        if(group[i] != i){
            group[i] = find(group[i], group);
        }
        return group[i];
    }

    void unite(int i, int j, unordered_map<int,int>&group){
        int ri = find(i, group);
        int rj = find(j, group);
        group[rj] = ri;
    }

    int removeStones(vector<vector<int>>& stones) {
        // #2 Union Find
        // 1. Flatten the array into 1 dimension
        // 2. Create groups[i] and each group has their own root. Count the valid group numbers
        // 3. When brige one into another, total group number--
        int n = stones.size();
        unordered_map<int,int>group;
        for(int i = 0; i < n; ++i){
            int xi = stones[i][0];
            int yi = ~stones[i][1];
            // This node has already bridged, must drop it
            if(!group.count(xi)) group[xi] = xi;
            if(!group.count(yi)) group[yi] = yi;
            unite(xi, yi, group);
        }

        unordered_set<int> root;
        for(auto& s : stones) root.insert(find(s[0], group));
        return n - root.size();
    }
};
