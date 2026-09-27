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
    bool equationsPossible(vector<string>& equations) {
        vector<int>parent(26);
        for(int i = 0; i < 26; ++i){
            parent[i] = i;
        }

        int n = equations.size();
        // unite all ==
        for(int i = 0; i < n; ++i){
            if(equations[i][1] == '=') {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                unite(x,y,parent);
            }
        }

        // check all !=
        for(int i = 0; i < n; ++i){
            if(equations[i][1] == '!') {
                int x = equations[i][0] - 'a';
                int y = equations[i][3] - 'a';
                
                int rx = find(x,parent);
                int ry = find(y,parent);
                if(rx == ry) return false;
            }
        }
        return true;
    }
};