class Solution {
public:
    struct cmp{
        bool operator()(const vector<int>&a , const vector<int>& b){
            return pow(a[0],2)+pow(a[1],2) < pow(b[0],2)+pow(b[1],2);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Create min heap
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        vector<vector<int>> result;
        for(int idx=0;idx<points.size();++idx){
            pq.push(points[idx]);
            if(pq.size()>k) pq.pop();
        }

        // dump all points in priority queue
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Use max heap to store the closest point
        // pair.first = distance
        // pair.second = idx in vector points
        
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        vector<vector<int>> result;
        for(int idx=0;idx<points.size();++idx){
            pair<int,int> p;
            p.first = pow(points[idx][0], 2) + pow(points[idx][1], 2);
            p.second = idx;

            pq.push(p);
            if(pq.size()>k) pq.pop();
        }

        // dump all points to output result
        while(!pq.empty()){
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
    }
};