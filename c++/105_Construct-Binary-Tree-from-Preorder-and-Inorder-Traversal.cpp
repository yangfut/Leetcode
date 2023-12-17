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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>&mp) {
        //ending condition
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mp[node->val];
        int numLeft = inRoot - inStart;

        //Preorder
        //Left subtree: preStart+1 : preStart + nunLeft
        //Right subtree: preStart+numLeft+1 : preEnd

        //Inorder
        //Left subtree: inStart : (inRoot-1)
        //Right subtree: (inRoot+1) : inEnd
        node->left = build(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, mp);
        node->right = build(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int idx=0; idx<inorder.size(); idx++){
            mp[inorder[idx]] = idx;
        }

        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n-1, inorder, 0, m-1, mp);
        return root;
    }
};