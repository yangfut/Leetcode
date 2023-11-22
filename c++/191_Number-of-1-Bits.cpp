class Solution {
public:
    int hammingWeight(uint32_t n) {
        int weight = 0;
        for(int c=0; c<32; c++){
            if((n&1)==1) weight++;
            n >>= 1;
        }
        return weight;
    }
};