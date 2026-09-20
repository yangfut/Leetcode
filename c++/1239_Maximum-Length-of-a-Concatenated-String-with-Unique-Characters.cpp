class Solution {
public:
    int getValidBits(string& s){
        int bits = 0;
        for(char& c : s){
            int offset = c - 'a';
            int mask = 1 << offset;
            if((bits & mask) != 0){
                // Overlaps
                return -1;
            }
            bits |= mask;
        }
        return bits;
    }
    int backtrack(int idx, int curr, vector<string>& arr, vector<int>& hash){

        if(idx == arr.size()){
            if(curr == -1) return 0;
            int ones = 0;
            for(int i = 0; i < 26; ++i){
                if(curr & 1) ++ones;
                curr = curr >> 1;
            }
            return ones;
        }

        int taken = 0, nottaken = 0;
        if((hash[idx] & curr) == 0){
            taken = backtrack(idx+1, hash[idx] | curr, arr, hash);
        }

        nottaken = backtrack(idx+1, curr, arr, hash);
        
        return max(taken, nottaken);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        vector<int> hash(n);
        for(int i = 0; i < n; ++i){
            hash[i] = getValidBits(arr[i]);
        }

        return backtrack(0,0,arr,hash);
    }
};