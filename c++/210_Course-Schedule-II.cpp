class Solution {
public:
    void dfsHelper(vector<vector<int>>& graph, vector<int>& visited, vector<int>& order, int idx){

        visited[idx] = 0; // temporarily visited
        for(int neighbor : graph[idx]){
            if(visited[neighbor] == 1) continue;
            if(visited[neighbor] == 0){
                visited[idx] = 1;
                return;
            }
            dfsHelper(graph, visited, order, neighbor);
        }

        visited[idx] = 1;
        order.push_back(idx); //All prerequisites are visited
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Topological ordering
        vector<int> visited(numCourses, -1);
        vector<vector<int>> graph(numCourses);
        for(vector<int>& course : prerequisites){
            graph[course[1]].push_back(course[0]);
        }

        vector<int> order;
        for(int idx=0; idx<numCourses; ++idx){
            if(visited[idx]==1) continue;
            dfsHelper(graph, visited, order, idx);
        }

        if(order.size() < numCourses) return {};
        reverse(order.begin(), order.end());
        return order;
    }
};

// BFS-based topological sort
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<int> order;
        queue<int> q;
        for(auto& p : preq) {
            adj[p[1]].push_back(p[0]);
            ++inDegree[p[0]];
        }

        for(int i = 0; i < n; ++i) if(inDegree[i] == 0) q.push(i);

        while(!q.empty()){
            int currIdx = q.front(); q.pop();
            order.push_back(currIdx);
            for(int chdIdx : adj[currIdx]){
                --inDegree[chdIdx];
                if(inDegree[chdIdx] == 0) q.push(chdIdx);
            }
        }
        return (order.size() == n) ? order : vector<int>();

    }
};