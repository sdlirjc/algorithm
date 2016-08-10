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
    bool check(TreeNode*root,int &mi,int&ma){
        if(!root){ mi=0;ma=0;return true;}
        int lmi;
        int rmi;
        int lma;
        int rma;
        bool lbal= check(root->left,lmi,lma);
        bool rbal= check(root->right,rmi,rma);
        mi=min(lmi,rmi)+1;
        ma=max(lma,rma)+1;
        return lbal&&rbal&&abs(lma-rma)<=1;
    }
    bool isBalanced(TreeNode *root) {
        if (!root)return true;
        if(!root->left&&!root->right)return true;
        int mi,ma;
        return check(root,mi,ma);
    }
};
