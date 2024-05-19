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
    int get_tree_size(TreeNode* root){
        
        // base case
        if(root == nullptr) return 0;
        return 1 + get_tree_size(root->left) + get_tree_size(root->right);
    }
    void precompute_node_depth(TreeNode* node, int depth, vector<int>& node_depth){

        // base case
        if(!node) return;
        
        node_depth[node->val] = depth;
        precompute_node_depth(node->left, depth+1, node_depth);
        precompute_node_depth(node->right, depth+1, node_depth);
    }

    int precompute_deepest_subtree(TreeNode* node, int depth, vector<int>& deepest_subtree){
        
        // base case
        if(!node) return -1;
        if(!node->left && !node->right) return deepest_subtree[node->val] = depth;

        int deepest_left = precompute_deepest_subtree(node->left, depth+1, deepest_subtree);
        int deepest_right = precompute_deepest_subtree(node->right, depth+1, deepest_subtree);
        return deepest_subtree[node->val] = max(deepest_left, deepest_right);
    }
    
    void precompute_depth_after_removal(TreeNode* node, TreeNode* other_child, vector<int>& depth_after_removal, vector<int>& node_depth, vector<int>& deepest_subtree, int parent){
        
        // base case
        if(node == nullptr) return;
        depth_after_removal[node->val] = max(max(depth_after_removal[parent], node_depth[parent]), (other_child == nullptr) ? 0 : deepest_subtree[other_child->val]);
        precompute_depth_after_removal(node->left, node->right, depth_after_removal, node_depth, deepest_subtree, node->val);
        precompute_depth_after_removal(node->right, node->left, depth_after_removal, node_depth, deepest_subtree, node->val);
    }
    // 1. to determine the depth after removeal, consider 3 scenarios
    //    (1) depth_after_removal[parent]
    //.   (2) node_depth[parent]
    //.   (3) deepest_subtree[other_child]
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> answer;
        int n = get_tree_size(root);
        
        vector<int> node_depth(n+1);
        vector<int> deepest_subtree(n+1);
        vector<int> depth_after_removal(n+1);

        precompute_node_depth(root, 0, node_depth);
        precompute_deepest_subtree(root, 0, deepest_subtree);
        precompute_depth_after_removal(root, nullptr, depth_after_removal, node_depth, deepest_subtree, 0);
        for(int& q : queries) answer.push_back(depth_after_removal[q]);

        return answer;
    }
};