class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n=s2.size();
        int m=s1.size();

        // Create hash table in sub string
        int h[26]={0};
        for(int i=0;i<m;++i) ++h[s1[i]-'a'];

        int hh[26]={0};
        // Find permutation of sub string in the main one
        for(int ed=0, st=0;ed<n;++ed){
            ++hh[s2[ed]-'a'];
            while(st<=ed && hh[s2[ed]-'a']>h[s2[ed]-'a']){
                --hh[s2[st]-'a'];
                ++st;
            }
            if(ed-st+1==m) return true;
        }
        return false;
        
    }
};