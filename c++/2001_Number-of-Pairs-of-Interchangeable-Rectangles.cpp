class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> count_ratio;

        for(int i = 0; i < rectangles.size(); ++i){
            double ratio = static_cast<double>(rectangles[i][0]) / rectangles[i][1];
            count_ratio[ratio]++;
        }

        long long numbers_pairs = 0;
        for(auto &it : count_ratio){
            if(it.second == 1) continue;
            long long temp = it.second;
            numbers_pairs += temp * (temp-1)/2;
        }
        return numbers_pairs;
    }
};