/* 
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // Not completely one-pass: nodes from m to n have executed twice
/*
        if (head==NULL)
            return head;
        if (head->next ==NULL || m==n)
            return head;
        /// partition
        ListNode* l = head;
        ListNode* l1;
        ListNode* l2;
        ListNode* l1p = NULL;
        int i = 1;
        while(i <= n)
        {
            if (i == m - 1)
                l1p = l;
            if (i == m)
                l1 = l;
            if (i == n)
                l2 = l;
            l = l->next;
            i++;
        }
        ListNode* l2n = l2->next;
        l2->next = NULL;
        /// reverse
        l = l1;
        ListNode* prev = NULL;
        while(l!=NULL)
        {
            ListNode* l_n = l->next;
            l->next = prev;
            prev = l;
            l = l_n;
        }
        /// reconnect
        if (l1p!=NULL)
            l1p->next = l2;
        l1->next = l2n;
        
        return m>1? head:l2;
*/
        /// completely one-pass: 1-m parition; m-n reverse; finally connect. Use a dummy head to solve the NULL problem
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode* d_head = &dummy;
        
        for(int i = 1; i < m; i++) /// partition
        {
            d_head = d_head->next;
        }
        ListNode* rl = d_head->next;
        ListNode* prev = d_head;
        for(int i = m; i <=n; i++)  /// reverse
        {
            ListNode* rl_n = rl->next;
            rl->next = prev;
            prev = rl;
            rl = rl_n;
        }
         ///reconnect
        d_head->next->next = rl;
        d_head->next = prev;             

        return dummy.next;        
    }
};