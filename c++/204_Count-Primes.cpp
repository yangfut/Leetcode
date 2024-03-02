class Solution {
public:
    int countPrimes(int n) {
        //Base case
        if(n<2) return 0;

        vector<bool> composite(n, false);
        composite[0]=true;
        composite[1]=true;
        //TRUE if number is a composite, and FALSE if it's a prime
        //Starting from i*i with increment of i
        int limit=(int)sqrt(n);
        for(int i=2;i<=limit;i++){
            if(composite[i]==true) continue;
            //Multiples of number i if i is a prime
            for(int j=i*i;j<n;j+=i){
                composite[j]=true;
            }
        }

        //Count numbers of false in composite[]
        int ans=0;
        for(int i=0;i<n;i++){
            if(!composite[i]) ans++;
        }
        return ans;
    }
};