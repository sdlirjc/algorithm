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
    bool valid(TreeNode*root,int MIN,int MAX){
        if(root==NULL){
            return true;
        }
        if(root->val>MIN&&root->val<MAX&&valid(root->left,MIN,root->val)&&valid(root->right,root->val,MAX)){
            return true;
        }else{
            return false;
        }
    }
    bool isValidBST(TreeNode *root) {
        return valid(root,INT_MIN,INT_MAX);
    }
};
