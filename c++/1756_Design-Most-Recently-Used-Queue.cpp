class MRUQueue {
public:
    class Node{
    public:
        int val;
        Node* next;
        Node* prev;
        Node(int _val){
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    int n, prev_k;
    Node* dummy = new Node(-1);
    Node* head = dummy;
    Node* tail = dummy;
    Node* prev_call = dummy;
    MRUQueue(int _n) {
        n = _n;
        prev_k = 0;
        for(int i = 1; i <= n; ++i){
            Node* curr = new Node(i);
            head ->next = curr;
            curr->prev = head;
            head = head->next;
        }
        tail = head;
        head = dummy;
    }
    
    int fetch(int k) {

        if(k == n) return tail->val;

        Node* curr;

        // Get the shortest distance from head or tail or previous k
        int res1 = abs(prev_k - k);
        int res2 = n - k;
        int res3 = k;
        int min_res = min(min(res1, res2), res3);
        if(min_res == res2){
            // Search from tail
            curr = tail;
            for(int i = n; i > k; --i) curr = curr->prev;
        }else if(min_res == res3){
            // Search from head
            curr = head->next;
            for(int i = 1; i < k; ++i) curr = curr->next;
        }else{
            // Search from previous k
            curr = prev_call;
            int direction = (prev_k > k) ? -1 : 1;
            while(prev_k != k){
                if(prev_k > k){
                    curr = curr->prev;
                }else{
                    curr = curr->next;
                }
                prev_k += direction;
            }
        }

        prev_k = k;
        prev_call = curr->next;

        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;

        tail->next = curr;
        curr->prev = tail;
        tail = tail->next;
        return tail->val;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */

class MRUQueue {
public:
    class Node{
    public:
        int val;
        Node* next;
        Node(int _val){
            val = _val;
            next = nullptr;
        }
    };

    int n;
    Node* dummy = new Node(-1);
    Node* head = dummy;
    Node* tail = dummy;
    MRUQueue(int _n) {
        n = _n;
        for(int i = 1; i <= n; ++i){
            Node* curr = new Node(i);
            head ->next = curr;
            head = head->next;
        }
        tail = head;
        head = dummy;
    }
    
    int fetch(int k) {

        if(k == n) return tail->val;

        Node* prev = dummy;
        Node* curr = dummy;
        for(int i = 0; i < k; ++i){
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        tail->next = curr;
        tail = tail->next;
        return tail->val;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */