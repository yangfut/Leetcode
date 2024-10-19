class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, -1);
        vector<int> post(n, -1);
        int isZero = -1;
        for(int i = 0; i < n; ++i){
            if(nums[i] == 0 && isZero == -1){
                isZero = i;
            }else if(nums[i] != 0 && isZero != -1){
                isZero = -1;
            }

            pre[i] = isZero;
        }
        isZero = -1;
        for(int i = n-1; i >= 0; --i){
            if(nums[i] == 0 && isZero == -1){
                isZero = i;
            }else if(nums[i] != 0 && isZero != -1){
                isZero = -1;
            }
            post[i] = isZero;
        }

        int k = 0;
        unordered_map<int,int> count;
        while(k < n){
            if(pre[k] == -1){
                ++k;
                continue;
            }

            int size = post[k] - pre[k] + 1;
            count[size]++;
            k = post[k]+1;
        }
        long long ans = 0;
        for(const auto& it : count){
            long long first = it.first;
            long long second = it.second;
            long long temp = second * (first+1) * first/2;
            ans += temp;
        }
        return ans;
    }
};

// ChatGPT
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;  // To store the total number of zero-filled subarrays
        long long currentZeros = 0;  // To track the length of the current zero sequence

        for (int num : nums) {
            if (num == 0) {
                // Increment the length of the current zero sequence
                currentZeros++;
                // Add the number of subarrays that can be formed with the current sequence
                count += currentZeros;
            } else {
                // Reset the zero sequence length if a non-zero number is encountered
                currentZeros = 0;
            }
        }

        return count;
    }
};