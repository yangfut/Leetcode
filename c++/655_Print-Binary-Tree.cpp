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
    void precompute_level_order_traverse(TreeNode* root, vector<vector<int>>& levelOrder){

        // BFS to traverse the entire tree in level-order
        deque<TreeNode*> deq;
        TreeNode* dummy = new TreeNode(-100);
        if(!root) root = dummy;

        deq.push_back(root);
        while(!deq.empty()){
            int deq_size = deq.size();
            int dummy_count = 0;
            vector<int> level;
            for(int count = 0; count < deq_size; ++count){
                TreeNode* node = deq.front();
                deq.pop_front();
                level.push_back(node->val);
                
                if(!node->left){
                    deq.push_back(dummy);
                    ++dummy_count;
                }else{
                    deq.push_back(node->left);
                }
                
                if(!node->right){
                    deq.push_back(dummy);
                    ++dummy_count;
                }else{
                    deq.push_back(node->right);
                }
                
            }
            levelOrder.push_back(level);
            if(dummy_count == 2*deq_size) break;
        }
    }
    void precompute_place_node(vector<vector<string>>& output, vector<vector<int>>& levelOrder, int r, int c, int left, int right){
        if(r == levelOrder.size()) return;
        if(levelOrder[r][c] == -100) return;

        int c_row = r;
        int c_col = (right + left) / 2;
        output[c_row][c_col] = to_string(levelOrder[r][c]);
        precompute_place_node(output, levelOrder, r+1, 2*c, left, c_col-1);
        precompute_place_node(output, levelOrder, r+1, 2*c+1, c_col+1, right);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<int>> levelOrder;
        precompute_level_order_traverse(root, levelOrder);

        int h = levelOrder.size();
        int c = pow(2,h)-1;
        vector<vector<string>> output(h, vector<string>(c, ""));

        // left bound = 0 and right bound = c - 1
        precompute_place_node(output, levelOrder, 0, 0, 0, c-1);
        return output;
    }
};