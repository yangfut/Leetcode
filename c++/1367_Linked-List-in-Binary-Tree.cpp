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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfsHelper(ListNode* head, TreeNode* root){
        // base case: traverse all the node in LinkedList
        if(!head) return true;

        // base case: at the end of the tree
        if(!root) return false;

        // base case: stop traverse if not matched
        if(head->val != root->val) return false;

        return dfsHelper(head->next, root->left) || dfsHelper(head->next, root->right);        
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!head) return true;
        if(!root) return false;
        if(dfsHelper(head, root)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};