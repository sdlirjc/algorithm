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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> >val;
        if(root==NULL)return val;
        if(root->left==NULL&&root->right==NULL){
            if(root->val==sum){
                vector<int>v;
                v.push_back(sum);
                val.push_back(v);
            }
            return val;
        }
        if(root->left){
            vector<vector<int> >vl=pathSum(root->left,sum-root->val);
            for(int i=0;i<vl.size();i++){
                vl[i].insert(vl[i].begin(),root->val);
                val.push_back(vl[i]);
            }
        }
        if(root->right){
            vector<vector<int> >vr=pathSum(root->right,sum-root->val);
            for(int i=0;i<vr.size();i++){
                vr[i].insert(vr[i].begin(),root->val);
                val.push_back(vr[i]);
            }
        }
        return val;      
    }
};
