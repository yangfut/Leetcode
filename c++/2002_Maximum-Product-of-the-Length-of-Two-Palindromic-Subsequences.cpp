class Solution {
public:
    bool isPalindrone(string &s){
        int st = 0, ed = s.length()-1;
        while(st < ed){
            if(s[st] != s[ed]) return false;
            ++st;
            --ed;
        }
        return true;
    }
    int maxProduct(string s) {
        int n = s.length();
        vector<pair<string, int>> subSeq;

        // all possible combinations for subsequence
        int total = 1 << n;
        for(int mask = 1; mask < total; ++mask){
            string temp = "";
            // complete a possible subsequence by specific mask
            for(int i = 0; i < n; ++i){
                if((1 << i) & mask) temp.push_back(s[i]);
            }

            if(isPalindrone(temp)){
                subSeq.push_back(make_pair(temp, mask));
            }
        }

        // Pick two of palindrone subsequence if they are not overlapped
        int maxProduct = 0;
        for(int i = 0; i < subSeq.size(); ++i){
            for(int j = i+1; j < subSeq.size(); ++j){
                int m1 = subSeq[i].second;
                int m2 = subSeq[j].second;

                if(m1 & m2) continue;
                int l1 = subSeq[i].first.length();
                int l2 = subSeq[j].first.length();
                maxProduct = max(maxProduct, l1 * l2);
            }
        }

        return maxProduct;
    }
};