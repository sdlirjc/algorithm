# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} val
    # @return {ListNode}
    def removeElements(self, head, val):
        if head is None:
            return
        fake= ListNode(0)
        last=fake
        fake.next=head
        while head is not None:
            if head.val==val:
                last.next=head.next
            else:
                last=head
            head=head.next
        return fake.next

        
