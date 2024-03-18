class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0, high=numbers.size()-1;

        while(low<high){
            int twoSum = numbers[low]+numbers[high];
            if(twoSum==target) return vector<int>{low+1, high+1};
            else if (twoSum > target) --high;
            else ++low;
        }
        //no valid solution
        return vector<int>{-1};
    }
};