class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(int i=0;i<26;++i) children[i]=nullptr;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {delete root;}
    void addWord(string word) {
        TrieNode* curNode = root;
        for(char c:word){
            if(!curNode->children[c-'a']){
                curNode->children[c-'a']=new TrieNode();
            }
            curNode = curNode->children[c-'a'];
        }
        curNode->isWord = true;
    }
    
    bool search(string word) {
        queue<TrieNode*> que;
        que.push(root);
        int n = word.size();
        for(int wIdx = 0; wIdx < n && !que.empty(); ++wIdx){
            int idx = 0, size = que.size();
            while(idx<size){
                TrieNode * thisNode = que.front();
                que.pop();

                if(word[wIdx]=='.'){
                    for(int i=0;i<26;++i){
                        if(thisNode->children[i]) que.push(thisNode->children[i]);
                    }
                }else{
                    if(thisNode->children[word[wIdx]-'a']){
                        que.push(thisNode->children[word[wIdx]-'a']);
                    }
                }
                ++idx;
            }
        }

        while(!que.empty()){
            TrieNode* curNode = que.front();
            que.pop();
            if(curNode->isWord) return true; 
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class TrieNode{
public:
    TrieNode* children[26];
    bool isWord;
    TrieNode(){
        isWord = false;
        for(int i=0;i<26;++i) children[i]=nullptr;
    }
};

class WordDictionary {
private:
    bool searchRecursion(string word, int start, TrieNode* curNode){
        if(start == word.size()) return curNode->isWord;

        char c = word[start];
        if(c=='.'){
            for(int i=0;i<26;++i){
                if(!curNode->children[i]) continue;
                if(searchRecursion(word, start+1, curNode->children[i])) return true;
            }
        }else{
            if(!curNode->children[c-'a']) return false;
            return searchRecursion(word, start+1, curNode->children[c-'a']);
        }
        return false;
    }
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {delete root;}
    void addWord(string word) {
        TrieNode* curNode = root;
        for(char c:word){
            if(!curNode->children[c-'a']) curNode->children[c-'a']=new TrieNode();
            curNode = curNode->children[c-'a'];
        }
        curNode->isWord = true;
    }
    
    bool search(string word) {
        return searchRecursion(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */