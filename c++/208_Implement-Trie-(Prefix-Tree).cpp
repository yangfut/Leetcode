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


class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode(){
        for(int i=0;i<26;++i) children[i] = nullptr;
        isWord=false;
    }
};
class Trie {
public:
    
    TrieNode* head;
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curNode = head;

        for(char c:word){
            int idx=c-'a';
            if(!curNode->children[idx]){
                TrieNode* node = new TrieNode();
                curNode->children[idx] = node;
            }

            curNode = curNode->children[idx];
        }
        curNode->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* curNode = head;
        for(char c:word){
            int idx=c-'a';
            if(!curNode->children[idx]) return false;
            curNode = curNode->children[idx];
        }
        return curNode->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curNode = head;
        for(char c:prefix){
            int idx=c-'a';
            if(!curNode->children[idx]) return false;
            curNode = curNode->children[idx];
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