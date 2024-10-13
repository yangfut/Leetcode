int getLargestIndexLen(vector<int> &feature1, vector<int> &feature2){
    
    int n = feature1.size();
    
    vector<int> dp(n, 1);
    int maxLen = 1;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < i; ++j){
            if((feature1[i] < feature1[j] && feature2[i] < feature2[j]) || (feature1[i] > feature1[j] && feature2[i] > feature2[j])){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

vector<int> getRequestNumbers(vector<int> &wait){
    int n = wait.size();
    vector<int> output;
    // #1 Brute-force: TC: O^2, SC: O(N)
    // for(int t = 0; t < n; ++t){
    //     int q = 0;
    //     for(int j = t; j < n; ++j){
    //         if(t < wait[j]) ++q;
    //     }
    //     output.push_back(q);
    // }
    
    // #2 MultiSet: TC:(N), S: O(N)
    unordered_multiset<int> waitSet(wait.begin(), wait.end());
    for(int i = 0; i < n; ++i){
        //Remove expired queue
        waitSet.erase(i);
        if(i && wait[i-1] > i){
            // Remove previous element in queue
            auto it = waitSet.find(wait[i-1]);
            if(it != waitSet.end()){
                waitSet.erase(it);   
            }
   
        }
        output.push_back(waitSet.size());
    }
    return output;
}