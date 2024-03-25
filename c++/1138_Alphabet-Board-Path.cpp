class Solution {
public:
    string alphabetBoardPath(string target) {
        
        // 1. Move up/down(limit to 4th row) and then move left/right
        // 2. If row is still smaller then the row of target, move down again
        // 3. Update start by target

        int st=0;
        string output = "";
        for(char char_c:target){
            int row_c = (char_c-'a')/5, col_c = (char_c-'a')%5;
            //Go up
            while(st/5>row_c){
                st-=5; output.push_back('U');
            }
            //Go down
            while(st/5<row_c && st/5<4){
                st+=5; output.push_back('D');
            }
            //Go left
            while(st%5>col_c){
                --st; output.push_back('L');
            }
            //Go right
            while(st%5<col_c){
                ++st; output.push_back('R');
            }

            //If target is z, go down again
            while(st/5<row_c){
                st+=5; output.push_back('D');
            }
            output.push_back('!');
            st = char_c-'a';
        }
        return output;
    }
};