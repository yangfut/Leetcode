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

class Solution {
public:
    int hammingWeight(int n) {
        // #1 bitset
        bitset<32> bits(n);
        return bits.count();

        // #2 Division
        // int hamming = 0;
        // while(n > 0){
        //     if(n % 2) ++hamming;
        //     n /= 2;
        // }
        // return hamming;
    }
};