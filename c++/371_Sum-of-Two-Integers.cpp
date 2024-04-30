class Solution {
public:
    bitset<32> intToTwoComplement(int num){
        bitset<32> bits;
        
        if(num >= 0){
            bits = num;
        }else{
            // get unsign int
            bits = -num;

            // get 1's complement
            bits.flip();

            // increment 1 to convert 1's complement to 2's complement
            bits = bits.to_ulong() + 1;
        }
        return bits;
    }
    int bitset_sol(int a, int b){
        bitset<32> bits_a = intToTwoComplement(a);
        bitset<32> bits_b = intToTwoComplement(b);
        bitset<32> carry = 0;

        // 1-bit adder
        for(int i=0; i<32; ++i){
            
            carry[i] = bits_a[i] & bits_b[i];
            bits_a[i] = bits_a[i] ^ bits_b[i];
            
            if(i>0){
                carry[i] = carry[i] ^ (bits_a[i] & carry[i-1]);
                bits_a[i] = bits_a[i] ^ carry[i-1];
            }
        }

        return static_cast<int>(bits_a.to_ulong());
    }
    int getSum(int a, int b) {
        // #1 bitset solution
        // return bitset_sol(a, b);

        // #2 bitwise adder
        // the overwhelming majority of C++ implementations use two's complement representation for signed integers (int, short, long, long long) due to its efficiency and simplicity for arithmetic operations.
        int carry;
        while(b!=0)
        {
            carry = (a&b);
            a=a^b;
            b=carry<<1;
        }
        return a;
    }
};