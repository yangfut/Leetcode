// Time Limit Exceeded
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        vector<int> left_candle(n, -1);
        vector<int> right_candle(n, n);

        for(int i = 0; i < n; ++i){
            if(i > 0) left_candle[i] = left_candle[i-1];
            if(s[i] == '|') left_candle[i] = i;
        }

        for(int i = n-1; i >= 0; --i){
            if(i < n-1) right_candle[i] = right_candle[i+1];
            if(s[i] == '|') right_candle[i] = i;
        }
        
        vector<int> res(m, 0);
        for(int j = 0; j < m; ++j){
            int l = queries[j][0], r = queries[j][1];
            int idx = l;
            while(idx <= r){
                if(s[idx] == '*' && left_candle[idx] >= l && right_candle[idx] <= r){
                    res[j] += (right_candle[idx] - left_candle[idx] - 1);
                    idx = right_candle[idx]+1;
                }else{
                    ++idx;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        int curLeftCandleIdx = -1;
        int curRightCandleIdx = n;
        int curSum = 0;

        vector<int> leftMost(s.length());
        vector<int> rightMost(s.length());
        vector<int> sumOfPlates(s.length());

        for(int l = 0; l < n; ++l){
            int r = n - 1 - l;
            if(s[l] == '*') ++curSum;
            if(s[l] == '|'){
                if(curLeftCandleIdx < 0) curSum = 0;
                else sumOfPlates[l] += curSum;

                curLeftCandleIdx = l;
            }

            if(s[r] == '|'){
                curRightCandleIdx = r;
            }

            leftMost[l] = curLeftCandleIdx;
            rightMost[r] = curRightCandleIdx;
        }
        vector<int> res;
        for(auto q : queries){
            int leftCandle = rightMost[q[0]];
            int rightCandle = leftMost[q[1]];
            int validPlates = (rightCandle > leftCandle) ? sumOfPlates[rightCandle] - sumOfPlates[leftCandle] : 0;
            res.push_back(validPlates);
        }
        return res;
    }
};
