/*
1307. Verify Preorder Sequence in Binary Search Tree

Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.

Follow up:
Could you do it using only constant space complexity?

Example
Example1

Input: preorder = [1,3,2]
Output: true
Example2

Input: preorder = [1,2]
Output: true
*/


class Solution {
public:
    /**
     * @param preorder: List[int]
     * @return: return a boolean
     */
    bool verifyPreorder(vector<int> &preorder) {
        if (preorder.size() < 2) return true;
        
        stack<int> stk;
        int root = INT_MIN;
        stk.push(preorder[0]);
        
        for(int i = 1; i < preorder.size(); i++)
        {
            if (preorder[i] < stk.top()) // left child of stack top
            {
                stk.push(preorder[i]);
            }
            else // right child of a node X hidden in the stack
            {
                // find the first val > current node = X's parent
                // node X is the last node popped out
                // use root to record its value as a lowerbound to the current node
                while(!stk.empty())
                {
                    if (stk.top() > preorder[i])  break; // find grandparent
                    root = stk.top(); // update parent
                    stk.pop();
                }
                 
                stk.push(preorder[i]);
            }
            
            if (preorder[i] < root) return false; // this node should be right child of root
        }
        
        return true;
    }
};

// Stack recovers preorder to inorder
// the pop sequence of stack will be inorder sequence