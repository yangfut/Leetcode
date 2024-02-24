class Solution {
public:
    int hash_table_solution(vector<int>& nums){
        if(nums.size()==0) return 0;

        unordered_set<int> s;
        int result=1;
        for(int num:nums) s.insert(num);

        while(s.size()>result){
            int number = *s.begin();
            int cnt=1;
            s.erase(number);

            int smaller=number-1;
            int bigger=number+1;
            
            while(s.count(smaller)>0){
                s.erase(smaller);
                smaller--;
                cnt++;
            }

            while(s.count(bigger)>0){
                s.erase(bigger);
                bigger++;
                cnt++;
            }

            result=max(result, cnt);
        }
        return result;
    }
    int longestConsecutive(vector<int>& nums) {
        //#Hash Table
        return(hash_table_solution(nums));
    }
};