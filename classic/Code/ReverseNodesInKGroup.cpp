/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "header.h"
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode*fake=new ListNode(-9999);
        fake->next=head;
        if(!head||k==1)return head;
        ListNode*pre=fake,*cur=head,*post=head->next;
        while(cur&&cur->next){
            post=cur->next;
            int i=0;
            while(i<k-1&&post){
                ListNode*tmp=post->next;
                post->next=cur;
                cur=post;
                post=tmp;
                i++;
            }
            if(i!=k-1){
                int k=0;
                ListNode*tmp=post;
                post=cur;
                cur=tmp;
                while(k<i){
                    tmp=post->next;
                    post->next=cur;
                    cur=post;
                    post=tmp;
                    k++;
                }
                break;
            }
            cout<<"DEBUG:1"<<endl;
            ListNode*tmp=pre->next;
            cout<<"DEBUG:2: "<<tmp->val<<endl;
            pre->next=cur;
            cout<<"DEBUG:3"<<endl;
            tmp->next=post;
            cout<<"DEBUG:4"<<endl;
            //if(post){tmp->next=post;}else{tmp->next=NULL;}
            pre=tmp;
            cout<<"DEBUG:5"<<endl;
            cur=pre->next;
        }
        head=fake->next;
        delete fake;
        return head;
    }
};
int main(){
    Solution s;
    int input[]={1,2};
    ListNode*fake=new ListNode(-9999);
    ListNode*cur=fake;
    for(int i=0;i<sizeof(input)/sizeof(input[0]);i++){
        ListNode * tmp=new ListNode(input[i]);
        cur->next=tmp;
        cur=cur->next;
    }
    cur->next=NULL;
    ListNode*newhead=s.reverseKGroup(fake->next, sizeof(input)/sizeof(input[0]));
    while(newhead){
        cout<<newhead->val<<endl;
        newhead=newhead->next;
    }
}
