/* 
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
    // sol1: reverse the list, then do the adding just as "Add Two Numbers I"
/*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* head = new ListNode(0);
        ListNode* l = head;
        int carry(0);
        while(l1!=NULL || l2!=NULL)
        {
            int num1 = l1 == NULL?0:l1->val;
            int num2 = l2 == NULL?0:l2->val;
            int sum = num1 + num2 + carry;
            l->next = new ListNode(sum%10);
            carry = sum >=10 ? 1:0;
            l1 = l1==NULL?NULL:l1->next;
            l2 = l2==NULL?NULL:l2->next;
            l = l->next;
        }
        if (carry>0)
            l->next = new ListNode(1);
        l = head->next;
        delete(head);
        return reverse(l);
    }
    ListNode* reverse (ListNode* l)
    {
        ListNode* prev = NULL;
        ListNode* temp;
        while (l!=NULL)
        {
            temp = l->next;
            l->next = prev;
            prev = l;
            l = temp;
        }
        return prev;
    }
    */
    //sol2: recursion http://www.cnblogs.com/grandyang/p/6216480.html
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    }
    
    ListNode* sumList(ListNode* l1, ListNode* l2, int& carry){
        int num1 = l1 == NULL?0:l1->val;
        int num2 = l2 == NULL?0:l2->val;
        
        int sum = num1 + num2;
        ListNode* thisNode = new ListNode(sum%10);
        
        ListNode* n1 = l1 == NULL?NULL:l1->next;
        ListNode* n2 = l2 == NULL?NULL:l2->next;


        thisNode->next = sumList(n1, n2, carry);

        carry = sum >=10?1:0;
        
        return thisNode;
    } 
    
    int getLength(ListNode* l)
    {
        int length(0);
        while(l!=NULL){ 
            length++;
            l = l->next;
        }
        return length;
    }
};