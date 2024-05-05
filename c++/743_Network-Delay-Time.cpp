class Solution {
public:
    int getMinLatency(vector<int>& latency, vector<bool>& visited){
        int min = INT_MAX, min_node = -1;
        for(int node = 1; node < latency.size(); ++node){
            if(!visited[node] && latency[node] < min){
                min = latency[node];
                min_node = node;
            }
        }

        return min_node;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        // Prim's algorithm for Minimum Spanning Tree
        // return the longest path

        // adjacency edge matrix
        vector<vector<int>> graph(n+1, vector<int>(n+1, INT_MAX));
        for(int edge = 0; edge < times.size(); ++edge){
            graph[times[edge][0]][times[edge][1]] = times[edge][2];
        }

        // represent vertex includes in the MST
        vector<bool> visited(n+1, false);

        // represent the minimum latecy to the MST
        vector<int> latency(n+1, INT_MAX);
        latency[k] = 0;

        int minTimes = 0;

        // Take n steps to traverse all nodes
        for(int count = 0; count < n; ++count){
            
            // get the optimal vertex with minimum weight(latency) to the MST
            int v = getMinLatency(latency, visited);

            // not traverse all nodes yet, but none of unvisited node can be touched
            if(v == -1) return -1;

            visited[v] = true;

            // find the time to reach the longest node in the MST
            minTimes = max(latency[v], minTimes);

            for(int node = 1; node <= n; ++node){
                if(!visited[node] && graph[v][node] != INT_MAX && latency[v] + graph[v][node] < latency[node]){
                    // accumulate the latency at each layer
                    latency[node] = latency[v] + graph[v][node];
                }
            }
        }

        return minTimes;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Dijkstra Algorithm to find shortest path in graph
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // create adjacency list
        vector<vector<pair<int,int>>> adjacenyList(n);

        for(auto& edge : times){
            adjacenyList[edge[0]-1].push_back(make_pair(edge[1]-1, edge[2]));
        }

        vector<int> latency(n, INT_MAX);

        // initialize the root(node k)
        pq.push(make_pair(0, k-1));
        latency[k-1] = 0;

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            pq.pop();

            for(pair<int,int>& edge : adjacenyList[p.second]){
                // pair<int,int> = {accumulated times, node}
                // Update latency if new node has smaller value and also update its adjancent nodes in the next ieration from pq
                if(edge.second + p.first < latency[edge.first]){
                    latency[edge.first] = edge.second + p.first;
                    pq.push(make_pair(edge.second + p.first, edge.first));
                }
            }
        }
        int maxv = 0;
        for(int idx = 0; idx < latency.size(); ++idx) maxv = max(maxv, latency[idx]);

        return (maxv == INT_MAX) ? -1 : maxv; 
    }
};