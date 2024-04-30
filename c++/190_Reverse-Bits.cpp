class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        // #1 right shift && left shift
        // uint32_t bits = 0;
        // for(int i=0; i<32; ++i){
        //     bits <<= 1;
        //     bits |= (n & 1);
        //     n >>= 1;
        // }
        // return bits;

        // #2 bitset
        bitset<32> bitset_n(n);
        for(int i=0; i<16; ++i){
            
            if(bitset_n[31-i] == bitset_n[i]) continue;

            bitset_n[31-i].flip();
            bitset_n[i].flip();
        }
        return bitset_n.to_ulong();
    }
};