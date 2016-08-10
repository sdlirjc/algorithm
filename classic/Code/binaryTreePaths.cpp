//Given a binary tree, return all root-to-leaf paths.

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
    void help(TreeNode*root,string path,vector<string>&ret){
        string tmp=to_string(root->val);
        if(path.size()>0){
            tmp=path+"->"+tmp;
        }
        if(!root->left&&!root->right){
            ret.push_back(tmp);
        }
        if(root->left){
            help(root->left,tmp,ret);
        }
        if(root->right){
            help(root->right,tmp,ret);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ret;
        if(!root){
            return ret;
        }
        help(root,"",ret);
        return ret;
    }
};
