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
    ListNode *sortList(ListNode *head) {
        if(!head)return NULL;
        int len=0;
        ListNode* it=head;
        while(it){
            it=it->next;
            len++;
        }
        return sort(&head,len);
    }
    ListNode*sort(ListNode**head,int len){
        if(len==1){
            ListNode*temp=*head;
            *head=(*head)->next;
            temp->next=NULL;
            return temp;
        }
        return merge(sort(head,len/2),sort(head,len-len/2));
    }
    ListNode*merge(ListNode*left,ListNode*right){
        ListNode*head=new ListNode(-1);
        ListNode*cur=head;
        while(left!=NULL||right!=NULL){
            int lv=(left==NULL)?INT_MAX:left->val;
            int rv=(right==NULL)?INT_MAX:right->val;
            if(lv<rv){
                cur->next=left;
                left=left->next;
            }else{
                cur->next=right;
                right=right->next;
            }
            cur=cur->next;
        }
        cur=head->next;
        delete head;
        return cur;
    }
};
