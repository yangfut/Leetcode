class Solution {
public:
    
    //#1 Bucket Sort
    //Time: Beats 29.29%, Memory: Beats 7.09%
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     vector<int> topElement;
    //     vector<vector<int>>bucket(nums.size()+1);
    //     unordered_map<int, int>mp;

    //     for(int &ele:nums){
    //         mp[ele]++;
    //     }

    //     for(auto &it:mp){
    //         bucket[it.second].push_back(it.first);
    //     }

    //     for(int idx=nums.size(); k>0; idx--){
    //         if(bucket[idx].size()==0) continue;

    //         for(int ii=0; ii<bucket[idx].size(); ii++){
    //             topElement.push_back(bucket[idx][ii]);
    //         }
    //         k -= bucket[idx].size();
    //     }
    //     return topElement;
    // }

    //#2: Pair Sort
    //Time: Beats 74.9%, Space: 65.98%
    // static bool sortByVal(const pair<int, int>& a, const pair<int, int>& b) 
    // { 
    //     return a.second < b.second; 
    // }
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int, int>mp;
    //     vector<pair<int, int>> vec;
    //     vector<int> topElement;
    //     for(int &ele:nums){
    //         mp[ele]++;
    //     }

    //     for(auto &it:mp){
    //         vec.push_back(it);
    //     }

    //     sort(vec.begin(), vec.end(), sortByVal);
        
    //     int n = vec.size();
    //     for(int idx = n-1; k>0; k--, idx--){
    //         topElement.push_back(vec[idx].first);
    //     }

    //     return topElement;
    // }

    //#3 Hash Map + Pirority Queue
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(k>nums.size()) return vector<int>();
        map<int, int>freq;
        priority_queue<pair<int, int>> pq;
        vector<int>res;
        for(int ele:nums) ++freq[ele];
        for(auto &[key, val]:freq) pq.push({val, key});
        
        while(k>0&&!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return res;
    }
};