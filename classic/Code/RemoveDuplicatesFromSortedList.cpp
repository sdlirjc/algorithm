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
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)return NULL;
        ListNode*pre=head;
        ListNode*p=head->next;
        while(p){
            if(p->val==pre->val){
                ListNode*t=p;
                p=p->next;
                pre->next=p;
                delete t;
                continue;
            }
            pre=pre->next;
            p=p->next;
        }
        return head;
        
    }
};
