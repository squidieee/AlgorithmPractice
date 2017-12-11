/* 
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        if (head ==NULL ||head->next == NULL)
            return head;
        ListNode* node = &dummy;
        while(node!=NULL && node->next!=NULL && node->next->next !=NULL)
        {
            ListNode* node1 = node->next;
            ListNode* nextStart = node->next->next->next;
            
            node->next = node->next->next;
            node->next->next = node1;
            node1->next = nextStart;
            node = node->next->next;
        }
        return dummy.next;
    }
};