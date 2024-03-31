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
    int maxDiameter=0;
    int getDepthOfBinaryTree(TreeNode* node){
        if(node==nullptr) return 0;

        int ld = getDepthOfBinaryTree(node->left);
        int rd = getDepthOfBinaryTree(node->right);

        maxDiameter = max(maxDiameter, ld+rd);

        return max(ld,rd)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        getDepthOfBinaryTree(root);
        return maxDiameter;
    }
};