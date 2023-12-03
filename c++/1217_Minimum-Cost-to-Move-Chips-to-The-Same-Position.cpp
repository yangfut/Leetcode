class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int odd=0;

        for(int idx=0; idx < position.size(); idx++){
            if(position[idx]%2 == 1) odd++;
        }

        if(odd > position.size()/2)return position.size()-odd;
        return odd;
    }
};