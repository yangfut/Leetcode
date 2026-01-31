class Solution {
public:
    bool confusingNumber(int n) {
        static int rotateMap[10] = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int origin = n;
        int rotated = 0;
        while(n){
            int dig = n % 10;
            if(rotateMap[dig] == -1) return false;
            n /= 10;
            rotated *= 10;
            rotated += rotateMap[dig];
        }
        return !(origin == rotated);
    }
};