// Time Limit Exceeded
// We only need a full dep/isPreq reachability matrix when answering repeated queries about arbitrary node pairs
// This question only ask for local verification from the topological sort result
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size() + 1;
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        vector<vector<bool>> dep(n, vector<bool>(n));
        for(auto& seq : sequences){
            for(int i = 1; i < seq.size(); ++i){
                int u = seq[i-1];
                int v = seq[i];
                adj[u].push_back(v);
                ++indegree[v];
            }

        }

        queue<int>q;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                for(int i = 0; i < n; ++i){
                    if(dep[u][i]){
                        dep[v][i] = true;
                    }
                }
                dep[v][u] = true;
                --indegree[v];
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        unordered_set<int> seen;
        for(int i = 0; i < nums.size(); ++i){
            int v = nums[i];
            for(int u : seen){
                if(!dep[v][u]) return false;
            }
            seen.insert(v);
        }
        return true;
    }
};

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size() + 1;
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(auto& seq : sequences){
            for(int i = 1; i < seq.size(); ++i){
                int u = seq[i-1];
                int v = seq[i];
                adj[u].push_back(v);
                ++indegree[v];
            }

        }

        queue<int>q;
        for(int i = 1; i < n; ++i){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int idx = 0;
        while(!q.empty() && q.size() == 1){
            int u = q.front();
            if(u != nums[idx++]) return false;
            q.pop();
            for(int v : adj[u]){
                --indegree[v];
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        // avoid cycle
        return idx == nums.size();
    }
};