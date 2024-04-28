#include <queue>
#include <vector>
#include <utility>

class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.first > b.first;
        }
    };
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int d = 0, count = 0;

        // pq.first: rotted day(d + days[i])
        // pq.second: apples[i]
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq; //min heap

        do{
            // Worst case: all apples are placed into pirority queue. O(NlogN)
            if(d<n && apples[d]) pq.push(make_pair(d+days[d], apples[d]));

            // Worst case: pop all elements at once. O(NlogN)
            while(!pq.empty() && pq.top().first <= d){
                pq.pop();
            }

            if(!pq.empty()){
                pair<int,int> apple = pq.top();
                pq.pop();

                if(apple.second > 1){
                    pq.push(make_pair(apple.first, apple.second-1));
                }

                ++count;
            }

            ++d;

        }while(!pq.empty() || d < n);

        return count;
    }
};