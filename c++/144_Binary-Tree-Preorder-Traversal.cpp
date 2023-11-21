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
    //Solution: Recursion
    /*
    void dfs_bottom(TreeNode* node, vector<int>* vi) {
        if(!node) return;

        dfs_bottom(node->left, vi);
        dfs_bottom(node->right, vi);
        vi->push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vi;    
        if(!root) return vi;
        
        dfs_bottom(root->left, &vi);
        dfs_bottom(root->right, &vi);
        vi.push_back(root->val);
        return vi;
    }
    */
    //Solution: Two Stacks
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>vi;    
        if(!root) return vi;
        
        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(!s1.empty()){
            TreeNode *cur = s1.top();
            s1.pop();
            s2.push(cur);

            if(cur->left != nullptr){
                s1.push(cur->left);
            }
            if(cur->right != nullptr){
                s1.push(cur->right);
            }
        }

        while(!s2.empty()){
            vi.push_back(s2.top()->val);
            s2.pop();
        }

        return vi;
    }
};