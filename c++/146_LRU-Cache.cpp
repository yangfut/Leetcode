// //Least recently used(LRU) -> Reorder -> Double Linked List
// //O(1) search time -> Hash Map(Map)
// //O(1) insert/remove -> Double Linked List if targaet is known
// class LRUCache {
// public:
//     class Node{
//     public:
//         int key;
//         int value;
//         Node* prev=nullptr;
//         Node* next=nullptr;
//         Node(){}
//         Node(int key, int value){
//             this->key=key;
//             this->value=value;
//         }
//     };

//     Node* head;
//     Node* tail;
//     unordered_map<int, Node*>cache;
//     int c;
//     LRUCache(int capacity) {
//         this->c=capacity;
//         head=new Node();
//         tail=new Node();

//         head->next = tail;
//         tail->prev = head;
//     }
    
//     void insert(Node* node){
//         Node* next = head->next;
//         //head<->node;
//         head->next = node;
//         node->prev = head;

//         //node<->next
//         node->next = next;
//         next->prev = node;
//     }

//     void moveToFront(Node* node){
//         if(head->next == node) return;
//         //prev<->next
//         node->prev->next = node->next;
//         node->next->prev = node->prev;

//         //head<->node<->next
//         Node* next = head->next;
//         next->prev = node;
//         node->next = next;
//         head->next = node;
//         node->prev = head;
//     }
//     //1. If item exists, move it to front(next to head)
//     //2. If item isn't found, return -1
//     int get(int key) {
//         if(cache.count(key)){
//             moveToFront(cache[key]);
//             return cache[key]->value;
//         }
//         return -1;
//     }
    
//     //1. If item isn't found, create a new pair in Map and a new node to front(next to head)
//     //2. If item isn't found && cache reaches the capacity, 
//         //find node at tail->prev as original key/value and update to the new key/value
//         //move this node to front(next to head)
//         //erase original key/value in Map and create a pair with new key/value
//     //3. If item exits, update value with the new one and move to front(next to head)
//     void put(int key, int value) {
//         if(cache.count(key)){
//             cache[key]->value = value;
//             moveToFront(cache[key]);
//         }else{
//             //Add new nodes
//             if(cache.size()==c){
//                 Node* node = tail->prev;
//                 cache.erase(node->key);
//                 node->key = key;
//                 node->value = value;
//                 cache[key] = node;
//                 moveToFront(node);
//             }else{
//                 Node* node = new Node(key, value);
//                 insert(node);
//                 cache[key]=node;
//             }
//         }
//     }
// };

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#include <unordered_map>
class LRUCache {
public:
    class Node{
    public:
        int val, key;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node(int _key, int _val){
            this->key = _key;
            this->val = _val;
        }
    };

    int cap;
    Node* head;
    Node* tail;
    // Arrange for least recently used cache by map and double linked list
    unordered_map<int,Node*>cache;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // return -1 if value is unfound
        if(!cache.count(key)) return -1;
        
        // detach the node
        Node* node = cache[key];
        node->prev->next = node->next;
        node->next->prev = node->prev;

        // put this node next to head
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        return node->val;
    }
    
    void put(int key, int value) {
        // If this key exists, simply update the value in cache
        // If the key unexists, check capacity and remove node before tail if size of cache meets the capcity
        Node* node;
        if(cache.count(key)){
            node = cache[key];
            node->val = value;
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }else{
            if(cache.size()==cap){
                Node* temp = tail->prev;
                cache.erase(temp->key);
                temp->prev->next = tail;
                tail->prev = temp->prev;
                delete temp;
            }
            node = new Node(key,value);
            cache[key]=node;
        }

        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */