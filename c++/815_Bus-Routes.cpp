class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;

        unordered_map<int, vector<int>> buslist;
        int n = routes.size(), stations = 0;
        for(int i = 0; i < n; ++i){
            for(int &stop : routes[i]){
                buslist[stop].push_back(i);
                stations = max(stations, stop);
            }
        }

        vector<int> visited_route(n, false);
        vector<int> visited_station(stations+1, false);

        queue<pair<int,int>> que;
        if(source > stations || target > stations) return -1;
        visited_station[source] = true;
        for(const int &curr_route : buslist[source]){
            que.push(make_pair(source, curr_route));
            visited_route[curr_route] = true;
        }
        int cnt = 1;
        while(!que.empty()){
            int que_size = que.size();
            for(int i = 0; i < que_size; ++i){
                int statNow = que.front().first;
                int routNow = que.front().second;
                que.pop();

                // linear search for all stations in this route
                for(const int &curr_stat : routes[routNow]){

                    if(curr_stat == target) return cnt;
                    if(curr_stat == statNow) continue;
                    if(visited_station[curr_stat]) continue;
                    
                    visited_station[curr_stat] = true;
                    
                    for(const int &next_route : buslist[curr_stat]){
                        if(visited_route[next_route]) continue;
                        
                        que.push(make_pair(curr_stat, next_route));
                        visited_route[next_route] = true;
                    }
                }
            }
            ++cnt;
        }
        return -1;
    }
};