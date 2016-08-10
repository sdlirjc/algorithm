#include"header.h"
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL){
            if(l2==NULL){
                return NULL;
            }else{
                return l2;
            }
        }else{
            if(l2==NULL){
                return l1;
            }else{
                ListNode*val=NULL;
                ListNode*retval=NULL;
                int carry=0;
                while(l1||l2){
                    //cout<<val<<"\t"<<l1<<"\t"<<l2<<endl;
                    if(l1==NULL){
                        if(val==NULL){
                            return l2;
                        }else{
                            int next=(l2->val+carry)%10;
                            carry=(l2->val+carry)/10;
                            l2->val=next;
                            val->next=l2;
                            l2=l2->next;
                            val=val->next;
                        }
                    }else{
                        if(l2==NULL){
                            if(val==NULL){
                                return l1;
                            }else{
                                
                                int next=(l1->val+carry)%10;
                                carry=(l1->val+carry)/10;
                                l1->val=next;
                                val->next=l1;
                                l1=l1->next;
                                val=val->next;
                            }
                        }else{
                            if(val==NULL){
                                int next=(l2->val+l1->val+carry)%10;
                                carry=(l2->val+l1->val+carry)/10;
                                l2->val=next;
                                val=l2;
                                retval=val;
                                
                                l2=l2->next;
                                l1=l1->next;
                                //cout<<l1<<"\t"<<l2<<endl;
                            }else{
                                int next=(l2->val+l1->val+carry)%10;
                                carry=(l2->val+l1->val+carry)/10;
                                l2->val=next;
                                val->next=l2;
                                l2=l2->next;
                                l1=l1->next;
                                val=val->next;
                            }
                        }
                    }
                }
                if(carry){
                    ListNode*last=retval;
                    while(last->next){
                        last=last->next;
                    }
                    ListNode*largest=new ListNode(carry);
                    last->next=largest;
                }
                return retval;
            }
        }
    
    }
};

int main(int argc,char** argv){
    Solution s;
    /*ListNode*t1=new ListNode(5);
    ListNode*t2=new ListNode(5);*/
    ListNode*t1=new ListNode(1);
    t1->next=new ListNode(8);
    ListNode*t2=new ListNode(0);
    ListNode*output=s.addTwoNumbers(t1, t2);
    while(output){
        cout<<output->val<<"->";
        output=output->next; 
    }
    cout<<endl;

}
