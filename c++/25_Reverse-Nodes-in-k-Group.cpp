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
    // Exclude the start node when reversing
    void reverse_segment_list(ListNode* start, ListNode* end){
        ListNode* tail = end->next;
        ListNode* prev = end->next;
        ListNode* curr = start->next;
        while(curr!=tail){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        start->next = prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(!head || k<=1) return head;
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* end = &dummy;
        
        while(end){
            ListNode* start = end;
            for(int i=0;i<k;++i) if(end) end=end->next;
            if(!end) break;
            
            // The next node of start would be the start of the next K group
            // Mark it before revsere and update start after completing the reverse segement
            ListNode* nextStart = start->next;
            reverse_segment_list(start, end);
            end = nextStart;
        }
        return dummy.next;
    }
};