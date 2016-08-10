/*369. Plus One Linked List  QuestionEditorial Solution  My Submissions
Total Accepted: 1114
Total Submissions: 2238
Difficulty: Medium
Given a non-negative number represented as a singly linked list of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Example:
Input:
1->2->3

Output:
1->2->4*/

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
    ListNode* plusOne(ListNode* head) {
        ListNode * cur = head; 
        ListNode * right = NULL; 
        while (cur){
            if(cur->val!=9){
                right = cur ; 
            }
            cur = cur -> next ; 
        }
        if(!right){
            ListNode * newHead = new ListNode(0);
            right = newHead ; 
            newHead->next = head ; 
            head = newHead ; 
        }
        right->val++;
        cur = right -> next; 
        while (cur){
            cur -> val = 0 ; 
            cur = cur->next ;
        }
        return head; 
    }
};

