class Solution {
public:
    int characterReplacement(string s, int k) {
        int h[26]={0};
        int l=0, n=s.size(), maxC=0, maxL=0;
        for(int r=0;r<n;++r){
            ++h[s[r]-'A'];
            maxC = max(maxC, h[s[r]-'A']);

            if((r-l+1)>maxC+k){
                --h[s[l]-'A'];
                ++l;
            }
            //maxL will be update only if maxC is updated, so it's not required to get exactly current maxC in the window
            maxL = max(maxL, r-l+1);
        }
        return maxL;
    }
};