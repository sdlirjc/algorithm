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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int>v;
        if(root==NULL)return v;
        v.push_back(root->val);
        vector<int>vl=preorderTraversal(root->left);
        vector<int>vr=preorderTraversal(root->right);
        for(int i=0;i<vl.size();i++)v.push_back(vl[i]);
        for(int i=0;i<vr.size();i++)v.push_back(vr[i]);
    }
};
