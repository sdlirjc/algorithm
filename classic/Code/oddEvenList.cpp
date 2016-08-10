/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next){
            return head;
        }
        ListNode * oddDummyHead = new ListNode(-1);
        ListNode * evenDummyHead = new ListNode(-1);
        oddDummyHead->next=head;
        evenDummyHead->next=head->next;
        ListNode * oddCurHead = head;
        ListNode * oddPreHead = head;
        ListNode * evenCurHead = head->next;
        while(oddCurHead&&oddCurHead->next&&oddCurHead->next->next){
            oddCurHead->next=evenCurHead->next;
            oddPreHead = oddCurHead;
            oddCurHead=oddCurHead->next;
            evenCurHead->next=oddCurHead->next;
            evenCurHead=evenCurHead->next;
        }
        if(!oddCurHead){
            oddPreHead->next=evenDummyHead->next;
        }else{
            oddCurHead->next=evenDummyHead->next;
        }
        return oddDummyHead->next;
    }
};
