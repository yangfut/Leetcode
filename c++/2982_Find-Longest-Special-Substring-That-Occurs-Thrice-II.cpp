#include <queue>
#include <algorithm>
#include <string>

class Solution {
public:
    int maximumLength(string s) {
        // 1. Use sliding window to count length of special substring
        // 2. Use min heap to store the length for each character
        // 3. To determine longest size, only require three maximum window size
        //     4, 4, 4 -> 4
        //     3, 4, 5 -> 4
        //     4, 4 -> 3
        //     5 -> 3

        int left = 0, right = 0, n = s.length();
        unordered_map<char, priority_queue<int,vector<int>, greater<int>>> collection;

        while(right < n){
            while(right < n && s[left] == s[right]) ++right;

            char c = s[left];
            collection[c].push(right - left);
            if(collection[c].size() > 3) collection[c].pop();

            // find next speical substr
            left = right;
        }

        int maxLen = INT_MIN;
        for(auto& [special_char, minHeap] : collection){

            int prev = minHeap.top();
            int i = 3;
            while(!minHeap.empty()){

                if(minHeap.top() > prev){
                    maxLen = max(maxLen, prev);
                    i = 2;
                }else if(minHeap.top() == prev){
                    --i;
                }

                maxLen = max(maxLen, minHeap.top() - i);

                prev = minHeap.top();
                minHeap.pop();
            }
        }

        return maxLen == 0 ? -1 : maxLen;

    }
};