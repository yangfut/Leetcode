class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rr;
        queue<int> dd;
        int n = senate.length();
        for(int i = 0; i < n; ++i){
            if(senate[i] == 'R') rr.push(i);
            else dd.push(i);
        }

        while(!rr.empty() && !dd.empty()){
            
            int r = rr.front();
            int d = dd.front();
            rr.pop();
            dd.pop();
            if(r < d){
                rr.push(r+n);
            }else{
                dd.push(d+n);
            }
        }

        return rr.empty() ? "Dire" : "Radiant";
    }
};