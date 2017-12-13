/* 
Sort a linked list in O(n log n) time using constant space complexity.


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
    ListNode* sortList(ListNode* head) {
        // mergeSort O(nlogn)
        if (head==NULL||head->next==NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next!=NULL && fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* p2 = slow->next;
        slow->next = NULL;
        return mergeSort(sortList(head), sortList(p2)); // sort the partitioned array, then merge them
    }
    
    ListNode* mergeSort(ListNode* p1, ListNode* p2)
    {
        if (p1==NULL)
            return p2;
        if (p2==NULL)
            return p1;
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(p1!=NULL&&p2!=NULL)
        {
            if (p1->val > p2->val)
            {
                node->next = p2;
                p2 = p2->next;
            }
            else
            {
                node->next = p1;
                p1 = p1->next;
            }
            node = node->next;
        }
        if (p1!=NULL)
            node->next = p1;
        else if (p2!=NULL)
            node->next = p2;
        return dummy.next;
    }
};