/*
95. Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
A single node tree is a BST
Example
An example:

  2
 / \
1   4
   / \
  3   5
The above binary tree is serialized as {2,1,4,#,#,3,5} (in level order).
*/
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 class Solution {
public:
    struct ReturnType
    {
        int min;
        int max;
        ReturnType(int min, int max)
        {
            this->min = min;
            this->max = max;
        }
    };
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        bool isValid = true;
        ReturnType result = helper(root, &isValid);
        return isValid;
    }
    
    // compare the root val with max of left and min of right
    ReturnType helper(TreeNode* node, bool* isvalid)
    {
        if (node==NULL) return ReturnType(INT_MAX, INT_MIN); 
        
        ReturnType resultL(INT_MAX, INT_MIN);
        ReturnType resultR(INT_MAX, INT_MIN);

        if (node->left!=NULL)
        {
            resultL = helper(node->left, isvalid);
            if (resultL.max >= node->val)
            {
                *isvalid = false;
                return resultL;
            }
        }
        
        if (node->right!=NULL)
        {
            resultR = helper(node->right, isvalid);
            if (resultR.min <= node->val)
            {
                *isvalid = false;
                return resultR;
            }
        }
        
        return ReturnType(std::min(resultL.min, node->val), std::max(resultR.max, node->val));
    }
    
};