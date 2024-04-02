#include <queue>
#include <vector>
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
    // vector<vector<int>> getLevelOrderTraversal(TreeNode* root){
    //     queue<TreeNode*> que;
    //     vector<vector<int>>res;
    //     if(!root) return res;
    //     que.push(root);
    //     while(!que.empty()){
    //         int size=que.size();
    //         vector<int> buffer;
    //         for(int i=0;i<size;++i){
    //             TreeNode* temp = que.front();
    //             buffer.push_back(temp->val);
    //             if(temp->left) que.push(temp->left);
    //             if(temp->right) que.push(temp->right);
    //             que.pop();
    //         }
    //         res.push_back(buffer);
    //     }
    //     return res;
    // }
    // vector<int> rightSideView(TreeNode* root) {
    //     // 1. Level Order Traversal, starting from left leaf
    //     // 2. Get the last element
    //     vector<vector<int>> levelOrderTraversal = getLevelOrderTraversal(root);
    //     vector<int> view;
    //     if(levelOrderTraversal.empty()) return view;
    //     for(auto vec:levelOrderTraversal){
    //         view.push_back(vec.back());
    //     }
    //     return view;
    // }
    vector<int> rightSideView(TreeNode* root) {
        // 1. Level Order Traversal
        // 2. Focus on the last item only
        queue<TreeNode*> que;
        vector<int>ans;
        if(!root) return ans;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            for(int i=0;i<size;++i){
                TreeNode* curr = que.front();
                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                que.pop();
                // focus on the last one
                if(i==size-1) ans.push_back(curr->val);
            }
        }
        return ans;
    }
};