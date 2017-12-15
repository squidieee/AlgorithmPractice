/* 
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

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
public: // Time O(Nlogk) Space O(1)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0)
            return NULL;
        if (len == 1)
            return lists[0];
        int Np = len;
        while(Np > 1) // loop through each level
        {
            int L= Np;
            Np = (Np+1)/2;
            for(int i=0; i < Np; i++) // loop through each pair
            {
                if (2*i+1 < L)
                    lists[i] = mergeTwoList(lists[2*i], lists[2*i+1]);
                else
                    lists[i] = mergeTwoList(lists[2*i], NULL);
            }
        }
        return lists[0];
        
    }
    ListNode* mergeTwoList(ListNode* head1, ListNode* head2)
    {
        if (head1==NULL)
            return head2;
        if (head2==NULL)
            return head1;
        ListNode dummy(0);
        ListNode* node = &dummy;
        ListNode* n1 = head1;
        ListNode* n2 = head2;
        while(n1!=NULL&&n2!=NULL)
        {
            if (n1->val < n2->val)
            {
                node->next = n1;
                n1 = n1->next;
            }
            else
            {
                node->next = n2;
                n2 = n2->next;
            }
            node = node->next;
        }
        
        if(n1!=NULL)
        {
            node->next = n1;
        }
        else if (n2!=NULL)
        {
            node->next = n2;
        }
        return dummy.next;
    }
};