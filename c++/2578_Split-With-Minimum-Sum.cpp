class Solution {
public:
    int splitNum(int num) {
        int table[10]={0};
        int remainder=0;
        int num1 = 0;
        int num2 = 0;
        int idx = 0;
        
        while(num!=0){
            remainder = num%10;
            num = num/10;
            table[remainder]++;
        }
 
        while(idx < 10){
            if(table[idx]==0){
                idx++;
                continue;
            }

            if(num1 >= num2){
                if(num2!=0){
                    num2*=10;
                }
                num2+=idx;
            }else{
                if(num1!=0){
                    num1*=10;
                }
                num1+=idx;
                
            }
            table[idx]--;
        }
        return num1+num2;
    }
};