class Solution {
public:
    int trap(vector<int>& height) {
        // 1. Get forward and backward maximum for each element
        // 2. Calculate rain by minimum(fwdv, bwdv) - height[i]
        int n=height.size();
        vector<int>fwdv(n);
        vector<int>bwdv(n);
        int maxv=-1;

        //backward max
        for(int i=0;i<n;++i){
            maxv = max(maxv, height[i]);
            bwdv[i] = maxv;
        }

        maxv=-1;
        //forward max
        for(int i=n-1;i>=0;--i){
            maxv = max(maxv, height[i]);
            fwdv[i] = maxv;
        }
        int rain=0;
        for(int i=0;i<n;++i){
            //calculate rain
            rain += min(fwdv[i], bwdv[i]) - height[i];
        }
        return rain;
    }
};