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
Runtime
8ms
Beats 70.68%of users with C++

Memory
21.62MB
Beats 59.39%of users with C++
*/
class Solution {
public:
    TreeNode* AddNewTreeNode(vector<int> &nums, int st, int ed) {
        if(ed < st) return NULL;
        if(ed == st) return new TreeNode(nums[ed]);

        int mid = (ed+st)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = AddNewTreeNode(nums, st, mid-1);
        node->right = AddNewTreeNode(nums, mid+1, ed);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) return new TreeNode(nums[0]);

        int mid = nums.size()/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = AddNewTreeNode(nums, 0, mid - 1);
        root->right = AddNewTreeNode(nums, mid + 1, nums.size() - 1);
        return root;
    }
};