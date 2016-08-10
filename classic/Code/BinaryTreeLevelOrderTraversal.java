/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer> >result=new ArrayList<List<Integer> >();
        if(root==null){
            return result;
        }
        Queue<TreeNode>current_level=new LinkedList<TreeNode>();
        Queue<TreeNode>next_level=new LinkedList<TreeNode>();
        current_level.add(root);
        while(!current_level.isEmpty()){
            List<Integer>currentResult=new ArrayList<Integer>();
            while(!current_level.isEmpty()){
                TreeNode node=current_level.poll();
                currentResult.add(node.val);
                if(node.left!=null){
                    next_level.add(node.left);
                }
                if(node.right!=null){
                    next_level.add(node.right);
                }
            }
            result.add(currentResult);
            Queue<TreeNode>tmp=current_level;
            current_level=next_level;
            next_level=tmp;
        }
        return result;
    }
}
