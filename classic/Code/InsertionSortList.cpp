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
    ListNode *insertionSortList(ListNode *head) {
        if(!head)return NULL;
        ListNode*inserted=head;
        while(inserted->next!=nullptr){
            ListNode*i=head;
            if(i->val>=inserted->next->val){
                i=inserted->next->next;
                inserted->next->next=head;
                head=inserted->next;
                inserted->next=i;
            }else{
                while(i->next->val<inserted->next->val){
                    i=i->next;
                }
                if(i!=inserted){
                    ListNode*tmp=i->next;
                    i->next=inserted->next;
                    ListNode*tmp1=inserted->next;
                    inserted->next=inserted->next->next;
                    tmp1->next=tmp;
                }else{
                    inserted=inserted->next;
                }
            }
        }
        return head;
    }
};
