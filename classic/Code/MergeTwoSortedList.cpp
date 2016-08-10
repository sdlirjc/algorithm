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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode*n=NULL;
        if(l1&&l2)if(l1->val<l2->val){n=l1;l1=l1->next;}else{n=l2;l2=l2->next;}
        else if(!l2&&!l1)return NULL;
        else if(!l2&&l1){n=l1;l1=l1->next;}
        else if(!l1&&l2){n=l2;l2=l2->next;}
        ListNode * head=n;
        while (l1&&l2){
            if(l1->val<l2->val){
                n->next=l1;
                l1=l1->next;
                n=n->next;
            }else{
                n->next=l2;
                l2=l2->next;
                n=n->next;
            }
        }
        while(l1){
            n->next=l1;
            l1=l1->next;
            n=n->next;
        }
        while(l2){
            n->next=l2;
            l2=l2->next;
            n=n->next;
        }
        return head;
    }
};
