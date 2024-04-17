/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        if(0 == node->neighbors.size() ) return new Node(node->val);
        
        // 1. Explore all nodes and add into map
        // 2. Connect those duplicated node by BFS of the original

        // Optimized approach: replace unordered_map with Node* array since smaller range value
        // unordered_map<Node*, Node*> mapToCloneNode;
        const int range = 100;
        Node* mapToCloneNode[range+1] = {nullptr};
        queue<Node*> que;
        mapToCloneNode[node->val] = new Node(node->val);


        que.push(node);
        while(!que.empty()){
            Node* front = que.front(); que.pop();
            Node* clone = mapToCloneNode[front->val];

            for(Node*& curr : front->neighbors) {
                if(!mapToCloneNode[curr->val]){
                    mapToCloneNode[curr->val] = new Node(curr->val);
                    que.push(curr);
                }
                clone->neighbors.push_back(mapToCloneNode[curr->val]);
            }
        }
        return mapToCloneNode[node->val];
    }
};