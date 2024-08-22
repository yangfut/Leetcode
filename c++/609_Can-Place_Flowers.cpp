class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        // brute-force
        for(int i = 0; i < flowerbed.size(); ++i){
            
            if(flowerbed[i] == 1) continue;
            int left = (i == 0 || flowerbed[i-1] == 0);
            int right = (i == flowerbed.size()-1 || flowerbed[i+1] == 0);

            if(left && right){
                flowerbed[i] = 1;
                --n;
                if(n==0) return true;
            }
        }
        return false;
    }
};