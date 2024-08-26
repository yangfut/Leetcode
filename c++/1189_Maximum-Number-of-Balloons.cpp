class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int hash_table[26];
        for(char c : text){
            ++hash_table[c-'a'];
        }

        // word: balloons
        int word_count = 0;
        while(true){

            if(hash_table['b'-'a'] < 1) break;
            hash_table['b'-'a']--;

            if(hash_table['a'-'a'] < 1) break;
            hash_table['a'-'a']--;

            if(hash_table['l'-'a'] < 2) break;
            hash_table['l'-'a'] -= 2;

            if(hash_table['o'-'a'] < 2) break;
            hash_table['o'-'a'] -= 2;

            if(hash_table['n'-'a'] < 1) break;
            hash_table['n'-'a']--;

            word_count++;
        }
        return word_count;
    }
};