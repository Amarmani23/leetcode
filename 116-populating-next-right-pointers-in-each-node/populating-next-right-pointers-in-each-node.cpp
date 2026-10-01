/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // Node* connect(Node* root) {
    //     if(!root) return nullptr;
    //     dfs(root);
    //     return root;
    // }
    // void dfs(Node* root){
    //     if(!root ||!root->left) return;
    //     root->left->next=root->right;
    //     if(root->next){
    //         root->right->next=root->next->left;

    //     }
    //     connect(root->left);
    //     connect(root->right);
    // }


    Node* connect(Node* root){
        if(!root || !root->left) return root;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        Node* prev=NULL;

        while(q.size()>0){
            Node* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(q.size()==0){
                    break;
                }else{
                    q.push(NULL);
                }
            }else{

                if(curr->left != NULL){
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                if(prev!=NULL){
                    prev->next=curr;
                }
            }
            prev=curr;
        }
        return root;
    }
};