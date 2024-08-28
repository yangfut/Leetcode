class Solution {
public:
    string largestGoodInteger(string num) {
        //sliding window
        int left = 0, right = 0;
        string output = "";
        
        while(right < num.length()){

            if(num[left] == num[right]){
                if(right-left == 2){
                    if(output.empty() || num[left] > output[0]){
                        output = num.substr(left,3);
                    }
                }
            }else{
                left = right;
            }
            ++right;    
        }
        return output;
    }
};