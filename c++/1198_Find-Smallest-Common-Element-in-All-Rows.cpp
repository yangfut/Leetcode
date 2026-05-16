class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        queue<int> q;
        queue<int> buff;
        int m = mat.size(), n = mat[0].size();
        for(int j = 0; j < n; ++j) q.push(mat[0][j]);
        for(int i = 1; i < m; ++i){
            for(int j = 0; j < n; ++j){
                while(!q.empty() && q.front() < mat[i][j]) q.pop();
                if(!q.empty() && q.front() == mat[i][j]){
                    buff.push(mat[i][j]);
                    q.pop();
                }
            }
            while(!q.empty()) q.pop();
            while(!buff.empty()){
                q.push(buff.front());
                buff.pop();
            }
            if(q.empty()) break;
        }
        return q.empty() ? -1 : q.front();
    }
};