class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Use min Heap of size to always acquire the minimum size
        // Only check the top of min Heap is satisfied. If not, remove it and then check again
        // Insert new intervals[i] that starti < queries[j]

        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), m = queries.size();
        vector<int> answer(m, -1);
        vector<pair<int,int>> sorted_queries;
        for(int idx = 0; idx < m; ++idx) sorted_queries.push_back(make_pair(queries[idx], idx));
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // first: size of the interval, second: index of the interval
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        // index to track the pq-added interval in intervals.
        // preceding elements have been added into pq and proceeding element aren't in pq
        int iIdx = 0;

        for(pair<int,int>& q : sorted_queries){
            int currQuery = q.first, currIdx = q.second;

            while(!pq.empty()){
                int i = pq.top().second;
                // valid best choice
                if(intervals[i][0] <= currQuery && intervals[i][1] >= currQuery) break;
                pq.pop();
            }

            // skip over irrelevant intervals
            while(iIdx < n && intervals[iIdx][0] <= currQuery){
                if(intervals[iIdx][0] <= currQuery && currQuery <= intervals[iIdx][1]){
                    pq.push(make_pair(intervals[iIdx][1]-intervals[iIdx][0]+1, iIdx));
                }
                ++iIdx;
            }

            if(!pq.empty()) answer[currIdx] = pq.top().first;
        }
        return answer;

    }
};