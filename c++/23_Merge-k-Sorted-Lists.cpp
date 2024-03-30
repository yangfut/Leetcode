/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(const ListNode* a, const ListNode* b){
            return a->val > b->val; // Change to '>' for min-heap
        }

    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        for(ListNode* list:lists){
            if(list) minHeap.push(list);
        }

        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;
        while(!minHeap.empty()){
            ListNode* node = minHeap.top();
            minHeap.pop();

            tail->next = node;
            tail = tail->next;
            
            if(node->next) minHeap.push(node->next);
        }
        return dummy.next;
    }
};