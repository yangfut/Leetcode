class Solution {
public:
    int getMinDistVertex(vector<int>& distance, vector<bool>& visited){
        int n = distance.size(), min = INT_MAX, min_idx;
        for(int idx = 0; idx < n; ++idx){
            if(!visited[idx] && distance[idx] < min){
                min_idx = idx;
                min = distance[idx];
            }
        }
        return min_idx;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Prim's algorithm for Minimum Spanning Tree(MST)
        // represent the vertex include in MST
        vector<bool> visited(n, false);

        // distance is used to pick the minimum edge to MST
        vector<int> distance(n, INT_MAX);

        // always pick index 0 as first element;
        distance[0] = 0;

        int cost = 0;
        for(int count = 0; count < n; ++count){
            
            // get the unvisited vertex with minimum edge to the MST
            int vertex  = getMinDistVertex(distance, visited);

            // add the picked vertex into the MST
            visited[vertex] = true;

            // calculate the optimal cost
            cost += distance[vertex];

            // update distance based on the new added vertex
            for(int idx = 0; idx < n; ++idx){
                
                // Only consider the vertices that doesn't include in the MST
                // Update the distance by finding new the minimum edge based on the picked vertex
                if(!visited[idx]){
                    int dist = abs(points[vertex][0] - points[idx][0]) + abs(points[vertex][1] - points[idx][1]);
                    distance[idx] = min(dist, distance[idx]);
                }

            }
        }

        return cost;
    }
};