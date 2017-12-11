/* 
Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        // compute length, mod k, then swap two sublists
        
        if (head == NULL|| head->next ==NULL || k < 1)
            return head;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* end = head;
        int len = 1;
        while(end->next!=NULL) // compute length
        {
            end = end->next;
            len++;
        }
        k = k % len;
        if (k==0)
            return head;
        
        ListNode* node = head;

        for(int i = 1; i < len-k; i++)
        {
            node = node->next;
        }
        
        dummy.next = node->next;
        node->next = NULL;
        end->next = head;
        return dummy.next;
    }
};