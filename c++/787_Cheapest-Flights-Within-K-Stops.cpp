class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        vector<vector<int>> adjList(n, vector<int>(n, -1));

        for(auto& edge : flights) adjList[edge[0]][edge[1]] = edge[2];

        deque<pair<int,int>> deq;
        deq.push_back(make_pair(dst, 0));
        cost[dst] = 0;
        while(k >= 0){
            int size = deq.size();
            for(int count = 0; count < size; ++count){
                int curr_dst = deq.front().first;
                int curr_cost = deq.front().second;
                deq.pop_front();
                for(int j = 0; j < n; ++j){
                    if(adjList[j][curr_dst] == -1) continue;
                    if(cost[j] > adjList[j][curr_dst] + curr_cost){
                        cost[j] = adjList[j][curr_dst] + curr_cost;
                        deq.push_back(make_pair(j, cost[j]));
                    }       
                }
            }
            --k;
        }
        return cost[src] == INT_MAX ? -1 : cost[src];
    }
};