/* 

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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

    /*// iteratively
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL)
            return head;
        if (head->next==NULL)
            return head;        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* node = &dummy;
        while(node->next!=NULL && node->next->next!=NULL)
        {
            if(node->next->val == node->next->next->val)
            {
                int dup = node->next->val; // record the duplicate number
                while(node->next!=NULL && node->next->val==dup) // remove all nodes with the same number 
                    node->next = node->next->next; 
            }
            else
            {
                node = node->next;
            }
        }  
    return dummy.next;
    }
*/
    // recursively
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        if (head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else
        {
            int val = head->val;
            while(head!=NULL && head->val == val) head = head->next; // move the cursor to distinct node
            return deleteDuplicates(head);
        }

    } 
};