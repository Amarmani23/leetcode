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
    int minDepth(TreeNode* root) {
        // if(!root) return 0;
        // int leftheight=minDepth(root->left);
        // int rightheight=minDepth(root->right);
        // if(leftheight && !rightheight || !leftheight && rightheight){
        //     return max(leftheight,rightheight)+1;
        // }
        // return min(leftheight,rightheight)+1;


        if (!root) return 0;
        
        // If left child is null, recurse down the right subtree
        if (!root->left) return 1 + minDepth(root->right);
        
        // If right child is null, recurse down the left subtree
        if (!root->right) return 1 + minDepth(root->left);
        
        // If both children exist, take the minimum of both paths
        return 1 + min(minDepth(root->left), minDepth(root->right));

    }
    
};