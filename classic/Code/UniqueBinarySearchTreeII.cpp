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
    vector<TreeNode *> generate(int start, int end ){
        vector<TreeNode*>subtree;
        if (start>end){
            subtree.push_back(NULL);
            return subtree;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>left=generate(start,i-1);
            vector<TreeNode*>right=generate(i+1,end);
            for(int j=0;j<left.size();j++){
                for(int k=0;k<right.size();k++){
                    TreeNode*t=new TreeNode(i);
                    t->left=left[j];
                    t->right=right[k];
                    subtree.push_back(t);
                }
            }
        }
        return subtree;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generate(1,n);
    }
    
};
