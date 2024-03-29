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
    void reverseList_recursion(ListNode* prev, ListNode* curr, ListNode** tail){

        //Base case
        if(curr == nullptr) return;
        if(curr->next == nullptr) *tail = curr;

        reverseList_recursion(curr, curr->next, tail);
        curr->next = prev;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        // #1 Recursion
        // ListNode* tail = nullptr;
        // reverseList_recursion(prev, curr, &tail);

        // #2 Iteration
        ListNode* temp = nullptr;
        while(curr!=nullptr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};