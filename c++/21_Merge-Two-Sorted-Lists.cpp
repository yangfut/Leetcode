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
    void mergeTwoLists_recursion(ListNode* list1, ListNode* list2, ListNode* curr){
        if (list1==nullptr && list2==nullptr) return;
        if (list2 == nullptr || (list1!=nullptr && list1->val <= list2->val)) {
            curr->next = list1;
            list1 = list1->next;
        }else{
            curr->next = list2;
            list2 = list2->next;
        }
        mergeTwoLists_recursion(list1, list2, curr->next);
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        ListNode* head = new ListNode();
        mergeTwoLists_recursion(list1, list2, head);
        return head->next;
    }
};