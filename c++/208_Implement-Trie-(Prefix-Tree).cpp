//TrieNode stores a TrieNode* list representing 26 alphabets and a boolean representing isEndOfWord
class TrieNode {
public:
    TrieNode* childrens[26];
    bool isEndOfWord;

    TrieNode(){
        isEndOfWord=false;
        //Initalize
        for(int i=0;i<26;i++) childrens[i]=nullptr;
    }
};
class Trie {
public:
    TrieNode* root;

    Trie() {
        root= new TrieNode(); 
    }
    void insert(string word) {
        TrieNode* cur=root;
        for(char c:word){
            int idx=c-'a';
            if(!cur->childrens[idx]){
                TrieNode* temp=new TrieNode();
                cur->childrens[idx]=temp;
            }
            cur=cur->childrens[idx];
        }
        cur->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* cur=root;
        for(char c:word){
            int idx=c-'a';
            if(!cur->childrens[idx]) return false;
            cur=cur->childrens[idx];
        }
        return cur->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(char c:prefix){
            int idx=c-'a';
            if(!cur->childrens[idx]) return false;
            cur=cur->childrens[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */