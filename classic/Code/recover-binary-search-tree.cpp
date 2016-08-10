/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*http://fisherlei.blogspot.com/2012/12/leetcode-recover-binary-search-tree.html*/
class Solution {
public:
    void InOrderTraverse(TreeNode* root,vector<TreeNode*>&list,vector<int>&val){
        if(!root)return;
        InOrderTraverse(root->left,list,val);
        list.push_back(root);
        val.push_back(root->val);
        InOrderTraverse(root->right,list,val);
    }
    void recoverTree(TreeNode *root) {
        vector<TreeNode*>list;
        vector<int>val;
        InOrderTraverse(root,list,val);
        sort(val.begin(),val.end());
        for(int i=0;i<val.size();i++){
            list[i]->val=val[i];
        }
        
    }
};
