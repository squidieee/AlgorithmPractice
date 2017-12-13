/* 
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (head==NULL||head->next==NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;        
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = reverse(slow->next);
        slow = head;
        while(fast!=NULL)
        {
            if (slow->val!=fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head!=NULL)
        {
            ListNode* nn = head->next;
            head->next = prev;
            prev = head;
            head = nn;
        }
        return prev;
    }
};