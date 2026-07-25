class Solution {
public:
    int maxNumberOfApples(vector<int>& w) {
        int cap = 5000, n = w.size();
        sort(w.begin(), w.end());
        for(int i = 0; i < n; ++i){
            cap -= w[i];
            if(cap < 0) return i;
        }
        return n;
    }
};