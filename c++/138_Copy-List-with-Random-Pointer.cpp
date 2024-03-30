/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> map_node;
        Node* curr = head;
        while(curr){
            map_node[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while(curr){
            Node* new_node = map_node[curr];
            new_node->next = map_node[curr->next];
            new_node->random = map_node[curr->random];
            curr = curr->next;
        }

        return map_node[head];
    }
};