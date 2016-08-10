/**
 * Definition for binary tree
*/

import java.util.*;
import java.io.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class FlattenBinaryTreeToLinkedList {
    public void flatten(TreeNode root) {
        if(root==null){return ;}
        if(root.left!=null){
            if(root.right!=null){
                flatten(root.left);
                TreeNode left=root.left;
                flatten(root.right);
                TreeNode right=root.right;
                while(left.right!=null){
                    left=left.right;
                }
                left.right=right;
                root.right=root.left;
                root.left=null;
            }else{
                root.right=root.left;
                flatten(root.right);
                root.left=null;
            }
        }else{
            if(root.right!=null){
                flatten(root.right);
            }else{
                return;
            }
        }
    }
    public static void main(String[]argv){
        TreeNode root=null;
        FlattenBinaryTreeToLinkedList ob = new FlattenBinaryTreeToLinkedList();
        ob.flatten(root);
    }
}



