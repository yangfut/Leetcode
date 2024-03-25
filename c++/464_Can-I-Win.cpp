#include <cstring>

class Solution {
public:
    int N, K;
    int selResultArr[1<<20]={-1}; //-1: undeteremined, 0: losed, 1: winned

    bool isWin(int curMask, int curSum){
        //Base case
        if(curSum >= K) return false; //THIS player loses. However, the first can still win
        
        if(selResultArr[curMask]!=-1) return selResultArr[curMask];

        for(int selectedNum=1;selectedNum<=N;++selectedNum){
            int numInBit = 1 << (selectedNum-1);
            if(numInBit & curMask) continue; //THIS number is chose

            if(!isWin(curMask|numInBit, curSum+selectedNum)){ //The only way to win is the next player lose in the following selection
                // Assign 1 to selResultArr[curMask]
                // Return 1 as result
                return selResultArr[curMask]=1;
            }
        }
        return selResultArr[curMask]=0;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        // 1. Record the number selection as a mask
        // 2. Create a sub function to iterate every possible choose to see if win the game
        N = maxChoosableInteger;
        K = desiredTotal;

        //Edge case 1: total sum satisfy desiredTotal
        int sum = (N+1)*N/2; //1+2+3+...+N
        if(sum<desiredTotal) return false;

        //Edge case 2: Player wins directly
        if(N>desiredTotal || desiredTotal==0) return true;

        //Fill selection result in -1
        memset(selResultArr,-1,sizeof(selResultArr));
        return isWin(0,0);
    }
};