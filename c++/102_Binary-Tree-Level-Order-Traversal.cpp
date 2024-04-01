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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         if(root==nullptr) return vector<vector<int>>();
//         vector<vector<int>> ans;
//         stack<TreeNode*> parent;
//         stack<TreeNode*> child;

//         parent.push(root);

//         do{

//             while(!child.empty()){
//                 parent.push(child.top());
//                 child.pop();
//             }
//             vector<int> buff;
//             while(!parent.empty()){
//                 buff.push_back(parent.top()->val);
//                 if(parent.top()->left) child.push(parent.top()->left);
//                 if(parent.top()->right) child.push(parent.top()->right);
//                 parent.pop();
//             }
//             ans.push_back(buff);
//         }while(!child.empty());
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return vector<vector<int>>();
        queue<TreeNode*> que;
        vector<vector<int>> ans;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            vector<int> level;

            for(int i=0;i<size;++i){
                level.push_back(que.front()->val);
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                que.pop();
            }
            ans.push_back(level);
        }
        return ans;
    }
};