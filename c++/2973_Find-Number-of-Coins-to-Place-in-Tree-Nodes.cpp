class Solution {
private:
    vector<long long> answer;
    vector<long long> dfsHelper(int node, vector<vector<int>>& adjList, vector<int>& cost, vector<bool>& visited){
        priority_queue<int> neg; // maxHeap
        priority_queue<int,vector<int>, greater<int>> pos; // minHeap

        if(cost[node] > 0){
            pos.push(cost[node]);
        }else{
            neg.push(cost[node]);
        }

        visited[node] = true;
        for(int other_node : adjList[node]){
            if(visited[other_node]) continue;

            // index 0 - 2: max positive values, index 3 - 5: min negative values
            vector<long long> from_other = dfsHelper(other_node, adjList, cost, visited);
            for(int i = 0; i < 3 && from_other[i] != 0; ++i){
                if(pos.size() == 3){
                    if(from_other[i] > pos.top()) pos.pop();
                    else break;
                }
                pos.push(from_other[i]);
            }

            for(int i = 3; i < 6 && from_other[i] != 0; ++i){
                if(neg.size() == 3){
                    if(from_other[i] < neg.top()) neg.pop();
                    else break;
                }
                neg.push(from_other[i]);
            }
        }

        vector<long long> heap(6, 0);
        for(int i = pos.size() - 1; i >= 0; --i){
            heap[i] = pos.top();
            pos.pop();
        }
        for(int i = neg.size() - 1; i >= 0; --i){
            heap[i+3] = neg.top();
            neg.pop();
        }

        int child_count = 0;
        for(int i = 0; i < 6; ++i){
            if(heap[i] != 0) ++child_count;
        }

        if(child_count < 3) answer[node] = 1;
        else{
            long long result = 0;
            // all postives
            long long temp = heap[0];
            for(int i = 1; i < 3; ++i){
                temp *= heap[i];
            }
            result = max(result, temp);
            
            // two negatives and one positves
            if(heap[0] != 0 && heap[3] != 0 && heap[4] != 0){
                temp = heap[0] * heap[3] * heap[4];
                result = max(result, temp);
            }
            answer[node] = result;
        }

        return heap;
    }

public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        
        int n = cost.size();
        vector<vector<int>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        answer = vector<long long>(n, -1);
        dfsHelper(0, adjList, cost, visited);
        return answer;

    }
};