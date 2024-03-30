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
    // ListNode* reverse(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* next;
    //     while(head){
    //         next = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = next;
    //     }
    //     return prev;
    // }

    void reorderList(ListNode* head) {
        // 1. Reverse the half end of Linked List
        // 2. Link the the half head and the reversed half end

        if(head->next==nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;
        // find middle node
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow;
        stack<ListNode*> stack;
        while(slow){
            stack.push(slow);
            slow = slow->next;
        }

        ListNode* cur = head;

        while(!stack.empty()&&cur!=stack.top()){
            ListNode* temp = cur->next;
            cur->next = stack.top();
            stack.pop();
            cur->next->next = temp;
            cur = temp;
        }
        cur->next = nullptr;
    }
};