class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            int idxK = n - k;
            while(idxK < 0) idxK+=n;
            vector<int> vec(n);
            for(int i = 0; i < n; ++i){
                int srcIdx = ( idxK+i < n ) ? idxK+i : idxK+i-n ;
                vec[i] = nums[srcIdx];
            }
    
            for(int i = 0; i < n; ++i){
                nums[i] = vec[i];
            }
    
        }
    };

// No need to check redundent cycle because all cycles can be visited between 0 to k
class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            int n = nums.size();
            // equivalent k
            k = k % n;
            int cnt = 0, st = 0;
            while(cnt < n){
                int curr = st, currVar = nums[curr];
                do{
                    int next = ( curr + k ) % n;
                    int temp = nums[next];
                    nums[next] = currVar;
                    currVar = temp;
                    curr = next;
                    ++cnt;
                }while(curr != st);
                ++st;
            }
        }
    };