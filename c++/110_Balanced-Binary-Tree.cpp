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
 /*
 Balanced Tree means the difference of every two nodes is less than 1.
 */
class Solution {
public:
    int GetDepthOfSubTree(TreeNode* node, int curH) {
        if(node == NULL) return curH;
        curH++;
        int left = GetDepthOfSubTree(node->left, curH);
        int right = GetDepthOfSubTree(node->right, curH);
        
        if(left == -1 || right == -1) return -1;
        if(abs(right - left) <= 1) return max(left, right);
        return -1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int left = GetDepthOfSubTree(root->left, 0);
        int right = GetDepthOfSubTree(root->right, 0);
        
        if(left == -1 || right == -1) return false;
        return (abs(right - left) <= 1) ? true : false;
    }
};

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
    bool returnIsBalanced=true;
    int getDepth(TreeNode* curNode){
        if(curNode==nullptr||!returnIsBalanced) return 0;

        int ld = getDepth(curNode->left);
        int rd = getDepth(curNode->right);


        if(abs(rd-ld)>1) returnIsBalanced = false;
        return max(ld,rd)+1;
    }
    bool isBalanced(TreeNode* root) {
        getDepth(root);
        return returnIsBalanced;
    }
};