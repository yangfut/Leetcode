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
    int INVALID = -1001;
    int dfs(TreeNode* curr, int& maxv){
        if(curr == nullptr) return 0;

        int depth = 1;
        int ld = dfs(curr->left, maxv);
        int rd = dfs(curr->right, maxv);
        if(ld != 0 && curr->left->val == curr->val){
            depth = ld + 1;
        }

        if(rd != 0 && curr->right->val == curr->val){
            depth = max(depth,rd+1);
        }

        if(ld != 0 && rd != 0){
            if(curr->left->val == curr->right->val && curr->right->val == curr->val){
                maxv = max(ld+rd, maxv);
            }
        }
        maxv = max(depth-1, maxv);
        return depth;
    }
    int longestUnivaluePath(TreeNode* root) {
        int maxv = INVALID;
        dfs(root, maxv);
        return maxv == INVALID ? 0 : maxv;
    }
};