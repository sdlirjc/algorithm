//  Definition for singly-linked list.
#include"header.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode*rev(ListNode*head){
            if(!head->next)return head;
            if(!head->next->next){head->next->next=head;ListNode*newHead=head->next;head->next=NULL;return newHead;}
            ListNode*t1=head;
            ListNode*t2=head->next;
            ListNode*t3=t2->next;
            head->next=NULL;
            while(t3){
                t2->next=t1;
                t1=t2;
                t2=t3;
                t3=t3->next;
            }
            t2->next=t1;
            return t2;
        }
        void reorderList(ListNode *head) {
            if(!head)return ;
            if(!head->next)return;
            int l=0;
            ListNode*h1=head;
            ListNode*h2=head;
            while(head){
                head=head->next;
                l++;
            }
            head=h1;
            if(l<=2)return;
            int m=l/2;
            ListNode*h1Tail;
            for(int i=0;i<m;i++){
                if(i==m-1)h1Tail=h2;
                h2=h2->next;
            }
            h1Tail->next=NULL;
            cout<<h2->val<<endl;
            h2=rev(h2);
            cout<<h2->val<<endl;
            head=h1;
            while(h1&&h2){
                ListNode*t1=h1->next;
                ListNode*t2=h2->next;
                h1->next=h2;
                h2->next=t1?t1:t2;
                h2=t2;
                h1=t1;
            }
        }
};
int main(int argc,char**argv){
    Solution s;
    ListNode*tmp=new ListNode(1);
    ListNode*n=tmp;
    for(int i=2;i<=7;i++){
        n->next=new ListNode(i);
        n=n->next;
    }
    s.reorderList(tmp);
    return 0;
}
