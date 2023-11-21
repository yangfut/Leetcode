class Solution {
public:
    /*Original
    uint32_t reverseBits(uint32_t n) {
        uint32_t mask  = 0x1;
        uint32_t ans = 0x0;
        uint32_t temp;

        for(uint32_t count = 31; count > 0; count--){
            temp = n & mask;
            n = n >> 1;
            ans = ans | (temp << count);
        }
        
        return ans | n;
    }
    */
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int count = 0; count < 32; count++){
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }
        return ans;
    }
};