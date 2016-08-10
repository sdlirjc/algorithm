/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode*sort(ListNode*head,ListNode*tail){
        if(head==tail)return NULL;
        int N=0;
        ListNode*tmp=head;
        while(tmp!=tail){
            N++;
            tmp=tmp->next;
        }
        int mid=N/2;
        tmp=head;
        for (int i=0;i<mid;i++){
            tmp=tmp->next;
        }
        TreeNode*tHead=new TreeNode(tmp->val);
        tHead->left=sort(head,tmp);
        tHead->right=sort(tmp->next,tail);
        return tHead;
        
    }
    TreeNode *sortedListToBST(ListNode *head) {
        return sort(head,NULL);
    }
};
