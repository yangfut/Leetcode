class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        int count = 0, val = 0;
        vector<int> ans(n);
        for(int i = 0; i < n; ++i){
            ans[i] = abs(val - (count * i));
            if(boxes[i] == '1'){
                val += i;
                ++count;
            }
        }

        count = 0, val = 0;
        for(int i = n-1; i >= 0; --i){
            ans[i] += abs(val - (count * i));
            if(boxes[i] == '1'){
                val += i;
                ++count;
            }
        }
        return ans;
    }
};