class Solution {
public:
    int find(int x, vector<int>&parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    void unite(int x, int y, vector<int>&parent){
        int rx = find(x, parent);
        int ry = find(y, parent);
        if(rx == ry) return;
        if(ry < rx) swap(rx,ry);
        parent[ry] = rx;
    }

    int findLatestStep(vector<int> arr, int m) {
        int n = arr.size() + 1;
        int ans = -1;
        vector<int> parent(n);
        vector<int> group(n,0);
        unordered_map<int,int> pattern;
        for(int i = 0; i < n; ++i) parent[i] = i;

        for(int i = 0; i < n-1; ++i){
            int val = arr[i];
            int back = val + 1;
            int front = find(val-1,parent);
            
            group[val] = 1;
            pattern[group[val]]++;

            // unite back
            if(val < n-1 && group[back] != 0){
                unite(val, back,parent);
                pattern[group[val]]--;
                pattern[group[back]]--;

                group[val] = 1 + group[back];     
                pattern[group[val]]++;
            }

            // unite front
            if(val > 1 && group[front] != 0){
                unite(front, val,parent);
                pattern[group[val]]--;
                pattern[group[front]]--;

                group[front] += group[val];
                pattern[group[front]]++;
            }
            
            if(pattern[m] > 0) ans = i + 1;
        }
        return ans;
    }
};

class Solution {
public:
    int find(int x, vector<int>&parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    void unite(int x, int y, vector<int>&parent){
        int rx = find(x, parent);
        int ry = find(y, parent);
        if(rx == ry) return;
        if(ry < rx) swap(rx,ry);
        parent[ry] = rx;
    }

    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        int k = arr.size() + 1;
        int ans = -1;
        vector<int> parent(k);
        vector<int> group(k,0);
        vector<int> pattern(k,0);
        for(int i = 0; i < k; ++i) parent[i] = i;

        for(int i = 0; i < n; ++i){
            int val = arr[i];
            int back = val + 1;
            int front = find(val - 1,parent);
            
            group[val] = 1;
            pattern[group[val]]++;

            // unite back
            if(val < k-1 && group[back] != 0){
                unite(val, back,parent);
                pattern[group[val]]--;
                pattern[group[back]]--;

                group[val] = 1 + group[back];     
                pattern[group[val]]++;
            }

            // unite front
            if(val > 1 && group[front] != 0){
                unite(front, val,parent);
                pattern[group[val]]--;
                pattern[group[front]]--;

                group[front] += group[val];
                pattern[group[front]]++;
            }
            
            if(pattern[m] > 0) ans = i+1;
        }
        return ans;
    }
};