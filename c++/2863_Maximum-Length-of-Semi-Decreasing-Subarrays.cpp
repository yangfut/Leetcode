#include <deque>

class Solution {
private:
    static bool cmp(const pair<int,int>& a, const pair<int,int>& b){
        return (a.first == b.first) ? a.second < b.second : a.first < b.first;
    }
public:
    int maxSubarrayLength(vector<int>& nums) {
        vector<pair<int,int>> sorted_nums;
        int n = nums.size();
        for(int idx = 0; idx < n; ++idx) sorted_nums.push_back(make_pair(nums[idx], idx));

        sort(sorted_nums.begin(), sorted_nums.end(), cmp);
        int maxLen = 0, maxIdx = sorted_nums[0].second;
        for(int idx = 0; idx < n; ++idx){
            maxLen = max(maxLen, maxIdx - sorted_nums[idx].second);
            maxIdx = max(maxIdx, sorted_nums[idx].second);
        }
        return maxLen == 0 ? 0 : maxLen + 1;
    }
};

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums) {
        // Two stacks method: two monotonic increasing stack. One is from tail and the other is from head

        // 57, 55, 50, 60, 61, 58, 63, 59, 64, 60, 63
        // head = [(57,0), (60,3), 61, 61, 64]
        // tail = [50, 58, 59, 60, 63]
        deque<pair<int,int>> head;
        deque<pair<int,int>> tail;
        int n = nums.size();
        head.push_back(make_pair(nums[0], 0));
        tail.push_back(make_pair(nums[n-1], n-1));
        
        for(int idx = 1; idx < n; ++idx){
            if(nums[idx] <= head.back().first) continue;
            head.push_back(make_pair(nums[idx], idx));
        }

        for(int idx = n-1; idx >= 0; --idx){
            if(nums[idx] >= tail.front().first) continue;
            tail.push_front(make_pair(nums[idx], idx));
        }
        int maxLen = 0;
        while(!head.empty() && !tail.empty()){
            if(head.front().first > tail.front().first){
                maxLen = max(maxLen, tail.front().second - head.front().second + 1);
                tail.pop_front();
            }else{
                head.pop_front();
            }
        }
        return maxLen;
    }
};

