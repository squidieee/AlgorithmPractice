/* 
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
     // solution1: stack. time O(n) Space O(n)
/*       
        stack<ListNode*> nums;
        ListNode* l = head;
        int length = 0;
        while(l!=NULL)
        {
            nums.push(l);
            l = l->next;
            length++;
        }
        if (length < 3)
            return;
        
        l = head;
        int i = 0;
        while(i < length/2)
        {
            nums.top()->next = l->next;
            l->next = nums.top();
            l = nums.top()->next;
            nums.pop();
            i++;
        }
        l->next = NULL;   
*/
    // solution2: partition, reverse, merge. time O(n), space O(1)
        if (head == NULL)
            return;
        if (head->next == NULL)
            return;
        
        ListNode* p1 = NULL;
        ListNode* p2 = NULL;
        
        partition(head, p1, p2);
        
        reverse(p2);
        
        while(p1!=NULL && p2!=NULL)
        {
            ListNode* p1n = p1->next;
            ListNode* p2n = p2->next;
            
            p1->next = p2;
            p2->next = p1n;
            p1 = p1n;
            p2 = p2n;
        }
        
    }
    
    void reverse(ListNode* &head)
    {
        ListNode* l = head;
        ListNode* prev = NULL;
        while(l!=NULL)
        {
            ListNode* l_n = l->next;
            l->next = prev;
            prev = l;
            l = l_n;
        }
        head = prev;
    }
    
    void partition(ListNode* head, ListNode* &p1, ListNode* &p2)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != NULL&& fast->next->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        p2 = slow->next;
        p1 = head;
        slow->next = NULL;
    }
};