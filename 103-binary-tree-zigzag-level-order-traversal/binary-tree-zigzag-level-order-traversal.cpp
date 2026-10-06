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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=false;
        while(!q.empty()){
            int q_size=q.size();
            vector<int>curr(q_size);
            for(int i=0;i<q_size;i++){
                TreeNode* node=q.front();
                q.pop();
                int idx=flag ?(q_size -1 -i): i;
                curr[idx]=node->val;
               
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
                
            }
            flag=!flag;
            ans.push_back(curr);
        }
        return ans;
    }
};