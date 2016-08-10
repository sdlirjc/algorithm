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
    int sumNumbers(TreeNode *root) {
        int sum=0,path=0;
        GenerateSum(root,path, sum);
        return sum;
        
    }
    void GenerateSum(TreeNode*root,int path,int&sum){
        if(!root)return;
        path=path*10+root->val;
        if(!root->left&&!root->right) {sum+=path;return;}
        GenerateSum(root->right,path, sum);
        GenerateSum(root->left,path, sum);
        
    }
    
};
