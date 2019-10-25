/* 
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

Example
Example1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example2:

Input: 2->1->null
Output: 2->1->null
Notice
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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
     * @param head: a singly linked list
     * @return: Modified linked list
     */
    ListNode * oddEvenList(ListNode * head) {
        int nid = 1;
        
        ListNode dummyOdd(-1), dummyEven(-1);

        ListNode* curr = head;
        ListNode* oddCurr =  &dummyOdd;
        ListNode* evenCurr = &dummyEven;
        
        while(curr != NULL) 
        {
            if (nid % 2)
            {
                oddCurr->next = curr;
                oddCurr = oddCurr->next;
            }
            else
            {
                evenCurr->next = curr;
                evenCurr = evenCurr->next;
            }
            
            nid++;
            curr = curr->next;
        }
        
        oddCurr->next = dummyEven.next;
        evenCurr->next = NULL;
        
        return dummyOdd.next;
    }
};

// split into odd and even parts
// use a counter to record the number
// connect two parts