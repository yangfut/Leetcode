class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=gas.size()-1, ed=0;
        int sum=gas[st]-cost[st];
        while(ed<st){
            if(sum<=0){
                st--;
                sum+=gas[st]-cost[st];
            }else{
                sum+=gas[ed]-cost[ed];
                ed+=1;
            }
        }
        return (sum>=0)?st:-1;
    }
};