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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<vector<int>>res;
        vector<int>curr;
        path(root,targetSum,res,curr);
        return res;
    }
    void path(TreeNode* root, int targetSum,vector<vector<int>>&res,vector<int>&curr){
        if(root==nullptr) return;
        
        targetSum-=root->val;
        
        curr.push_back(root->val);
        if(!root->left && !root->right){
            if(targetSum == 0){
                res.push_back(curr);
                
            }
        }
        path(root->left,targetSum,res,curr);
        path(root->right,targetSum,res,curr);
        curr.pop_back();
    }
};