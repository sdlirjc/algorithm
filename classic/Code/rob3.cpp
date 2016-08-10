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

    int rob(TreeNode* root) {

        return dfs(root).first;

    }

    pair<int,int>dfs(TreeNode*root){

        pair<int, int> ret = make_pair(0,0);

        if(!root){

            return ret;

        }

        pair<int,int> R=dfs(root->right);

        pair<int,int> L=dfs(root->left);

        //choose children, sometimes children are not chosen as well, 

        // children's children are chosen

        ret.second=L.first+R.first;

        //don't choose children

        ret.first=max(ret.second,root->val+L.second+R.second);

        return ret;

    }

};
