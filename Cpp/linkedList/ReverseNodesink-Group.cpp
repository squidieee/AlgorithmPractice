/* 
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head==NULL||head->next==NULL||k==1)
            return head;
        int len = getLength(head);
        int nGroup = len / k;
        
        ListNode* prev = NULL;
        ListNode* node = head;
        for(int i = 0; i < nGroup; i++)
        {
            int cnt(0);
            ListNode* end = node;
            ListNode* start = prev;
            while(cnt < k)
            {
                ListNode* nodeN = node->next;
                node->next = prev;
                prev = node;
                node = nodeN;
                cnt++;
            }
            if (i==0)
                head = prev;
            if (start!=NULL)
                start->next = prev;         
            prev = end;
        }
        if (prev!=NULL)
            prev->next = node;
        return head;
    }
    int getLength(ListNode* head){
        int len(0);
        while(head!=NULL)
        {
            head = head->next;
            len++;
        }
        return len;
    }   
    
};