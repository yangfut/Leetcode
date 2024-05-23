class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adjList(n);

        //Indegree: the number of incoming edges incident on a vertex in a directed graph.
        vector<int> indegree(n, 0);

        for(auto& rel : relations){
            adjList[rel[0]-1].push_back(rel[1]-1);
            ++indegree[rel[1]-1];
        }

        deque<int> deq;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0) deq.push_back(i);
        }

        vector<int> topSort;
        int semaster = 0;
        while(!deq.empty()){
            int deq_size = deq.size();
            ++semaster;
            for(int i = 0; i < deq_size; ++i){
                int current = deq.front();
                topSort.push_back(current);
                for(int& next : adjList[current]){
                    --indegree[next];
                    if(indegree[next] == 0) deq.push_back(next);
                }
                deq.pop_front();
            }
        }

        return topSort.size() == n ? semaster : -1;
    }
};