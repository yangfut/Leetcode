class Solution {
public:
    /*
    //Recurive: T(n) = O(2^n), S(n) = O(1)
    int fib(int n) {
        int result;
        if(n == 0 || n == 1){
            result = n;
        }else{
            result = fib(n-1)+fib(n-2);
        }
        return result;
    }
    */

    /*
    //Memorization(Top-down): T(n) = O(n), S(n) = O(n)
    int fibMem(int n, vector<int>&cache){
        if (cache[n] == -1){
            cache[n] = fibMem(n-1, cache) + fibMem(n-2, cache);
        }
        return cache[n];

    }
    int fib(int n) {
        if(n <= 1) return n;
        vector<int> cache(n+1, -1);
        cache[0] = 0;
        cache[1] = 1;
        return fibMem(n-1, cache) + fibMem(n-2, cache);
    }
    */
    
    //Tablulation(Bottom-up): T(n) = O(n), S(n) = O(n)
    int fib(int n){
        if(n<=1) return n;
        vector<int>cache(n+1, 0);
        cache[1] = 1;
        for(int idx=2; idx < n+1; idx++){
            cache[idx] = cache[idx-1] + cache[idx-2];
        }
        return cache[n];
    }
};

class Solution {
public:
    vector<int> memo = vector<int>(31, -1);
    int fib(int n) {
        if(n <= 1) return n;
        if(memo[n] == -1) return memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
};