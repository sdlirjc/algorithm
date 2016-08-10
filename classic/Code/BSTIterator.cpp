/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> leftS;
    TreeNode * iter; 
public:
    BSTIterator(TreeNode *root) {
        iter = root ;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(iter==NULL&&leftS.size()==0){
            return false;
        }else{
            return true; 
        }
    }

    /** @return the next smallest number */
    int next() {
        while(iter){
            leftS.push(iter);
            iter=iter->left;
        }
        TreeNode * ret = leftS.top();
        leftS.pop();
        iter = ret -> right; 
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
