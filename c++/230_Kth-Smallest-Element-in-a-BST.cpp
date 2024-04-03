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
    // void inorder_traversal(TreeNode* curNode, vector<int>&vec, int k){
    //     if(!curNode) return;

    //     inorder_traversal(curNode->left, vec, k);
    //     if(vec.size()==k) return;
    //     vec.push_back(curNode->val);
    //     inorder_traversal(curNode->right, vec, k);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int>vec;
    //     inorder_traversal(root, vec, k);
    //     return vec.back();
    // }
    int kthSmallest(TreeNode* root, int& k) {
        // 1. Count with inorder traversal
        // 2. If leaf reaches k-indexed element, return its value
        // 3. Otherwise, --k and return -1
        if(root==nullptr) return -1;

        int l = kthSmallest(root->left, k);
        if(l!=-1) return l;
        
        --k;
        if(k==0) return root->val;
        return kthSmallest(root->right, k);
    }
};