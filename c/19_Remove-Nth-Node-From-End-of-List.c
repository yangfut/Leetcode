/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 //Time:100%, Space:52.9%
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head->next==NULL) return NULL;
    struct ListNode *this = head;
    struct ListNode *prev = head;

    while(n>0){
        this = this->next;
        n--;
    }
    
    if(this==NULL){
        return prev->next;
    }else{
        while(this->next!=NULL){
            this = this->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;
        return head;
    }
}