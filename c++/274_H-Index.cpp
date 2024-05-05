class Solution {
public:
    int hIndex(vector<int>& citations) {
        // [0, 1, 3, 5, 6]
        // check h is satisfying if citiations[n-h] is equal or greater than h
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for(int h = n; h >= 1; --h){
            if(citations[n-h] >= h) return h;
        }

        // if last element can't be greater or equal to 1, then all citiations[i] are zeros
        return 0;
    }
};