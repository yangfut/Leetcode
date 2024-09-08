class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // #1 Brute-Force
        // int n = tickets.size();
        // int round = 0;
        // while(tickets[k] != 0){
        //     for(int i = 0; i < n && tickets[k] != 0; ++i){
        //         if(tickets[i] == 0) continue;

        //         --tickets[i];
        //         ++round;
        //     }
        // }
        // return round;

        // #2 Math
        if(tickets[k] == 1) return k+1;
        
        int n = tickets.size();
        int round = 0, tar = tickets[k];
        for(int i = 0; i < n; ++i){
            int val = 0;
            if(i <= k) val = min(tickets[i], tar);
            else val = min(tickets[i], tar-1);

            round += val;
        }
        return round;

    }
};