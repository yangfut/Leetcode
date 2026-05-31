class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> graph;
        int n = ppid.size();
        for(int i = 0; i < n; ++i){
            int p = ppid[i], c = pid[i];
            graph[p].push_back(c);
        }

        vector<int>output;
        queue<int>q;
        q.push(kill);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            output.push_back(curr);
            if(graph.count(curr)){
                for(int c : graph[curr]) q.push(c);
            }
        }
        return output;
    }
};