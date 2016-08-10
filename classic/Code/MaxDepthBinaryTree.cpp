/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void d(TreeNode*root,int&n){
        
        if(root->left==NULL){
            if(root->right==NULL){
                return;
            }else{
                d(root->right,n);
                n++;
            }
        }else{
            if(root->right==NULL){
                d(root->left,n);
                n++;
            }else{
                int m=n;
                d(root->left,n);
                d(root->right,m);
                n=max(m,n)+1;
            }
        }
    }
    int maxDepth(TreeNode *root) {
        if(!root)return 0;
        int n=1;
        d(root,n);
        return n;
        
    }
    
};
