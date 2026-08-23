#include <algorithm>
#include <vector>

class Solution {
public:
    long long get_consume_time(vector<int>&piles, int k){
        long long time=0;
        for(int banana:piles){
            time += (banana%k==0) ? banana/k : (banana/k)+1;
        }
        return time;
    }
    int bs_solution(vector<int>&piles, int h){
        //determine k value between low and high
        int low = 1, high = *max_element(piles.begin(), piles.end())+1;
        
        //lower bound binary search
        while(low<high){
            int mid = low+(high-low)/2;
            long long time = get_consume_time(piles, mid);
            if(time > (long long)h) low = mid+1;
            else high = mid;
        }

        return low;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //boundary of k: 1 <= k <= max(piles)
        // #1 Binary Search
        return bs_solution(piles, h);
    }
};

class Solution {
public:
    bool is_valid(int k, vector<int>& piles, int h){
        for(int p : piles){
            // Find the ceil of (p / k)
            h -= (p + k -1) / k;
            if(h < 0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lhs = 1;
        int rhs = 1;
        for(int p : piles) rhs = max(rhs, p);

        while(lhs < rhs){
            int m = lhs + (rhs-lhs)/2;
            if(is_valid(m, piles, h)){
                rhs = m;
            }else{
                lhs = m+1;
            }
        }
        return lhs;
    }
};