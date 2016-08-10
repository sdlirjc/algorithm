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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode tmp=head;
        for(int i=0;i<n;i++){
            tmp=tmp.next;
        }
        ListNode pre=new ListNode(0);
        ListNode fake=pre;
        pre.next=head;
        ListNode ret=head;
        while(tmp!=null){
            tmp=tmp.next;
            ret=ret.next;
            pre=pre.next;
        }
        pre.next=ret.next;
        return fake.next;
    }
}
