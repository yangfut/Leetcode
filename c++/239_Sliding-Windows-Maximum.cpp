#include <utility>
#include <deque>
#include <queue>
#include <vector>
#include <set>

class Solution {
public:
    vector<int> multiset_sol(vector<int>&nums, int k){
        vector<int>vec;
        if(k==0) return vec;
        multiset<int>st;

        for(int i=0, n=nums.size();i<n;i++){
            if(i>=k)st.erase(st.find(nums[i-k]));
            st.insert(nums[i]);
            if(i>=k-1) vec.push_back(*st.rbegin());
        }
        return vec;
    }

    vector<int> deq_sol(vector<int>&nums, int k){
        vector<int> res;
        deque<int> deq;

        //Pull the tail out if input element is greater bc this tail will leave earlier
        //Push back if input element is smaller thean deq.end()
        //Pop the head if it is out of the windows(head<=i-k)

        for(int i=0, n=(int)nums.size();i<n;i++){
            while(!deq.empty()&&deq.front()<=i-k)
                deq.pop_front();
            while(!deq.empty()&&nums[deq.back()]<=nums[i])
                deq.pop_back();
            deq.push_back(i);

            if(i>=k-1) res.push_back(nums[deq.front()]);
        }
        return res;
    }

    vector<int>pq_sol(vector<int>& nums, int k) {
        vector<int>res;
        
        //Use priority queue to get maximum value
        //Use pair to store (val, idx) and evalute the idx on the top element
        priority_queue<pair<int, int>> pq;

        for(int i=0, n=(int)nums.size();i<n;i++){
            while(!pq.empty()&&pq.top().second<=i-k) pq.pop();
            pq.push(make_pair(nums[i], i)); //TC:O(logN)
            if(i>=k-1) res.push_back(pq.top().first);
        }
        return res;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //#1 MultiSet
        //TC:O(NlogK)
        //return multiset_sol(nums, k);

        //#2 Double-end queue
        //TC:O(N)
        //return deq_sol(nums, k);

        //#3 Priority Queue
        //TC:O(NLogN)
        return pq_sol(nums, k);
    }
};