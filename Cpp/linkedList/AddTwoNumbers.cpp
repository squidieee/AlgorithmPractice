/* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* l = head;
        int carry(0);
        while(l1!=NULL || l2!=NULL)
        {
            int num1 = l1==NULL? 0:l1->val;
            int num2 = l2==NULL? 0:l2->val;
            int sum = carry + num1 + num2;
            l->next = new ListNode(sum % 10);
            carry = sum >=10? 1:0;
            l1 = l1==NULL? NULL: l1->next;
            l2 = l2==NULL? NULL: l2->next;
            l = l->next;
        }
        
        if (carry)
            l->next = new ListNode(1);
        l = head->next;
        delete(head);
        return l;

    }
};