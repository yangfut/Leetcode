/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head){
    if(head->next == NULL) return head;
    struct ListNode *this = head;
    int counter = 1;
    int middle;
    while(this->next != NULL){
        counter++;
        this = this->next;
    }

    middle = (int) counter/2; //Division generates floating numbers, which leads code to run slower
    this = head;

    for(int idx=0; idx < middle; idx++)
        this = this->next;

    return this;
    
}