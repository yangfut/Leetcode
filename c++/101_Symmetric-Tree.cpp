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
    bool decisionTree(TreeNode* lNode, TreeNode* rNode) {
        if(lNode == NULL && rNode == NULL) return true;
        if(lNode == NULL || rNode == NULL) return false;

        if(lNode->val == rNode->val){
            return decisionTree(lNode->left, rNode->right) && decisionTree(lNode->right, rNode->left);
        } else { 
            return false; 
        } 
    }
    bool isSymmetric(TreeNode* root) {
        return decisionTree(root->left, root->right);
    }
};