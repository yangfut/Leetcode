// Hash Map + Hash Set
class Leaderboard {
public:
    unordered_map<int,int> scoreMap;
    set<pair<int,int>> rankBoard;
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        if(scoreMap.count(playerId)){
            rankBoard.erase({scoreMap[playerId], playerId});
        }

        scoreMap[playerId] += score;
        rankBoard.insert({scoreMap[playerId], playerId});
    }
    
    int top(int K) {
        int sum = 0;
        auto it = rankBoard.rbegin();
        while(K && it != rankBoard.rend()){
            sum += it->first;
            --K;
            ++it;
        }
        return sum;
    }
    
    void reset(int playerId) {
        int score = scoreMap[playerId];
        rankBoard.erase({score, playerId});
        scoreMap.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */

// Priority Queue + Hash Map with lazy update
class Leaderboard {
public:
    priority_queue<pair<int,int>> pq;
    unordered_map<int, int> scoreMap;

    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        int accScore = scoreMap[playerId] + score;
        scoreMap[playerId] = accScore;
        pq.push({accScore, playerId});
    }
    
    int top(int K) {
        stack<pair<int,int>> tempStack;
        unordered_set<int> visited;
        int topKSum = 0;
        while(!pq.empty() && K){
            auto [score, player] = pq.top();
            pq.pop();
            if(!visited.count(player) && score == scoreMap[player]){
                visited.insert(player);
                tempStack.push({score, player});
                topKSum += score;
                --K;
            }
        }

        while(!tempStack.empty()){
            pq.push(tempStack.top());
            tempStack.pop();
        }

        return topKSum;
    }
    
    void reset(int playerId) {
        scoreMap[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */