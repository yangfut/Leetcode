// Recursive with Memoization
// Pros: Clear and concise; uses memoization to avoid redundant calculations.
// Cons: Slightly more complex due to the recursive nature and potential for stack overflow for large n.
class Solution {
public:
    vector<int> memo = vector<int>(38, -1);
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;

        if(memo[n] == -1) return memo[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);
        return memo[n];
    }
};

// Tabulation
// Pros: Simple and straightforward; no risk of stack overflow.
// Cons: Requires careful initialization of the vector, but this is minor.
class Solution {
public:
    int tribonacci(int n) {
        if(n < 2) return n;
        if(n == 2) return 1;

        vector<int> vec = vector<int>(n+1, -1);
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 1;
        for(int i = 3; i <= n; ++i){
            vec[i] = vec[i-1] + vec[i-2] + vec[i-3];
        }
        return vec.back();
    }
};