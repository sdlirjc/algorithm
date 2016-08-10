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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step = n-m; 
        if(step<=0)return head;
        ListNode*fake=new ListNode(0);
        fake->next=head;
        ListNode*tmp=fake;
        ListNode*pre=NULL;
        int counter=0;
        while (counter<m){
            pre=tmp;
            tmp=tmp->next;
            counter++;
        }
        counter=0;
        ListNode*ReversingListlastElement=tmp;
        ListNode*preListLastElement=pre;
        ListNode*oldNext=NULL;
        while(counter<=step){
            ListNode*oldNext=tmp->next;
            if (counter==0){
                tmp->next=NULL;
            }else{
                tmp->next=pre;
            }
            pre=tmp;
            tmp=oldNext;
            counter++;
        }
        preListLastElement->next=pre;
        ReversingListlastElement->next=tmp;
        return fake->next;
    }
};
