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
    int maxPathSum(TreeNode* root) {
        int global_max = INT_MIN;
        dfs(root,global_max);
        return global_max;

    }
private:
    int dfs(TreeNode* node,int &global_max){
        if(node==nullptr){
            return 0;

        }
        int left_max=max(dfs(node->left,global_max),0);
        int right_max=max(dfs(node->right,global_max),0);

        int current_U_sum=node->val+left_max+right_max;
        global_max=max(global_max,current_U_sum);
        return node->val + max(left_max,right_max);
    }
};