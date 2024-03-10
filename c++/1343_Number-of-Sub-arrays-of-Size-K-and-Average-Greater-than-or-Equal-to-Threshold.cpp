class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        //Sliding Window

        //sumOfWindow = sum(i, n-k)
        //idx=i+k-1 -> n
        //add arr[ptr] and remove arr[ptr-k]

        int totalSum=threshold*k;
        int sumOfWindow=0, count=0, n=arr.size();
        for(int i=0;i<k;i++) sumOfWindow += arr[i];

        if(sumOfWindow>=totalSum) count++;
        for(int idx=k;idx<n;idx++){
            sumOfWindow += arr[idx];
            sumOfWindow -= arr[idx-k];
            // cout << arr[idx] << ":" << sumOfWindow << endl;
            if(sumOfWindow>=totalSum) count++;
        }
        return count;
    }
};