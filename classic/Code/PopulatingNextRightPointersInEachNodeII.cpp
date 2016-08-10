/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL){return;}
        TreeLinkNode*p=root->next;
        while(p){
            if(p->left){p=p->left;break;}
            if(p->right){p=p->right;break;}
            p=p->next;
        }
        if(root->right){root->right->next=p;}
        if(root->left){
            if(root->right){
                root->left->next=root->right;
            }else{
                root->left->next=p;
            }
        }
        connect(root->right);
        connect(root->left);
    }
};
