class Solution {
public:
    
    //Option#1: Sort and Map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;

        for(string str:strs){
            string s=str;
            sort(s.begin(), s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto &p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
    //Option#2: Hash Table
    /*
    vector<int> getHashTable(string strs){
        vector<int> hashTable(26, 0);
        for(int idx=0; idx<strs.length(); idx++){
            hashTable[strs[idx]-97]++;
        }
        return hashTable;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<int>>mp;
        vector<vector<string>>ans;
        vector<int> key;
        for(int idx=0; idx<strs.size(); idx++){
            key = getHashTable(strs[idx]);
            if(mp.find(key) == mp.end()){
                mp.insert(pair<vector<int>, vector<int>>(key, vector<int>(1, idx)));
            }else{
                mp[key].push_back(idx);
            }
        }

        vector<string> temp;
        for(const pair<vector<int>, vector<int>> &p : mp){
            temp.clear();
            for(int idx=0; idx < p.second.size(); idx++){
                temp.push_back(strs[p.second[idx]]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
    */
};