package solution;

/**
 * Definition for binary tree
 */

public class Solution {
	public class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	int digit(int input) {
		int tmp = input;
		int counter = 0;
		if (input < 0)
			input = -input;
		if (input == 0)
			return 1;
		while (tmp != 0) {
			tmp = tmp / 10;
			counter++;
		}
		return counter;
	}

	public int sumNumbers(TreeNode root) {
		if (root == null)
			return 0;
		else if (root.left != null && root.right != null) {
			return (root.val * (int) Math.pow(10, digit(sumNumbers(root.left)))
					+ sumNumbers(root.left) + root.val
					* (int) Math.pow(10, digit(sumNumbers(root.right))) + sumNumbers(root.right));
		} else if (root.left != null && root.right == null) {
			return root.val * (int) Math.pow(10, digit(sumNumbers(root.left)))
					+ sumNumbers(root.left);
		} else if (root.left == null && root.right != null) {
			return (root.val
					* (int) Math.pow(10, digit(sumNumbers(root.right))) + sumNumbers(root.right));
		} else {
			return root.val;
		}
	}

	public static void main(String[] argv) {
		Solution s = new Solution();
		System.out.println(s.digit(-1));
		System.out.println(s.digit(5));
	}
}