class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingTime = 0;
        int chefStartTime = 0, chefFinishTime = 0;

        for(auto& customer : customers){
            chefStartTime = max(customer.front(), chefStartTime);
            chefFinishTime = chefStartTime + customer.back();
            waitingTime += chefFinishTime - customer.front();
            chefStartTime = chefFinishTime;
        }

        return waitingTime / customers.size();
    }
};