/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count=0;
    int result = 0 ; 
    void traverse(TreeNode * root , int k){
        if(!root){
            return; 
        }
        traverse(root->left,k);
        count++;
        if(count==k){
            result=root->val;
            return;
        }
        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        traverse(root,k);
        return result;
    }
};
