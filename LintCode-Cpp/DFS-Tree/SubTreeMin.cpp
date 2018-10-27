/*
596. Minimum Subtree
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 
return the node 1.

Notice
LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.
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
    /**
     * @param root: the root of binary tree
     * @return: the root of the minimum subtree
     */
    
    /* subtree1: traversal version - Find sum of each subtree and compare them with min, requires Global Variable */
    
    TreeNode * findSubtree(TreeNode * root) {
        TreeNode* result = NULL;
        int minval = INT_MAX;
        traversalSums(root, &result, minval);
        
        return result;
    }
    
    int traversalSums(TreeNode* node, TreeNode** pminNode, int& minSum)
    {
        if (node == NULL) return 0;
        
        int s =  traversalSums(node->left, pminNode, minSum) + traversalSums(node->right, pminNode, minSum) + node->val;
        
        if (s <= minSum)
        {
            *pminNode = node;
            minSum = s;
        }
        return s;
    }
    
    /* subtree2: divide and conquer - Compare leftmin, rightmin, and root sum, requires Requrn Type */
    struct ReturnType
    {
        public:
        TreeNode* minNode;
        int minVal;
        int sum;
        
        ReturnType(TreeNode* minNode, int minVal, int sum)
        {
            this->minNode = minNode;
            this->minVal = minVal;
            this->sum = sum;
        }
    };
    
    TreeNode * findSubtree(TreeNode * root) {
    
        ReturnType result = divideConquerSum(root);
        return result.minNode;
    }
    
    ReturnType divideConquerSum(TreeNode * root)
    {
        if (root == NULL) return ReturnType(NULL, INT_MAX, 0);
        
        ReturnType leftResult = divideConquerSum(root->left);
        ReturnType rightResult = divideConquerSum(root->right);
        
        int sum = root->val + rightResult.sum + leftResult.sum;
        if (leftResult.minVal > rightResult.minVal)
        {
            if (sum > rightResult.minVal)
                return ReturnType( rightResult.minNode, rightResult.minVal, sum);
        }
        else
        {
            if (sum > leftResult.minVal)
                return ReturnType( leftResult.minNode, leftResult.minVal, sum);            
        }
        
        return ReturnType( root, sum, sum);

    }

};