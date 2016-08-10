/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
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
    public TreeNode convert(ListNode start, ListNode end){
        int n=0;
        ListNode tmp=start;
        if(start==end)return null;
        while(tmp!=end&&tmp!=null){
            tmp=tmp.next;
            n++;
        }
        int mid=n/2;
        tmp=start;
        for(int i=0;i<mid;i++){
            tmp=tmp.next;
        }
        TreeNode node=new TreeNode(tmp.val);
        node.left=convert(start,tmp);
        node.right=convert(tmp.next,end);
        return node;
    }
    public TreeNode sortedListToBST(ListNode head) {
        return convert(head,null);
    }
}
