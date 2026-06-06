class Solution {
public:
    int maxBoxesInWarehouse(vector<int>& boxes, vector<int>& warehouse) {
        int bottleneck = INT_MAX, n = warehouse.size(), cnt = 0;
        for(int i = 0; i < n; ++i){
            bottleneck = min(warehouse[i], bottleneck);
            warehouse[i] = bottleneck;
        }
        sort(boxes.begin(), boxes.end());
        for(int i = 0, j = n-1; i < boxes.size() && j >= 0; ++i){
            int b = boxes[i];

            while(j >= 0 && b > warehouse[j]) --j;

            if(j >= 0){
                ++cnt;
                --j;
            }
        }
        return cnt;
    }
};