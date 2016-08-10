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

    TreeNode* invertTree(TreeNode* root) {

        if(!root){

            return NULL;

        }

        if(root->left&&root->right){

            TreeNode * tmp = root->left;

            root->left = invertTree(root->right);

            root->right = invertTree(tmp);

        }else if(root->left&&!root->right){

            root->right = invertTree(root->left);

            root->left=NULL;

        }else if(!root->left&&root->right){

            root->left = invertTree(root->right);

            root->right=NULL;

        }

        return root;

    }

};
