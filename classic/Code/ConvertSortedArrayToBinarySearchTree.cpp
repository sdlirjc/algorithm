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
    TreeNode* form(vector<int>&num,int s,int e){
        if(s<=e-1){
            int m=(s+e)/2;
            TreeNode*mNode=new TreeNode(num[m]);
            mNode->left=form(num,s,m);
            mNode->right=form(num,m+1,e);
            return mNode;
        } 
        return NULL;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if(!num.size())return NULL;
        int m=num.size()/2;
        TreeNode*n=new TreeNode(num[m]);
        n->left=form(num,0,m);
        n->right=form(num,m+1,num.size());
        return n;
    }
};
