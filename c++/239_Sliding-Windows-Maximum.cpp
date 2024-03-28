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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Use double-ended queue(deq) to track the maximum value in window
        // deq.front() is the maximum value
        // if input element > deq.back(), deq.pop_back() until deq.empty() or deq.back() is greater

        //Edge cases
        if(nums.size()==1) return nums;
        deque<int>deq;
        int n=nums.size();
        vector<int>output(n-k+1,0);
        
        //Initial deq
        for(int st=0;st<k;++st){
            while(!deq.empty()&&deq.back()<nums[st]){
                deq.pop_back();
            }
            deq.push_back(nums[st]);
        }
        output[0]=deq.front();
        for(int st=1; st<=n-k;++st){
            if(deq.front()==nums[st-1]) deq.pop_front();
            while(!deq.empty()&&deq.back()<nums[st+k-1]) deq.pop_back();
            deq.push_back(nums[st+k-1]);
            output[st]=deq.front();
        }
        return output;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Use double-ended queue(deq) to track the maximum value in window
        // deq.front() is the maximum value
        // if input element > deq.back(), deq.pop_back() until deq.empty() or deq.back() is greater

        //Edge cases
        if(nums.size()==1) return nums;
        deque<int>deq;
        int n=nums.size();
        vector<int>output(n-k+1,0);
        
        for(int idx=0; idx<n;++idx){

            if(!deq.empty()&&deq.front()==idx-k) deq.pop_front();
            while(!deq.empty()&&nums[deq.back()]<=nums[idx]) deq.pop_back();
            deq.push_back(idx);
            if(idx>=k-1) output[idx-k+1]=nums[deq.front()];
        }
        return output;
    }
};