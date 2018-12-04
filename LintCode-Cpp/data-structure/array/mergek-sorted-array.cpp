/* 
104. Merge K Sorted Lists
Merge k sorted linked lists and return it as one sorted list.

Analyze and describe its complexity.

Example
Given lists:

[
  2->4->null,
  null,
  -1->null
],
return -1->2->4->null.
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *>& lists) {
        // K lists, each has N nodes
        /*
        // v1: O(NK)
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); i++)
        {
            head = mergeTwoList(head, lists[i]);
        }
        
        return head;
        */
        
        // v2: O(NlogK)
        if (lists.empty()) return nullptr;
        
        return mergeSortHelper(lists, 0, lists.size() - 1);
        
    }
    
    // merge two list: O(NK)
    // two pointer: one at n1, one at n2
    // return the merged list
    ListNode* mergeTwoList(ListNode* n1, ListNode* n2)
    {
        if (n1 == nullptr) return n2;
        if (n2 == nullptr) return n1;
        
        ListNode dummy(0);
        
        ListNode* in1 = n1;
        ListNode* in2 = n2;
        ListNode* prev = &dummy;
        
        while(in1 != nullptr || in2 != nullptr)
        {
            if ( in2 == nullptr || (in1!= nullptr && in1->val <= in2->val))
            {
                prev->next = in1;
                prev = prev->next;
                in1 = in1->next;
            }
            else
            {
                prev->next = in2;
                prev = prev->next;
                in2 = in2->next;
            }
        }
        
        return dummy.next;
    }
    
    // merge sort: O(NlogK)
    // merge each two nodes 
    // return the merged list
    ListNode* mergeSortHelper(vector<ListNode *>& lists, int lstart, int lend )
    {
        if (lstart == lend) return lists[lstart];
        if (lstart + 1 == lend) return mergeTwoList(lists[lstart], lists[lend]);
        
        int lmid = lstart + (lend - lstart) / 2;
        ListNode* firstHalf = mergeSortHelper(lists, lstart, lmid);
        ListNode* secondHalf = mergeSortHelper(lists, lmid + 1, lend);
        
        return mergeTwoList(firstHalf, secondHalf);
    }
};
