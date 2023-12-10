class Solution {
public:
    void sortedSubArrayToBST(vector<int>& nums, int st, int ed, TreeNode* node){
        if(ed < st) return;
        int mid = (st+ed)/2;
        TreeNode* thisnode = new TreeNode(nums[mid]);
        if(nums[mid] < node->val){
            node->left = thisnode;
        }else{
            node->right = thisnode;
        }

        sortedSubArrayToBST(nums, st, mid-1, thisnode);
        sortedSubArrayToBST(nums, mid+1, ed, thisnode);            
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = (nums.size()-1)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        sortedSubArrayToBST(nums, 0, mid-1, root);
        sortedSubArrayToBST(nums, mid+1, nums.size()-1, root);
        
        return root;
    }
};