/* 
Reverse a singly linked list.


Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

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
    // iteratively
    /*
    ListNode* reverseList(ListNode* head) {
        ListNode* l =head;
        ListNode* prev = NULL;
        while(l!=NULL)
        {
            ListNode* l_n = l->next;
            l->next = prev;
            prev = l;
            l = l_n;
        }
        return prev;
    }
    */
    // recursively
    ListNode* reverseList(ListNode* head) {
        if (head==NULL)
            return head;
        if (head->next == NULL)
            return head;
        ListNode* p = reverseList(head->next); // assuming the rest has been reversed
        head->next->next = head; // recursive formula
        head->next = NULL; // the very beginning case
        return p;        
    }
};