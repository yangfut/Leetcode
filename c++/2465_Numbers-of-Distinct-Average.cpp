class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int cMap[101] = {0};
        int sumMap[201] = {0};
        int st = 0;
        int ed = 100;
        int uniqueSum = 0;

        for(const int& ele : nums){
            cMap[ele]++;
        }

        while(ed >= st){
            if(cMap[ed] == 0){
                ed--;
                continue;
            }
            if(cMap[st] == 0){
                st++;
                continue;
            }

            sumMap[ed+st]++;
            cMap[ed]--;
            cMap[st]--;
        }

        for(int idx = 0; idx < 201; idx++){
            if(sumMap[idx] == 0) continue;
            uniqueSum++;
        }
        return uniqueSum;
    }
};