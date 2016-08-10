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

    vector<vector<int> > levelOrder(TreeNode *root) {

        vector<vector<int> > r;

        if (root==NULL) return r;

        queue<TreeNode*>q;

        q.push(root);

        int c=1,n=0,v=0;

        vector<int>l;

        while(q.size()!=0){

            TreeNode * no=q.front();

            q.pop();

            v++;

            l.push_back(no->val);

            if(no->left!=NULL){

                q.push(no->left);

                n++;

            }

            if(no->right!=NULL){

                q.push(no->right);

                n++;

            }

            if(v==c){

                v=0;

                c=n;

                n=0;

                r.push_back(l);

                l.clear();

            }

        }

        return r;

    }

};
