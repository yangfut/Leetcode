class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        // if num == 2736, s = {2, 7, 3, 6}
        int n = s.length();
        vector<int> last(10, -1);
        for(int i = 0; i < n; ++i){
            // Use hash map to record the right-most digit
            last[s[i]-'0'] = i;
        }

        for(int i = 0; i < n; ++i){
            int val = s[i] - '0';
            for(int d = 9; d > val; --d){
                if(last[d] != -1 && i < last[d]){
                    int iToSwap = last[d];
                    swap(s[i], s[iToSwap]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};