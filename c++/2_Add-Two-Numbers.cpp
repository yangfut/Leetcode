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
    void add_recursion(ListNode* l1, ListNode* l2, ListNode* curNode, int increment) {
        if(l1==nullptr && l2==nullptr && increment==0) return;
        int num = increment;
        if(l1!=nullptr){
            num+=l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            num+=l2->val;
            l2=l2->next;
        }
        
        ListNode* temp = new ListNode(num%10);
        curNode->next = temp;
        add_recursion(l1, l2, curNode->next, num/10);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* curNode = head;
        add_recursion(l1, l2, curNode, 0);
        return head->next;
    }
};