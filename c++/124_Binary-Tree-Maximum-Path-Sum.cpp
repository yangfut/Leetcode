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
    int maxv = -1001;
    int _maxPathSum(TreeNode* root){
        if(!root) return 0;

        int leftSum = max(_maxPathSum(root->left), 0);
        int rightSum = max(_maxPathSum(root->right), 0);

        int tempSum = root->val + leftSum + rightSum;
        maxv=max(maxv,tempSum);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int result = _maxPathSum(root);
        return result > maxv ? result : maxv;
    }
};