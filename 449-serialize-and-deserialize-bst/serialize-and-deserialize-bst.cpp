/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result="";
        if(!root) return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto curr=q.front();
                q.pop();
                result+=to_string(curr->val) + ",";
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            
        }
        return result;
    }
    struct nodestatus{
        TreeNode* node;
        long long min_val;
        long long max_val;
    };
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")return NULL;
        vector<int>vals;
        stringstream ss(data);
        string item;
        while(getline(ss,item,',')){
            vals.push_back(stoi(item));
        }
        int i =0;
        TreeNode* root=new TreeNode(vals[i++]);
        queue<nodestatus>q;
        q.push({root,LLONG_MIN,LLONG_MAX});
        while(!q.empty() && i<vals.size()){
            auto [currNode,min_val,max_val]=q.front();
            q.pop();
            if(i<vals.size()&&vals[i]>min_val && vals[i]<currNode->val){
                currNode->left=new TreeNode(vals[i]);
                q.push({currNode->left,min_val,currNode->val});
                i++;
            }
            if(i<vals.size() && vals[i]<max_val&&vals[i]>currNode->val){
                currNode->right=new TreeNode(vals[i]);
                q.push({currNode->right,currNode->val,max_val});
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;