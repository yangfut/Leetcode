/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 1. Use Floyd tortoise and hare algorithm to check hasCycle()
        // 2. Put tortoise at head and count index starting from 0
        // 3. Return index
        
        ListNode* fast = head;
        ListNode* slow = head;
        bool hasCycle = false;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow){
                hasCycle=true;
                break;
            }
        }

        if(!hasCycle) return nullptr;

        slow = head;
        while(fast!=slow){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};