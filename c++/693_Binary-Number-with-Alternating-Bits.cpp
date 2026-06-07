class Solution {
public:
    bool hasAlternatingBits(int n) {
        int b = -1;
        while(n){
            int curr_b = n % 2;
            if(b != -1 && b == curr_b) return false;
            n /= 2;
            b = curr_b;
        }
        return true;
    }
};