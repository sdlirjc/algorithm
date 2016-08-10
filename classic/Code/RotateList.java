/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode rotateRight(ListNode head, int n) {
        // Start typing your Java solution below
        // DO NOT write main() function
        ListNode end=head; 
		ListNode cut = head; 
		if(head==null)return head;
		if(n==0)return head;
		int N=1;
		while(end.next!=null){
			end=end.next;
			N++;
		}
		int m=N-(n%N);
		end.next=head;
		for (int i=0;i<m-1;i++){
			cut=cut.next;
		}
		ListNode value=cut.next;
		cut.next=null;
		return value;
	}
}
