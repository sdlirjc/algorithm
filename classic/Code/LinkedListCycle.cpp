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
    bool hasCycle(ListNode *head) {
        if (head==NULL)return false;
        if(head->next==NULL)return false;
        ListNode*n1=head->next;
        ListNode*n2=head->next->next;
        if(n1==n2)return true;
        while (n1->next!=NULL&&n2->next!=NULL&&n2->next->next!=NULL&&n1!=n2){
            n1=n1->next;
            n2=n2->next->next;
            if(n1==n2)return true;
        }
    }
};
