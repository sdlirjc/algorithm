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

    int minDepth(TreeNode *root) {

        if (root==NULL) return 0;

        int lmin=minDepth(root->left);

        int rmin=minDepth(root->right);

        if(lmin==0){

            return rmin==0?1:rmin+1;  

        }else{

            return rmin==0?lmin+1:min(lmin,rmin)+1;

        }

    }

};
