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

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        // Union-find structure
        sort(logs.begin(), logs.end());
        vector<int> parent(n, -1);
        vector<int> rank(n, 0);
        int remain = n-1;
        for(int i = 0; i < n; ++i) parent[i] = i;

        for(auto& log : logs){
            int parentA = log[1], parentB = log[2];
            while(parentA != parent[parentA]){
                parentA = parent[parentA];
            }

            while(parentB != parent[parentB]){
                parentB = parent[parentB];
            }
            // already united
            if(parentA == parentB) continue;

            // unite two segments
            if(rank[parentA] < rank[parentB]) swap(parentA, parentB);

            parent[parentB] = parentA;
            ++rank[parentA];
            --remain;
            if(remain == 0) return log[0];
        }
        // should not be here
        return -1;
        
    }
};