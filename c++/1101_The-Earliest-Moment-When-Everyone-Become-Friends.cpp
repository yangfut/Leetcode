class Solution {
private:
    int find_parent(vector<int>& parent, int person){

        // [0, 0, 1, 2]
        // if person is 2, then person is 1 -> persion is 0, return 0

        // [0, 0, 2, 2, 3, 5]
        // if persion is 1, then persion is 0, return 0
        while(person != parent[person]){
            person = parent[person];
        }

        return person;
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // 1. Find its parent recursively
        // 2. Update one person's parant to the person with smaller ID
        // 3. Once set of parent is size in 1, all vertices are united
        sort(logs.begin(), logs.end());

        vector<int> parent(n);
        for(int i = 0; i < n; ++i) parent[i] = i;

        for(auto& log : logs){
            if(log[1] > log[2]) swap(log[1], log[2]);

            int root_a = find_parent(parent, log[1]);
            int root_b = find_parent(parent, log[2]);
            if(root_a == root_b) continue;

            parent[root_b] = root_a;
            --n;

            if(n == 1) return log[0];
        }

        return -1;
    }
};