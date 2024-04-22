class Solution {
public:
    class Trie{
    public:
        class TrieNode{
        public:
            int wordNum;
            TrieNode* children[26];
            TrieNode(){
                wordNum = -1;
                for(int i=0; i<26; ++i) children[i] = nullptr;
            }
        };

        TrieNode* head;
        unordered_map<string, int> wordNumMap;
        Trie(){
            head = new TrieNode();
        }
        void updateWordNum(const vector<string>& wordList){
            for(int i=0; i<wordList.size(); ++i) wordNumMap[wordList[i]] = i;
        }

        void insert(string word){
            TrieNode* curNode = head;
            for(char c : word){
                if(!curNode->children[c-'a']) curNode->children[c-'a'] = new TrieNode();
                curNode = curNode->children[c-'a'];
            }

            if(!wordNumMap.count(word)) return;
            curNode->wordNum = wordNumMap[word];
        }
        
        void searchRecursion(string word, int start, TrieNode* curNode, int blindIdx, vector<int>& result){
            if(!curNode) return;
            if(start == word.size()){
                result.push_back(curNode->wordNum);
            }else if (start == blindIdx){
                for(int i=0; i<26; ++i){
                    searchRecursion(word, start+1, curNode->children[i], blindIdx, result);
                }
            }else{
                if(!curNode->children[word[start]-'a']) return;
                searchRecursion(word, start+1, curNode->children[word[start]-'a'], blindIdx, result);
            }
        }
        vector<int> blindSearch(string word){
            TrieNode* curNode = head;
            vector<int> result;
            for(int i = 0; i < word.size(); ++i){
                searchRecursion(word, 0, curNode, i, result);
            }
            return result;
        }

    };
    // 1. Create graph
    // 2. Find shortest path in graph from A to B
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        Trie tr = Trie();
        tr.updateWordNum(wordList);
        if(!tr.wordNumMap.count(endWord)) return 0;

        for(string word : wordList){
            tr.insert(word);
        }
        int n = wordList.size();
        vector<vector<int>> graph(n+1);
        
        for(int i = 0; i < n; ++i){
            graph[i] = tr.blindSearch(wordList[i]);
        }

        int root;
        if(tr.wordNumMap.count(beginWord)){
            root = tr.wordNumMap[beginWord];
        }
        else{
            root = n;
            tr.wordNumMap[beginWord] = n;
            graph[n] = tr.blindSearch(beginWord);
        }

        vector<int> dist(n+1, INT_MAX);

        dist[root] = 1;
        queue<int>que;
        que.push(root);

        //Dijastra Algorithm
        while(!que.empty()){
            int current = que.front();
            que.pop();
            for(int neighbor : graph[current]){
                if(dist[current] + 1 < dist[neighbor]){
                    dist[neighbor] = dist[current] + 1;
                    que.push(neighbor);
                }
            }
        }
        return dist[tr.wordNumMap[endWord]] == INT_MAX ? 0 : dist[tr.wordNumMap[endWord]];
    }
};

class Solution {
public:
    // TC: O(N*W*logN), SC: O(N)
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> collection(wordList.begin(), wordList.end());
        if(collection.find(endWord) == collection.end()) return 0;
        int len = beginWord.length();

        queue<pair<string,int>> que;
        que.push(pair<string,int>{beginWord, 1});

        while(!que.empty()){
            string word = que.front().first;
            int dist = que.front().second;
            que.pop();

            for(int i = 0; i < len; ++i){
                char t = word[i];
                for(char c = 'a'; c <= 'z'; ++c){
                    word[i] = c;
                    if(word == endWord) return dist+1;
                    if(collection.find(word) != collection.end()){
                        collection.erase(word);
                        que.push(pair<string, int>{word, dist+1});
                    }
                }
                word[i] = t;
            }
        }
        // should never be here
        return 0;
    }
};