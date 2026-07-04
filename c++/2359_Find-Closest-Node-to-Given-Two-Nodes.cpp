class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // minimum of max(dist1[x], dist2[x])
        int n = edges.size();
        vector<vector<int>> dist(n, vector<int>(2,-1));
        vector<int> nodes = {node1, node2};
        int distance;
        for(int i = 0; i < 2; ++i){
            distance = -1;
            queue<int> q;
            q.push(nodes[i]);
            while(!q.empty() && q.front() != -1){
                ++distance;
                int node = q.front(); q.pop();
                if(dist[node][i] == -1){
                    dist[node][i] = distance;
                    q.push(edges[node]);
                }
            }
        }

        int minDist = INT_MAX, index = -1;
        for(int i = 0; i < n; ++i){
            if(dist[i][0] == -1 || dist[i][1] == -1) continue;
            int currDist = max(dist[i][0],dist[i][1]);
            if(currDist < minDist){
                index = i;
                minDist = currDist;
            }
        }
        return index;
    }
};

class Solution {
public:
    vector<int> getDist(vector<int>& edges, int node){
        int _node = node, n = edges.size();
        vector<int> dist(n,-1);
        int d = -1;
        while(_node != -1 && dist[_node] == -1){
            ++d;
            dist[_node] = d;
            _node = edges[_node];
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        // minimum of max(dist1[x], dist2[x])
        vector<int> dist1 = getDist(edges, node1);
        vector<int> dist2 = getDist(edges, node2);

        int minDist = INT_MAX, index = -1;
        for(int i = 0; i < edges.size(); ++i){
            if(dist1[i] == -1 || dist2[i] == -1) continue;
            int currDist = max(dist1[i],dist2[i]);
            if(currDist < minDist){
                index = i;
                minDist = currDist;
            }
        }
        return index;
    }
};