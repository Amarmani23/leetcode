/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(int low,int high,ListNode* &curr){
        if(low>high){
            return NULL;
        }
        int mid=low+(high-low)/2;

        TreeNode* leftNode=solve(low,mid-1,curr);
        TreeNode* root=new TreeNode(curr->val);
        root->left=leftNode;
        curr=curr->next;
        root->right=solve(mid+1,high,curr);
        return root;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr=head;
        int count=0;
        while(curr!=nullptr){
            count++;
            curr=curr->next;
        }
        return solve(0,count-1,head);
    }
};