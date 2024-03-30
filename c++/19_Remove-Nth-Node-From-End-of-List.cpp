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
    ListNode* stack_solution(ListNode* head, int n) {
        stack<ListNode*>stack;
        ListNode* curNode = head;
        while(curNode){
            stack.push(curNode);
            curNode = curNode->next;
        }
        if(stack.size()==n) return head->next;

        ListNode* temp;
        while(n>0 && !stack.empty()){
            temp = stack.top();
            stack.pop();
            --n;
        }

        stack.top()->next = temp->next;
        return head;
    }

    ListNode* dummy_node_solution(ListNode* head, int n){
        ListNode dummy(0);
        
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        dummy.next = head;
        
        for(int i=0;i<n;++i) fast = fast->next;
        while(fast->next!=nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy.next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // #1 Stack Solution
        // return stack_solution(head, n);

        // #2 Dummy Node and floyd tortoise and hare
        return dummy_node_solution(head, n);
    }
};