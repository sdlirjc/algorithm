/*366. Find Leaves of Binary Tree My Submissions QuestionEditorial Solution
Total Accepted: 1200 Total Submissions: 2253 Difficulty: Medium
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Removing the leaves [4, 5, 3] would result in this tree:

          1
         / 
        2          
2. Now removing the leaf [2] would result in this tree:

          1          
3. Now removing the leaf [1] would result in the empty tree:

          []         
Returns [4, 5, 3], [2], [1].*/

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res ; 
        while (root){
            vector<int>leaves;
            root=remove(root,leaves);
            res.push_back(leaves);
        }
        return res;
    }
    TreeNode* remove(TreeNode* root,vector<int>&leaves){
        if(!root){
            return NULL;
        }
        if(!(root->left)&&!(root->right)){
            leaves.push_back(root->val);
            return NULL;
        }
        root->left=remove(root->left,leaves);
        root->right=remove(root->right,leaves);
        return root;
    }
};
