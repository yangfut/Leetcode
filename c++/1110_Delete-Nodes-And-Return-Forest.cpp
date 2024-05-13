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
private:
    void dfsHelper(TreeNode* node, unordered_set<int>& del, vector<TreeNode*>& result){
        
        if(node == nullptr) return;
        if(del.count(node->val)){
            if(node->left && !del.count(node->left->val)) result.push_back(node->left);
            if(node->right && !del.count(node->right->val)) result.push_back(node->right);
        }
        
        if(node->left){
            dfsHelper(node->left, del, result);
            if(del.count(node->left->val)) node->left = nullptr;
        }

        if(node->right){
            dfsHelper(node->right, del, result);
            if(del.count(node->right->val)) node->right = nullptr;
        }

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        if(root == nullptr) return vector<TreeNode*>();

        // 1. Make to_delete into unordered_set()
        // 2. Traverse child nodes first and then delete child nodes if they ar in to_delete[]
        // 3. If current node is in to_delete[], append its child nodes into output result if they are not in to_delete[]
        
        vector<TreeNode*> result;
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        if(!del.count(root->val)) result.push_back(root);
        dfsHelper(root, del, result);
        return result;
    }
};