class Solution {
private:
    int find_parent(vector<int>& parent, int idx){
        if(parent[idx] == idx) return idx;
        while(idx != parent[idx]){
            // path compression
            parent[idx] = parent[parent[idx]];
            idx = parent[idx];
        }
        return idx;
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        for(int idx = 0; idx < n; ++idx) parent[idx] = idx;

        for(vector<int>& edge : edges){
            int parent_a = find_parent(parent, edge[0]);
            int parent_b = find_parent(parent, edge[1]);

            if(parent_a == parent_b) continue;

            // union
            if(parent_a < parent_b){
                parent[parent_b] = parent_a;
            }else{
                parent[parent_a] = parent_b;
            }
        }

        unordered_map<int,int> distinct;
        long long count = 0;
        for(int idx = 0; idx < n; ++idx){
            int my_parent = find_parent(parent, parent[idx]);
            ++distinct[my_parent];
        }

        for(auto& [_,size] : distinct){
            count += static_cast<long long>(size) * static_cast<long long>(n - size);
        }

        return count/2;
    }
};