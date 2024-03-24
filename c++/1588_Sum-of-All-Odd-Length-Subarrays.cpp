class Solution {
public:
    // Optimized Solution
    // int sumOddLengthSubarrays(vector<int>& arr) {
    //     //left side(included) of subarrays = i-0+1
    //     //right side(included) of subarrays = n-1-i+1 = n-i
    //     //total subarrays of index i = (i-1) * (n-i)
    //     //each length in left side can combine with all varies of right side
    //     //One odd subarray should be considered and amount of odd length is the ceiling, so +1
    //     int sum=0, n=arr.size();
    //     for(int i=0;i<n;++i){
    //         int contributedNum = ((i+1)*(n-i)+1)/2;
    //         sum+=arr[i]*contributedNum;
    //     }
    //     return sum;
    // }

    int sumOddLengthSubarrays(vector<int>& arr) {

        int n=arr.size(), len;
        if(n%2==1){
            len=n;
        }else{
            len=n-1;
        }
        int arr_count[1001]={0};
        
        //Count the appears of each element in all subarrays
        //while(len>=1) -> O(n)
        //double for loop -> O(n+1/2)
        //So, total time complexity is O(n^2)
        while(len>=1){
            for(int i=0;i<=n-len;++i){
                for(int j=i;j<i+len;++j){
                    arr_count[arr[j]]++;
                }
            }
            len-=2;
        }

        int sum=0;
        for(int i=0;i<n;++i){
            if(arr_count[arr[i]]==0) continue;

            sum += arr[i]*arr_count[arr[i]];
            arr_count[arr[i]]=0;
        }
        return sum;
    }

};