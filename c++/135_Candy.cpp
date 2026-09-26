class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<pair<int,int>> vec;
        vector<int> cy(n,1);
        for(int i = 0; i < n; ++i){
            vec.push_back({ratings[i], i});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; ++i){
            int p = vec[i].first;
            int idx = vec[i].second;

            if(idx-1 >= 0){
                if(ratings[idx-1] < p){
                    cy[idx] = max(cy[idx], cy[idx-1]+1);
                }
            }

            if(idx+1 < n){
                if(ratings[idx+1] < p){
                    cy[idx] = max(cy[idx], cy[idx+1]+1);
                }
            }
        }
        int ans = 0;
        for(int c : cy) ans += c;
        return ans;
    }
};

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cy(n,1);
        for(int i = 1; i < n; ++i){
            // left violations
            if(ratings[i-1] < ratings[i]){
                cy[i] = max(cy[i], cy[i-1]+1);
            }
        }
        for(int i = n-2; i >= 0; --i){
            // right violations
            if(ratings[i+1] < ratings[i]){
                cy[i] = max(cy[i], cy[i+1]+1);
            }
        }
        int ans = 0;
        for(int c : cy) ans += c;
        return ans;
    }
};