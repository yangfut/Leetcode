class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // sliding window
        int l = 0, r = 0, n = fruits.size();
        int maxLen=0;
        unordered_map<int,int>basket;
        while(r<n){
            if(basket.size()<=2){
                ++basket[fruits[r]];
                ++r;
            }

            if(basket.size()>2){
                --basket[fruits[l]];
                if(basket[fruits[l]]==0) basket.erase(fruits[l]);
                ++l;
            }
            maxLen=max(maxLen,r-l);
        }
        return maxLen;
    }
};