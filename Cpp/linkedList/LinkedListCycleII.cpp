/*Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        // hashmap: time O(n), space O(n)
        /*
        unordered_map<ListNode*,int> map;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* node = &dummy;
        while(node!=NULL)
        {
            if (map.find(node->next)==map.end())
            {
                map[node->next] = 1;
            }
            else
            {
                return node->next;
            }
            node = node->next;
        }
        return NULL;
        */
        // two pointer
        if (head == NULL|| head->next ==NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next !=NULL && fast->next->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow ==fast)
            {
                ListNode* node = head;
                while(node!=slow)
                {
                    node=node->next;
                    slow=slow->next;
                }
                return node;
            }
        }
        return NULL;
    }
};