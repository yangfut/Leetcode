class Solution {
public:
    class GraphNode{
    public:
        map<int,int> nextNodePath;
        GraphNode(){}
    };
    
    void dfs(map<int, GraphNode*>& graph, vector<int>& disappear, vector<int>& time, int idx){
        if(!graph.count(idx)) return;
        
        GraphNode* curr = graph[idx];
        for(const auto& it : curr->nextNodePath){
            int tar = it.first;
            int length = it.second;
            
            if(time[tar]!=-1 && time[tar]<time[idx]) continue;
            if(time[idx]+length >= disappear[tar]) continue;
            
            if(time[tar]==-1 || time[idx]+length < time[tar]){
                time[tar]= time[idx]+length;
                dfs(graph, disappear, time, tar);
            }

        }
    }
    // Naive Solution
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        map<int, GraphNode*> graph;
        vector<int> time(n, -1);
        for(const auto& edge:edges){
            int ptr1=edge[0];
            int ptr2=edge[1];
            if(!graph.count(ptr1)){
                GraphNode* node = new GraphNode();
                graph[ptr1] = node;
            }
            int temp = graph[ptr1]->nextNodePath[ptr2];
            graph[ptr1]->nextNodePath[ptr2] = (temp==0)? edge[2] : min(temp, edge[2]);
            
            if(!graph.count(ptr2)){
                GraphNode* node = new GraphNode();
                graph[ptr2] = node;
            }
            temp = graph[ptr2]->nextNodePath[ptr1];
            graph[ptr2]->nextNodePath[ptr1] = (temp==0)?edge[2]: min(temp, edge[2]);
        }
        
        time[0]=0;
        dfs(graph, disappear, time, 0);
        return time;
        
    }
};