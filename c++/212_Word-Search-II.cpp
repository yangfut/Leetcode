class Solution {
private:
    class Trie{
    public:
        Trie* childrens[26];
        string word;
        Trie(){
            word="";
            for(int i=0;i<26;i++) childrens[i]=nullptr;
        }

        void insert(string word){
            Trie* cur=this;
            for(char& c:word){
                if(!cur->childrens[c-'a']) cur->childrens[c-'a']=new Trie();
                cur=cur->childrens[c-'a'];
            }
            cur->word=word;
        }
    };

public:
    void dfs(vector<vector<char>>& board, int row, int col, Trie* cur, vector<string>&result_v){
        //Base case
        if(row<0||col<0||row==board.size()||col==board[0].size()) return;
        if(board[row][col]=='$'||!cur->childrens[board[row][col]-'a']) return;

        char c=board[row][col];
        board[row][col]='$';
        cur=cur->childrens[c-'a'];
        if(cur->word.size()){
            result_v.push_back(cur->word);
            cur->word="";
        }
        //string ss=s+c; Removing this line improves the Runtime performance from 13.9% to 90.14%
        //dfs(board, row+1, col, cur, ss, result_v);
        //dfs(board, row-1, col, cur, ss, result_v);
        //dfs(board, row, col+1, cur, ss, result_v);
        //dfs(board, row, col-1, cur, ss, result_v);
        dfs(board, row+1, col, cur, result_v);
        dfs(board, row-1, col, cur, result_v);
        dfs(board, row, col+1, cur, result_v);
        dfs(board, row, col-1, cur, result_v);

        board[row][col]=c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //Store words into prefix tree
        Trie* root=new Trie();
        for(string word:words) root->insert(word);
        vector<string>result_v;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(board, i, j, root, result_v);
            }
        }
        return result_v;
    }
};