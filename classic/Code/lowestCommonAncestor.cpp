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
    bool contains(TreeNode*root,TreeNode*p){
        if(root==NULL)return false;
        if(root->val==p->val){return true;}
        return contains(root->left,p)||contains(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){return NULL;}
        bool cp=contains(root,p);
        bool cq=contains(root,q);
        if(cq&&cp){
            bool lp=contains(root->left,p);
            bool lq=contains(root->left,q);
            bool rp=contains(root->right,p);
            bool rq=contains(root->right,q);
            if(lq&&lp){return lowestCommonAncestor(root->left,p,q);}
            if(rq&&rp){return lowestCommonAncestor(root->right,p,q);}
            return root; 
        }
        return NULL;
    }
};
