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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return dfs(root,0);
    }
private:
    int dfs(TreeNode* root,int curr_sum){
        if(!root) return 0;
        curr_sum=curr_sum*10+root->val;
        if(!root->left && !root->right){
            return curr_sum;
        }
        int left_sum=dfs(root->left,curr_sum);
        int right_sum=dfs(root->right,curr_sum);
        return left_sum+right_sum;
    }
};