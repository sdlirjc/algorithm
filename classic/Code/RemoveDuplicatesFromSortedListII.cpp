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
        if (!head)return head;
        ListNode * fake = new ListNode(INT_MAX);
        fake->next=head;
        ListNode*tmp=head;
        ListNode*current=fake;
        while(tmp){
            bool isDup=false;
            while(tmp->next&&tmp->val==tmp->next->val){
                if(!isDup)isDup=true;
                ListNode*del=tmp;
                tmp=tmp->next;
                delete del;
            }
            if(isDup){
                ListNode*del=tmp;
                tmp=tmp->next;
                delete del;
                continue;
            }
            current->next=tmp;
            current=current->next;
            tmp=tmp->next;
        }
        current->next = tmp;
        
        return fake->next; 
    }
};

