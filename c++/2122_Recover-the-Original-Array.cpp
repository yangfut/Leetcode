class Solution {
private:
    bool recover(vector<int>& nums, int twoK, vector<int>& answer){

        //invalid k
        if(twoK % 2 == 1 || twoK == 0) return false;

        deque<int> deq;
        for(int ele : nums){
            if(deq.size() > 0 && ele - twoK > deq.front()){
                return false;
            }else if(deq.size() > 0 && ele - twoK == deq.front()){
                answer.push_back(deq.front() + (twoK/2));
                deq.pop_front();
            }else{
                deq.push_back(ele);
            }
        }
        return deq.size() == 0;
    }
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            vector<int> answer;
            if(recover(nums, nums[i]-nums[0], answer)){
                return answer;
            }
        }
        // should never be here
        return vector<int>();
    }
};