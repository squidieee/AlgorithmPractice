/* 
Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        /*
        // time O(n), space O(n), one pass
        ListNode* curr = head;
        queue<ListNode*> q;

        while(curr!=NULL)
        {
            if(q.size() > n)
                q.pop();
            q.push(curr);
            curr = curr->next;
        }
        
        if (q.size() == n )
        {
            return q.front()->next;
        }
        else
        {
            q.front()->next = q.front()->next->next;
            return head;
        }
        
        // time O(n), space O(1), two pass
        int length(0);
        ListNode* curr = head;
        while(curr!=NULL)
        {
           curr = curr->next;
            length++;
        }
        if (length == n)
            return head->next;
        
        int cnt(0);
        curr = head;
        while(curr!=NULL)
        {
            cnt++;
            if (cnt == length - n)
            {
                curr->next = curr->next->next;
                return head;
            }
            curr = curr->next;
        }
        */   
        // time O(n), space O(1), one pass
        ListNode* end = head;
        int cnt(0);
        while(cnt < n)
        {
            end = end->next;
            cnt++;
        }
        if(end == NULL)
            return head->next;
        
        ListNode* start = head;
        while(end->next!=NULL)
        {
            start = start->next;
            end = end->next;
        }
        start->next = start->next->next;
        
        return head;
    }
};