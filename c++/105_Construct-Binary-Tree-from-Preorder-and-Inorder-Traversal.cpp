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
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>&mp) {
        //ending condition
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* node = new TreeNode(preorder[preStart]);
        int inRoot = mp[node->val];
        int numLeft = inRoot - inStart;

        //Preorder
        //Left subtree: preStart+1 : preStart + nunLeft
        //Right subtree: preStart+numLeft+1 : preEnd

        //Inorder
        //Left subtree: inStart : (inRoot-1)
        //Right subtree: (inRoot+1) : inEnd
        node->left = build(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, mp);
        node->right = build(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, mp);
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int idx=0; idx<inorder.size(); idx++){
            mp[inorder[idx]] = idx;
        }

        int n = preorder.size();
        int m = inorder.size();

        TreeNode* root = build(preorder, 0, n-1, inorder, 0, m-1, mp);
        return root;
    }
};


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
    // #1 Recursion
    TreeNode* _build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<int,int>& mp){
        // end case
        if(preStart > preEnd || inStart > inEnd) return nullptr;
        
        int inNode = mp[preorder[preStart]];
        int leftNum = inNode - inStart;
        TreeNode* curNode = new TreeNode(preorder[preStart]);
        curNode->left = _build(preorder, inorder, preStart+1, preEnd, inStart, inNode-1, mp);
        curNode->right = _build(preorder, inorder, preStart+leftNum+1, preEnd, inNode+1, inEnd, mp);
        return curNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<inorder.size();++i) mp[inorder[i]]=i;

        int preStart=0, preEnd=n-1;
        int inStart=0, inEnd=n-1;
        return _build(preorder, inorder, preStart, preEnd, inStart, inEnd, mp);
    }
    // #2 Update the vector of preorder and inorder
    // Reconstruct preorder and inorder to build subtree
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     //base cases
    //     if(preorder.empty()) return nullptr;
        
    //     int idx;
    //     for(int i=0;i<inorder.size();++i){
    //         if(inorder[i]==preorder[0]){
    //             idx=i;
    //             break;
    //         }
    //     }
    //     TreeNode* root = new TreeNode(preorder[0]);
    //     vector<int> sub_left_preorder(preorder.begin()+1, preorder.begin()+1+idx);
    //     vector<int> sub_left_inorder(inorder.begin(), inorder.begin()+idx);
    //     root->left = buildTree(sub_left_preorder, sub_left_inorder);
        
    //     vector<int> sub_right_preorder(preorder.begin()+idx+1, preorder.end());
    //     vector<int> sub_right_inorder(inorder.begin()+idx+1, inorder.end());
    //     root->right = buildTree(sub_right_preorder, sub_right_inorder);
    //     return root;
    // }

};