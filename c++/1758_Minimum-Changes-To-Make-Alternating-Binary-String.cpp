class Solution {
public:
    int minOperations(string s) {
        char masks[] = {'0', '1'};
        int masks_ops[] = {0, 0};

        for(int i = 0; i < 2; ++i){
            for(const char &c : s){
                if(c != masks[i]) ++masks_ops[i];
                masks[i] ^= 1;
            }
        }

        return min(masks_ops[0], masks_ops[1]);
    }
};