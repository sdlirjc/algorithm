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
    ListNode *swapPairs(ListNode *head) {
        if(!head||!head->next)return head; 
        ListNode* nextHead=head->next->next;
        ListNode* newHead=head->next;
        ListNode*newNext=head;
        newHead->next=newNext;
        newNext->next=swapPairs(nextHead);
        return newHead;
        
    }
};
