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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> >result;
        if(root==NULL){return result;}
        stack<TreeNode*>current_level;
        stack<TreeNode*>next_level;
        current_level.push(root);
        bool normalOrder=true;
        while (!current_level.empty()){
            vector<int>currentResult;
            while (!current_level.empty()){
                TreeNode*node=current_level.top();
                current_level.pop();
                currentResult.push_back(node->val);
                if(normalOrder){
                    if(node->left){next_level.push(node->left);}
                    if(node->right){next_level.push(node->right);}
                }else{
                    if(node->right){next_level.push(node->right);}
                    if(node->left){next_level.push(node->left);}
                }
            }
            result.push_back(currentResult);
            //swap(current_level,next_level);
            current_level.swap(next_level);
            //current_level=next_level;
            //while(!next_level.empty()){next_level.pop();}
            normalOrder=!normalOrder;
        }
        return result;
    }
};
