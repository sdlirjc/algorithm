#include "header.h"

struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)return NULL;
        RandomListNode*tmpHead=head;
        while (tmpHead){
            RandomListNode*tmp=new RandomListNode(tmpHead->label);
            RandomListNode*oldheadnext=tmpHead->next;
            cout<<"DEBUG:1"<<endl;
            tmpHead->next=tmp;
            cout<<"DEBUG:2"<<endl;
            tmp->next=oldheadnext;
            tmpHead=oldheadnext;
        }
        cout<<"DEBUG:3"<<endl;
        tmpHead=head;
        while (tmpHead){
            if(tmpHead->random){
                tmpHead->next->random=tmpHead->random->next;
            }else{
                tmpHead->next->random=NULL;
            }
            tmpHead=tmpHead->next->next;
        }
        cout<<"DEBUG:4"<<endl;
        tmpHead=head;
        RandomListNode*val=tmpHead->next;
        while(tmpHead){
            RandomListNode*newHead=tmpHead->next;
            tmpHead->next=newHead->next;
            RandomListNode*oldNext=tmpHead->next;
            if(oldNext){
                newHead->next=oldNext->next;
            }else{
                newHead->next=NULL;
            }
            tmpHead=tmpHead->next;
        }
        cout<<"DEBUG:5"<<endl;
        return val;
    }
};

int main(int argc,char**argv){
    Solution s ;
    RandomListNode*head=new RandomListNode(-1);
    s.copyRandomList(head);

}
