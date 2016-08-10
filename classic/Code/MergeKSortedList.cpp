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
    ListNode *merge2Lists(ListNode*p1,ListNode*p2){
        ListNode*fake=new ListNode(INT_MIN);
        ListNode* p=fake;
        while(p1&&p2){
            if(p1->val>p2->val){
                p->next=p2;
                p2=p2->next;
            }else{
                p->next=p1;
                p1=p1->next;
            }
            p=p->next;
        }
        if(p1){
            p->next=p1;
        }
        if(p2){
            p->next=p2;
        }
        p=fake->next;
        delete fake;
        return p;
    }
    ListNode *merge(vector<ListNode *> &lists,int start,int end) {
        if(end==start+1){return lists[start];}
        int mid=(start+end)/2;
        ListNode*p1=merge(lists,start,mid);
        ListNode*p2=merge(lists,mid,end);
        return merge2Lists(p1,p2);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0){return NULL;}
        return merge(lists,0,lists.size());
    }
    ListNode *mergeKListsheap(vector<ListNode *> &lists) {
        if(lists.size()==0){return NULL;}
        ListNode*fake=new ListNode(INT_MIN);
        ListNode*cur=fake;
        bool used=false;
        
        while (!used){
            int index=-1;
            int M=INT_MAX;
            for(int i=0;i<lists.size();i++){
                if(lists[i]&&M>lists[i]->val){
                    M=lists[i]->val;
                    index=i;
                }
            }
            if(index==-1){
                used=true;
            }else{
                cur->next=lists[index];
                cur=cur->next;  
                lists[index]=lists[index]->next;
            }
        }
        return fake->next;
    }
};
