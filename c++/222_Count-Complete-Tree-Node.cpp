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
    void countNode_recursion(TreeNode* node, int &cache){
        if(node == nullptr) return;
        cache++;
        countNode_recursion(node->left, cache);
        countNode_recursion(node->right, cache);
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int cache = 1;
        countNode_recursion(root->left, cache);
        countNode_recursion(root->right, cache);
        return cache;
    }
};