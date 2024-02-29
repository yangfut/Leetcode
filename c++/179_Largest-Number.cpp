class Solution {
public:
    void merge_sort_merge(vector<string>& strNums, int low, int mid, int high){
        int llen=mid-low+1;
        int rlen=high-mid;

        vector<string>tmp_left(llen);
        vector<string>tmp_right(rlen);
        for(int i=0;i<llen;i++)tmp_left[i]=strNums[low+i];
        for(int i=0;i<rlen;i++)tmp_right[i]=strNums[mid+1+i];

        for(int i=0, j=0, k=low;k<=high;k++){
            if(i<llen&&(j==rlen||tmp_left[i]+tmp_right[j]>tmp_right[j]+tmp_left[i])){
                strNums[k]=tmp_left[i++];
            }else{
                strNums[k]=tmp_right[j++];
            }
        }
    }
    void merge_sort_recursion(vector<string>& strNums, int low, int high){
        if(low<high){
            int mid=low+(high-low)/2;
            merge_sort_recursion(strNums, low, mid);
            merge_sort_recursion(strNums, mid+1, high);

            merge_sort_merge(strNums, low, mid, high);
        }
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string>strNums;
        string result="";
        for(int i=0;i<nums.size();i++) strNums.push_back(to_string(nums[i]));
        //#1 Merge Sort
        //merge_sort_recursion(strNums, 0, strNums.size()-1);
        
        //#1 STL Sort
        sort(strNums.begin(), strNums.end(), [](string& s1, string& s2){return s1+s2>s2+s1;});
        if(strNums[0]=="0") return "0";

        for(string num:strNums) result+=num;
        return result;
    }
};