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
    ListNode* reverseList(ListNode* head) {
        if(!head){return head;}
        if(!head->next){return head;}
        ListNode * next = NULL;
        while(head->next){
            ListNode * tmp = head->next; 
            head->next = next;
            next=head;
            head=tmp;
        }
        head->next=next;
        return head;
    }
};
