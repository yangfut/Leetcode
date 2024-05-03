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

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last_occurance(26, -1);
        vector<int>ans;
        int n=s.size();

        for(int i=0;i<n;++i) last_occurance[s[i]-'a']=i;
        int start=0, end=0;
        for(int i=0;i<n;++i){
            end = max(end, last_occurance[s[i]-'a']);

            // If currnet node reaches the end point, count the length of this partition
            if(i==end){
                ans.push_back(end-start+1);
                start=i+1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.length() == 1) return {1};

        unordered_map<char, int> collection;
        for(char& c : s) ++collection[c];

        int lastEndIdx = -1, n = s.length();
        unordered_map<char, int> subseq;
        vector<int> answer;
        for(int idx = 0; idx < n; ++idx){
            char c = s[idx];

            // place new element into hash table
            ++subseq[c];

            // check subsequence include all the specifc letters in s
            if(subseq[c] == collection[c]){
                subseq.erase(c);
            }

            if(subseq.empty()){
                answer.push_back(idx - lastEndIdx);
                lastEndIdx = idx;
            }
        }
        return answer;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_occurence(26, -1);
        int n = s.length();
        
        // record the last occurence for each letter
        for(int idx = 0; idx < n; ++idx) last_occurence[s[idx] - 'a'] = idx;

        int endIdx = 0, startIdx = -1;
        vector<int> answer;
        for(int idx = 0; idx < n; ++idx){

            // guarantee letter before endIdx appears once (this letter no longer appears after endIdx)
            endIdx = max(endIdx, last_occurence[s[idx] - 'a']);

            if(idx == endIdx){
                answer.push_back(endIdx - startIdx);
                startIdx = endIdx;
            }
        }

        return answer;
    }
};