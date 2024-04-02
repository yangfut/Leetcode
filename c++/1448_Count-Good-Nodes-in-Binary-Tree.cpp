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
    int countGoodNode(TreeNode* curNode, int prevMax){
        if(curNode==nullptr) return 0;

        if(curNode->val > prevMax) prevMax=curNode->val;
        int cleft = countGoodNode(curNode->left, prevMax);
        int cright = countGoodNode(curNode->right, prevMax);

        return (curNode->val == prevMax) ? cleft+cright+1 : cleft+cright;
    }
    int goodNodes(TreeNode* root) {
        //edge case;
        if(!root) return 0;

        return countGoodNode(root, root->val);
    }
};