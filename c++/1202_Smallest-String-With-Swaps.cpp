class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x != parent[x]) parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int x, int y, vector<int>& parent){
        int rx = find(x, parent);
        int ry = find(y, parent);
        if(rx == ry) return;
        if(ry < rx) swap(rx, ry);
        // Pick the smaller one as root
        parent[ry] = rx;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // 1. create parent[i] and update their parents
        // 2. create children[i] to store all the children into a vector<int>
        // 3. use heap to sort all the target element and replace to the original
        int n = s.length();
        vector<int> parent(n,0);
        unordered_map<int,vector<int>> group;
        // min heap
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < n; ++i) parent[i] = i;
        for(auto& p : pairs) unite(p[0], p[1], parent);
        for(int i = 0; i < n; ++i){
            int root = find(i, parent);
            group[root].push_back(i);
        }

        for(auto g : group){
            vector<int>& children = g.second;
            for(int i : children) pq.push(s[i]);
            for(int i = 0; i < children.size(); ++i){
                int index = children[i];
                s[index] = pq.top();
                pq.pop();
            }
        }
        return s;
    }
};

class Solution {
public:
    int find(int x, vector<int>& parent){
        if(x != parent[x]) parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int x, int y, vector<int>& parent){
        int rx = find(x, parent);
        int ry = find(y, parent);
        if(rx == ry) return;
        if(ry < rx) swap(rx, ry);
        // Pick the smaller one as root
        parent[ry] = rx;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // 1. create parent[i] and update their parents
        // 2. create children[i] to store all the children into a vector<int>
        // 3. use heap to sort all the target element and replace to the original
        int n = s.length();
        vector<int> parent(n,0);
        vector<vector<int>> group(n);

        for(int i = 0; i < n; ++i) parent[i] = i;
        for(auto& p : pairs) unite(p[0], p[1], parent);
        for(int i = 0; i < n; ++i){
            int root = find(i, parent);
            group[root].push_back(i);
        }

        for(auto g : group){
            if(g.empty()) continue;
            string substr;
            for(int i : g) substr += s[i];
            sort(substr.begin(), substr.end());
            for(int i = 0; i < g.size(); ++i){
                int index = g[i];
                s[index] = substr[i];
            }
        }
        return s;
    }
};

// DFS
class Solution {
public:
    void dfs(int idx, vector<vector<int>>& adj, vector<int>& indexGroup, vector<bool>& visited){
        stack<int>st;
        st.push(idx);
        visited[idx] = true;
        while(!st.empty()){
            int top = st.top(); st.pop();
            for(int j : adj[top]){
                if(visited[j]) continue;
                visited[j] = true;
                st.push(j);
            }
            indexGroup.push_back(top);
        }
        

    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> adj(n);
        for(auto &p : pairs){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(n,false);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            vector<int> indexGroup;
            dfs(i, adj, indexGroup, visited);
            string chars;
            for(int idx : indexGroup) chars += s[idx];
            sort(chars.begin(), chars.end());
            sort(indexGroup.begin(), indexGroup.end());
            for(int j = 0; j < indexGroup.size(); ++j){
                int idx = indexGroup[j];
                s[idx] = chars[j];
            }
        }
        return s;
    }
};

// BFS
class Solution {
public:
    void bfs(int idx, vector<vector<int>>& adj, vector<int>& indexGroup, vector<bool>& visited){
        queue<int>q;
        q.push(idx);
        visited[idx] = true;
        while(!q.empty()){
            int top = q.front(); q.pop();
            for(int j : adj[top]){
                if(visited[j]) continue;
                visited[j] = true;
                q.push(j);
            }
            indexGroup.push_back(top);
        }
        

    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> adj(n);
        for(auto &p : pairs){
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(n,false);
        for(int i = 0; i < n; ++i){
            if(visited[i]) continue;
            vector<int> indexGroup;
            bfs(i, adj, indexGroup, visited);
            string chars;
            for(int idx : indexGroup) chars += s[idx];
            sort(chars.begin(), chars.end());
            sort(indexGroup.begin(), indexGroup.end());
            for(int j = 0; j < indexGroup.size(); ++j){
                int idx = indexGroup[j];
                s[idx] = chars[j];
            }
        }
        return s;
    }
};