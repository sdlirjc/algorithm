#include"header.h"

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root==NULL)return ;
        
        if(root->left!=NULL){
            if(root->right!=NULL){
                flatten(root->left);
                TreeNode*left=root->left;
                flatten(root->right);
                TreeNode*right=root->right;
                TreeNode*val=root->left;
                while (left->right){
                    left=left->right;
                }
                left->right=right;
                root->right=val;
            }else{
                root->right=root->left;
                flatten(root->left);
            }
        }else{
            if(root->right!=NULL){
                flatten(root->right);
            }else{
                return;
            }
        }
        return;
    }
};

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
    TreeNode* help(TreeNode*root,TreeNode*tail){
        if(!root)return tail;
        root->right=help(root->left,help(root->right,tail));
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode *root) {
        if(root==NULL)return ;
        help(root,NULL);
    }
};

int main(int argc,char**argv){
    Solution s;
    TreeNode*tree=new TreeNode(1);
    TreeNode*t1=new TreeNode(2);
    tree->right=t1;
    s.flatten(tree);
}
