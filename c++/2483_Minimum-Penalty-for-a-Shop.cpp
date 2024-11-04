class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), curPen = 0, minPen = 0, idx = 0;
        for(int i = 0; i < n; ++i){
            if(customers[i] == 'Y') --curPen;
            else ++curPen;

            if(curPen < minPen){
                minPen = curPen;
                idx = i+1;
            }
        }
        return idx;
    }
};