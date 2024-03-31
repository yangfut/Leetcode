class Solution {
public:
    static bool sortByPair(const pair<int,int>a, pair<int,int>b){
        return a.first < b.first;
    }
    vector<int> partitionLabels(string s) {
        if(s.size()==1) return vector<int>{1};
        vector<pair<int,int>>letter_location(26, pair<int,int>{-1,-1});
        int n=s.size();

        for(int idx=0;idx<n;++idx){
            char c=s[idx];
            if(letter_location[c-'a'].first==-1){
                letter_location[c-'a'].first = idx;
            }
            letter_location[c-'a'].second = idx;
        }

        sort(letter_location.begin(), letter_location.end(), sortByPair);
    
        vector<int>ans;
        pair<int,int>temp={0,0};
        for(int idx=0;idx<26;++idx){
            if(letter_location[idx].first==-1) continue;
            int st=letter_location[idx].first;
            int ed=letter_location[idx].second;
            if(st>temp.second){
                //create new partition
                ans.push_back(temp.second-temp.first+1);
                temp.first = st;
                temp.second = ed;
            }else{
                //concatenate the partition
                temp.second = max(temp.second, ed);
            }
        }
        ans.push_back(temp.second-temp.first+1);
        return ans;
    }
};