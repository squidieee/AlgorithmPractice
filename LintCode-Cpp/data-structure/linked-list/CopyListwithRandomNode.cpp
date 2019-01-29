/* 
105. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Challenge
Could you solve it with O(1) space?
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        /// Space O(1)
        
        // first pass
        RandomListNode* node = head;
        while(node != NULL)
        {
            RandomListNode* copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
            // move to next
            node = copy->next;
        }
        
        // second pass
        node = head;
        RandomListNode* copyHead = node->next;
        while(node != NULL)
        {
            // assign random
            RandomListNode* copy = node->next;
            copy->random = node->random != NULL ? node->random->next : NULL;
            // move next
            node = copy->next;
        }
        
        // third pass
        node = head;
        while(node != NULL)
        {
            RandomListNode* copy = node->next;
            // reconnect nodes
            node->next = copy->next;
            copy->next = copy->next != NULL ? copy->next->next : NULL;
            node = node->next;
        }
        
        return copyHead;
        
        /// Space O(n)
        /*
        
        
        // first pass
        unordered_map<RandomListNode*, RandomListNode*> table;
        RandomListNode* node = head;

        RandomListNode* curr, *prev;
        RandomListNode dummy(-1);
        prev = &dummy;
        
        while(node != NULL)
        {
            curr = new RandomListNode(node->label);
            table.insert({node, curr}); // assuming no cycle in node
            prev->next = curr;
            prev = curr;
            node = node->next;
        }
        
        // second pass
        curr = dummy.next;
        node = head;
        while(node != NULL)
        {
            if (table.find(node->random) != table.end())
                curr->random = table.at(node->random);
            
            curr = curr->next;
            node = node->next;
        }
        
        return dummy.next;
        */
    }
};

// create a hash table: 
// old RandomListNode* as key, new RandomListNode* as value
// 1st pass: deep copy without *random while building the table
// 2nd pass: fill in the *random
// Time O(n) Space O(n)

// Space O(1) solution:
/// 1st pass: create the copy in-place so that 1->2->3 becomes 1->1'->2->2'->3->3' 
/// 2nd pass: redirect the random pointers in the copied list based on the original list
/// 3rd pass: split two lists
