
package problem;

public class ValidateBST {
    class TreeNode {
        TreeNode left;
        TreeNode right;
        int val;

        TreeNode(final int x) {
            val = x;
        }
    }

    public boolean isValidBST(final TreeNode root) {
        if (root == null) {
            return false;
        }
        if (root.left != null && root.right != null) {
            if (root.left.val < root.val && root.right.val > root.val) {
                return isValidBST(root.left) && isValidBST(root.right);
            } else {
                return false;
            }
        } else if (root.left == null && root.right != null) {
            if (root.val < root.right.val) {
                return isValidBST(root.right);
            } else {
                return false;
            }
        } else if (root.right == null && root.left != null) {
            if (root.val > root.left.val) {
                return isValidBST(root.left);
            } else {
                return false;
            }
        } else {
            return true;
        }
    }
}
