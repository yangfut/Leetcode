class Solution {
public:
    int reverse(int x) {
        
        // INT_MAX: 2147483647
        // INT_MIN: –2147483648

        int max_bound = INT_MAX / 10;
        int min_bound = INT_MIN / 10;

        int reverse = 0;
        while(x != 0){

            if(reverse > max_bound || (reverse == max_bound && x > 7)) return 0;
            if(reverse < min_bound || (reverse == min_bound && x < -8)) return 0;

            // boundary check before increment 1 reverse digits
            reverse *= 10;
            reverse += (x%10);
            x /= 10;
        }
        return reverse;
    }
};