/* 
102. Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Example
	Example 1:
		Input: 21->10->4->5,  then tail connects to node index 1(value 10).
		Output: true
		
	Example 2:
		Input: 21->10->4->5->null
		Output: false
	
	```
Challenge
Follow up:
Can you solve it without using extra space?


*/

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    
    bool hasCycle(ListNode * head) {
        /* Sol2 */
        ListNode* slow = head;
        ListNode* fast = head;
        
        // needs to have exit in while otherwise inf loop
        while(fast != NULL && fast->next != NULL) 
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        
        return false;
        
        /* Sol1
        unordered_map<ListNode*, ListNode*> map;
        ListNode* node = head;
        while(node != NULL) // needs to have exit in while otherwise inf loop
        {
            if (map.find(node)!=map.end()) return true;
            map.insert({node, node->next});
            node = node->next;
        }
        
        
        return false;
        */
    }
};

//Sol1: Hashmap
// Time O(n) Space O(n)

//Sol2: two pointers
// Time O(n)