class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //1. Get the time for each position to reach the target
        //2. If greater position takes t times, other less position shouldn't take less time
        //   because they can't run over it.

        vector<pair<int,int>>ps;
        int n=position.size();
        for(int i=0;i<n;++i) ps.push_back(pair<int,int>(position[i],speed[i]));

        //sort by ps[i].first
        sort(ps.begin(), ps.end());

        stack<double>stack;
        for(int i=n-1;i>=0;--i){
            double t = (double)(target-ps[i].first)/(double)(ps[i].second);
            if(stack.empty()||stack.top()<t) stack.push(t);
        }
        return stack.size();
        
    }
};