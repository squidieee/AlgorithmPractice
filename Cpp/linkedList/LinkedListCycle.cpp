/*
Given a linked list, determine if it has a cycle in it.

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
    bool hasCycle(ListNode *head) {
        /*
        // hashmap: time O(n), space O(n)
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
                return true;
            }
            node = node->next;
        }
        return false;
        */
        // Two pointer: space O(1)
        if (head == NULL|| head->next ==NULL)
            return false;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = slow->next->next;

        while(fast->next !=NULL && fast->next->next !=NULL)
        {
            if (slow ==fast)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};