class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // 1. Execute task in Priority Queue and put it into the Cooling Queue with task/release time(time+n)
        // 2. Turn the task back to Priority Queue if release time is equal to the current time

        priority_queue<int> pq;
        queue<pair<int,int>> que;
        int freq[26]={0};

        for(char c:tasks) ++freq[c-'A'];
        for(int count:freq){
            if(!count) continue;
            pq.push(count);
        }
        int time=0;
        while(!pq.empty()||!que.empty()){
            
            if(!pq.empty()){
                if(pq.top()!=1){
                    pair<int,int>p;
                    p.first = pq.top()-1;
                    p.second = time + n;
                    que.push(p);
                }
                pq.pop(); // Executed
            }


            // Put the cooled task from Queue into Priority Qeue
            if(!que.empty()&&que.front().second == time){
                pq.push(que.front().first);
                que.pop();
            }
            ++time;
        }
        return time;
    }
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int count[26] = {0};
        for(const char &c : tasks){
            ++count[c-'A'];
        }
        priority_queue<int> maxHeap;
        queue<pair<int,int>> q;

        for(const int &ele : count){
            if(ele == 0) continue;
            maxHeap.push(ele);
        }
        
        int k = 0;
        while(!maxHeap.empty() || !q.empty()){

            if(maxHeap.empty()){
                k = q.front().first+1;
            }

            if(!q.empty() && q.front().first < k){
                maxHeap.push(q.front().second);
                q.pop();
            }

            int task = maxHeap.top();

            maxHeap.pop();
            if(task > 1){
                q.push(make_pair(k+n, task-1));
            }
            ++k;
        }
        return k;
    }
};