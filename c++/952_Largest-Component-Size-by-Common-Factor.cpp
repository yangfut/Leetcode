class Solution {
public:
    unordered_map<int,int> parent;
    int find(int x){
        if(!parent.count(x)) parent[x] = x;
        // path compression
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y){
        int rx = find(x);
        int ry = find(y);
        parent[ry] = rx;
    }
    int largestComponentSize(vector<int>& nums) {
        // 1. Decompose all elements
        // 2. Unite num with those factors, so these prime numbers point to one of the num. 
        // 3. Store the size based on each parent

        // Decomposition
        for(const int ele : nums){
            int curr = ele;
            for(int p = 2; (long long) p*p <= curr; ++p){
                if(curr % p == 0){
                    unite(ele, p);
                    while(curr % p == 0) curr /= p;
                }
            }
            if(curr > 1) unite(ele, curr);
        }

        int longest = 0;
        unordered_map<int,int>cnt;
        for(int ele : nums){
            longest = max(longest, ++cnt[find(ele)]);
        }
        return longest;
    }
};