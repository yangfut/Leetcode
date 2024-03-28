class Solution {
public:
    string minWindow(string s, string t) {
        //Edge cases
        if(t.size()>s.size()||s.empty()||t.empty()) return "";
        
        // A: ASCII 101
        // z: ASCII 172
        vector<int>h(72,0);
        vector<int>hh(72,0);
        int cat_in_t = 0, cat_in_w = 0, n=s.size(), output[]={0, n};
        for(char c:t) {
            ++h[c-'A'];
            if(h[c-'A']==1) ++cat_in_t;
        }
        
        for(int l=0,r=0;r<n;++r){
            ++hh[s[r]-'A'];
            if(hh[s[r]-'A']==h[s[r]-'A']) ++cat_in_w;

            while(cat_in_w == cat_in_t){
                if(r-l<=output[1]-output[0]){
                    output[1]=r;
                    output[0]=l;
                }

                do{
                    --hh[s[l]-'A'];
                    if(hh[s[l]-'A']<h[s[l]-'A']) --cat_in_w;
                    ++l;
                }while(l<r&&h[s[l]-'A']==0);
            }
        }
        //Any substring in s can't satisfy
        if(output[1]==n) return "";
        string minWinSubStr="";
        for(int i=output[0];i<=output[1];++i) minWinSubStr.push_back(s[i]);
        return minWinSubStr;

    }
};