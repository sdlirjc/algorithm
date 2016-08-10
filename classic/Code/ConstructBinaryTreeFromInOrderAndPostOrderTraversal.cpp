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
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd) {
        if (inStart>inEnd){
            return NULL;
        }
        if (postStart>postEnd){
            return NULL;
        }
        TreeNode*treenode=new TreeNode(postorder[postEnd]);
        int i=inStart;
        for(;i<=inEnd;i++){
            if(inorder[i]==treenode->val){
                break;
            }
        }
        if(i>inEnd){
            return NULL;
        }
        treenode->left=buildTree(inorder,inStart,i-1,postorder,postStart, postStart+i-1-inStart);
        treenode->right=buildTree(inorder,i+1,inEnd,postorder,postStart+i-inStart,postEnd-1);
        return treenode;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size()!=postorder.size())return NULL;
        return buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        
    }
};
