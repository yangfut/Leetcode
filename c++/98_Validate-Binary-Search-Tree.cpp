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
    void inorder(TreeNode* root, vector<int>&vec){
        if(root == nullptr) return;

        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    bool inorder_solution(TreeNode* root){
        // 1. Convert the BST into a vector
        // 2. Verify whether this vector is sorted in an ascending order
        vector<int> vec;
        inorder(root, vec);
        int n=vec.size();
        for(int i=1;i<n;++i){
            if(vec[i]<=vec[i-1]) return false;
        }
        return true;
    }

    bool _recursion(TreeNode* curNode, long long lower, long long upper){
        if(!curNode) return true;

        if(curNode->val <= lower || curNode->val >= upper) return false;
        bool l_result = (curNode->left) ? _recursion(curNode->left, lower, curNode->val) : true;
        bool r_result = (curNode->right) ? _recursion(curNode->right, curNode->val, upper) : true;

        return l_result && r_result;
    }
    bool two_pointers_solution(TreeNode* root){
        if(!root) return true;
        long long upper = 2147483648; // INT_MAX+1
        long long lower = -2147483649; // INT_MIN-1
        return _recursion(root, lower, upper);
    }
    bool isValidBST(TreeNode* root) {
        // 1. Inorder Traversal
        // return inorder_solution(root);

        // 2. Two Pointers
        return two_pointers_solution(root);
    }
};