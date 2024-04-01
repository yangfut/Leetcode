/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // #1 dfs
    void dfs(TreeNode* curNode, TreeNode* ref, vector<TreeNode*> &ref_vec){
        if(curNode==nullptr||ref_vec.back()==ref) return;

        ref_vec.push_back(curNode);
        dfs(curNode->left, ref, ref_vec);
        dfs(curNode->right, ref, ref_vec);
        if(ref_vec.back()!=ref) ref_vec.pop_back();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* dummy = new TreeNode(0);
        vector<TreeNode*> p_vec={dummy};
        vector<TreeNode*> q_vec={dummy};
        dfs(root, p, p_vec);
        dfs(root, q, q_vec);
        
        int ilca = 1;
        int len = min(p_vec.size(), q_vec.size());
        for(int i=1;i<len;++i){
            if(p_vec[i]!=q_vec[i]) break;
            ilca=i;
        }
        return p_vec[ilca];
    }
};

class Solution{
public:
    // #2 Recursion
    // Report the existance of p or q
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        if(root==p) return p;
        if(root==q) return q;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left==nullptr&&right==nullptr) return nullptr;
        if(left==nullptr) return right;
        if(right==nullptr) return left;
        return root;
    }
};