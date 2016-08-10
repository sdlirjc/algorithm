#include"header.h"
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode*cut=head;
        ListNode*fake=new ListNode(0);
        ListNode*retval=fake;
        fake->next=head;
        if(!head){return NULL;}
        else if(cut->val>=x){
        }else{
            while(cut&&cut->val<x){
                
                cut=cut->next;
                fake=fake->next;
            }
            if(cut==NULL){return head;}else{
                
            }
        }
        ListNode*last=fake;
        cout<<"last before moving: "<<last->val<<endl;
        ListNode*current=cut;
        
        while(current){
            cout<<"last before moving: "<<last->val<<endl;
            if(current->val<x){
                cout<<"current: "<<current->val<<" is smaller than "<<x<<endl;
                last->next=current->next;
                cout<<"last: "<<last->val<<endl;
                fake->next=current;
                current->next=cut;
                fake=fake->next;
                if(last->next==NULL){
                    //last=NULL;
                    current=NULL;
                }else{
                    //last=last->next;
                    //cout<<"DEBUG:1 "<<last->val<<endl;
                    current=last->next;
                }
            }else{
                last=last->next;
                current=current->next;
            }
            //cout<<"current: "<<current->val<<endl;
        }
        return retval->next;
    }
};
int main(int argc,char**argv){
    Solution s;
    ListNode * l1=new ListNode(3);
    ListNode * l2=new ListNode(1);
    ListNode * l3=new ListNode(2);
    l1->next=l2;
    l2->next=l3;
    ListNode* result=s.partition(l1,3);
    while(result){
        cout<<result->val<<endl;
        result=result->next;
    }
    return 0;
}
