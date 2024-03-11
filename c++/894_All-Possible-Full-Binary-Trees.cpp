#include <iostream>
#include <unordered_map>
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
    unordered_map<int, vector<TreeNode*>>dp;
public:
    //1. Don't create node from top to down since they will inherit other's result
    //2. Try bottom up. Every node are new
    vector<TreeNode*> allPossibleFBT_recursion(int n) {
        if(n%2==0) return{};
        if(n==1) return{new TreeNode()};

        vector<TreeNode*> cur;
        
        //Leave one node for root, so l and r should be odd number
        for(int l=1;l<n-1;l+=2){
            int r=n-1-l;
            
            vector<TreeNode*> leftPossible = allPossibleFBT_recursion(l);
            vector<TreeNode*> rightPossible = allPossibleFBT_recursion(r);

            for(auto left:leftPossible){
                for(auto right:rightPossible){
                    TreeNode* root = new TreeNode();
                    root->left = left;
                    root->right = right;
                    cur.push_back(root);
                }
            }
        }

        return cur;
    }

    vector<TreeNode*> allPossibleFBT_memoization(int n){
        if(n%2==0) return{};
        if(n==1) return{new TreeNode()};
        //Check if FPT(n) already exist in DP matrix
        if(dp.count(n)) return dp[n];

        vector<TreeNode*>cur;

        for(int l=1;l<n-1;l+=2){
            int r=n-1-l;

            vector<TreeNode*> leftPossible = allPossibleFBT_memoization(l);
            vector<TreeNode*> rightPossible = allPossibleFBT_memoization(r);

            for(auto left:leftPossible){
                for(auto right:rightPossible){
                    TreeNode* root = new TreeNode();
                    root->left = left;
                    root->right = right;
                    cur.push_back(root);
                }
            }
        }
        dp[n]=cur;
        return cur;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        
        //#1 Recursion only
        //return allPossibleFBT_recursion(n);

        //#1 Memoization
        return allPossibleFBT_memoization(n);
    }
};