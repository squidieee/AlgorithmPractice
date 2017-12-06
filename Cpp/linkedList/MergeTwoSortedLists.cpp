/* 
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /* 
        // Time O(m+n), Space O(m+n)
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;                
    
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
        */
        
        // Time O(m+n), Space O(1)
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;    
        
        ListNode* head = l1->val < l2->val?l1:l2;
        ListNode* prev = new ListNode(-1); // combine two into one new
        
        while(l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;         
        }
        // one of them did not reach the end
        if (l1 != NULL)
            prev->next = l1;
        else if (l2 != NULL) 
            prev->next = l2;
        return head;
    }
    
};