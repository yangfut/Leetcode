class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long res = 0;
        for(int num : nums) pq.push(num);
        for(int i = 0; i < k; ++i){
            int val = pq.top();
            pq.pop();
            pq.push(ceil(val / 3.0));
            res += val;
        }
        return res;
    }
};