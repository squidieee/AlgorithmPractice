/* 
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

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
    RandomListNode *copyRandomList(RandomListNode *head) {
        /*
        // Time O(n), Space O(n), HashMap, one-pass also possible
        if(head==NULL)
            return NULL;
        // create a copy
        RandomListNode* node = head;
        RandomListNode* copyHead = new RandomListNode(node->label);
        RandomListNode* copyNode = copyHead;
        // create a hash map
        unordered_map<RandomListNode*, RandomListNode*> map;
        map[node] = copyNode;
        while(node->next!=NULL)
        {
            node = node->next;
            copyNode->next = new RandomListNode(node->label);            
            copyNode = copyNode->next;
            map[node]=copyNode;
        }
        
        //assign random pointer
        node = head;
        copyNode = copyHead;
        while(node!=NULL)
        {
            if(map.find(node->random)!=map.end())
            {
                copyNode->random=map[node->random];
            }
            else
                copyNode->random=NULL;
            node = node->next;
            copyNode = copyNode->next;
        }
        return copyHead;
        */
        // Time O(n), Space O(1), 1->1'->2->2'->3->3'...
        if(head==NULL)
            return NULL;
        RandomListNode* node = head;
        RandomListNode* copyNode;
        while (node!=NULL)
        {
            copyNode = new RandomListNode(node->label);
            copyNode->next = node->next;
            node->next = copyNode;
            node = copyNode->next;
        }
        //copy random
        node = head;
        while (node!=NULL)
        {
            if(node->random!=NULL)
            {
                node->next->random = node->random->next;
            }
            else
                node->next->random = NULL;
            node = node->next->next;
        }
        // split the list
        RandomListNode dummy(0);
        copyNode = &dummy;
        node = head;
        while(node!=NULL)
        {
            copyNode->next = node->next;
            node->next = node->next->next;
            node = node->next;
            copyNode = copyNode->next;
        }
        return dummy.next;
    }
};