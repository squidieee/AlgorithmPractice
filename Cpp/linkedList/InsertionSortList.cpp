/* 
Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* node = head;
        while(node!=NULL)
        {
            ListNode* sNode = &dummy;
            ListNode* nextNode = node->next;
            while (sNode!=NULL)
            {
                if (sNode->next == NULL || node->val < sNode->next->val )
                {
                    ListNode* temp =  sNode->next;
                    sNode->next = node;                  
                    node->next = temp;                   
                    break;
                }
                sNode = sNode->next;
            }
            node = nextNode;
        }
        return dummy.next;
    }
};