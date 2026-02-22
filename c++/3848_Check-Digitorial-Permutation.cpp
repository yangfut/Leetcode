class Solution {
public:
    int factorial(int val, int (&memo)[10]){
        if(memo[val]) return memo[val];
        return memo[val] = val * factorial(val-1, memo);
    }

    bool isDigitorialPermutation(int n) {
        int memoFactorial[10] = {};
        memoFactorial[0] = 1;
        int anagramOrg[10] = {};
        int anagramMod[10] = {};
        int org = n, fact = 0;
        while(n > 0){
            int dig = n % 10;
            ++anagramOrg[dig];
            n /= 10;
            fact += factorial(dig, memoFactorial);
        }

        while(fact > 0){
            ++anagramMod[fact%10];
            fact /= 10;
        }

        for(int i = 0; i < 10; ++i){
            if(anagramOrg[i] != anagramMod[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    int factorial(int val, unordered_map<int,long long>& memo){
        if(memo.count(val)) return memo[val];
        return memo[val] = val * factorial(val-1, memo);
    }

    bool isDigitorialPermutation(int n) {
        unordered_map<int,long long> memoFactorial{{0,1}};
        unordered_map<int,int> anagramOrg;
        unordered_map<int,int> anagramMod;
        int org = n, fact = 0;
        while(n > 0){
            int dig = n % 10;
            ++anagramOrg[dig];
            n /= 10;
            fact += factorial(dig, memoFactorial);
        }

        while(fact > 0){
            int dig = fact % 10;
            ++anagramMod[dig];
            fact /= 10;
        }

        return anagramOrg == anagramMod;
    }
};