class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms;
        vector<double> output(nums.size()-k+1);
        auto m = ms.end();
        for(int i = 0; i < nums.size(); ++i){
            ms.insert(nums[i]);

            if(ms.size() == 1){
                m = ms.begin();
            }else{
                if(nums[i] >= *m && ms.size() % 2 == 1){
                    ++m;
                }else if(nums[i] < *m && ms.size() % 2 == 0){
                    --m;
                }
            }

            if(i >= k){
                auto toRemove = ms.find(nums[i-k]);
                if(toRemove == m){
                    if(ms.size() % 2 == 0) ++m;
                    else --m;
                }else if(*toRemove > *m && ms.size() % 2 == 1){
                    --m;
                }else if(*toRemove <= *m && ms.size() % 2 == 0){
                    ++m;
                }
                ms.erase(toRemove);
            }

            if(ms.size() == k){
                int curr = *m;
                int neig = *next(m);
                if(ms.size() % 2 == 0){
                    output[i-k+1] = (curr / 2.0) + (neig / 2.0 );
                }else{
                    output[i-k+1] = static_cast<double>(curr);
                }
            }
        }
        return output;
    }
};