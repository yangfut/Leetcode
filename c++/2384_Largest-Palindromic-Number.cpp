class Solution {
public:
    string largestPalindromic(string num) {
        // 1. Count every digits
        // 2. Create left/right identical string pair
        // 3. Take the largest number in the rest of collections
        // 4. Revser right string and append to the left

        vector<int>digit_count(10, 0);
        for(char c:num){
            digit_count[c-'0']+=1;
        }

        string left="";
        string right="";
        for(int idx=9;idx>=0;){
            if(digit_count[idx]<2){
                --idx;
                continue;
            }
            if(left.empty()&&idx==0) break;

            left.push_back(char(idx+'0'));
            right.push_back(char(idx+'0'));
            digit_count[idx]-=2;
        }

        for(int idx=9;idx>=0;--idx){
            if(digit_count[idx]>0){
                left.push_back(char(idx+'0'));
                break;
            }
        }

        int n=right.size();
        for(int idx=0;idx<n/2;++idx) swap(right[idx], right[n-1-idx]);
        return left+right;
    }
};