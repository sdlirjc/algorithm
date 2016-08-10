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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<int>l;
        vector<vector<int> >ret;
        if(!root)return ret;
        //ret.push_back(l);
        queue<TreeNode*>q;
        vector<TreeNode*>v;
        q.push(root);
        bool cont=true;
        while (cont){
            TreeNode* r=q.front();
            l.push_back(r->val);
            q.pop();
            if(r->left)v.push_back(r->left);
            if(r->right)v.push_back(r->right);
            if(q.empty()){
                for(int i=0;i<v.size();i++){
                    q.push(v[i]);
                }
                ret.push_back(l);
                v.clear();
                l.clear();
                if(q.empty()&&!r->left&&!r->right)cont=false;
            }
        }
        vector<vector<int> >reverse;
        for(int i=ret.size()-1;i>=0;i--){
            reverse.push_back(ret[i]);
        }
        return reverse;
    }
};
