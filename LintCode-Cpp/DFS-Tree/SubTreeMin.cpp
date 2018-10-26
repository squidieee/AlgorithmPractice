/*

Home
Algorithms
AI
VIP
Language
avatarweipuz
Back
596. Minimum Subtree
Description
Given a binary tree, find the subtree with minimum sum. Return the root of the subtree.

LintCode will print the subtree which root is your return node.
It's guaranteed that there is only one subtree with minimum sum and the given binary tree is not an empty tree.

Have you met this question in a real interview?  
Example
Given a binary tree:

     1
   /   \
 -5     2
 / \   /  \
0   2 -4  -5 
return the node 1.

Related Problems
DifficultyEasy
Total Accepted11693
Total Submitted31526
Accepted Rate37%
 Show Tags
 Company
Leaderboard - Java

gloria666
167ms

annig
167ms

BooleanWu
167ms

miaaa33
167ms

However
167ms
Note
既然是全局最小。。就弄个全局变量嘛。。。
Crystaleee
Created at 19 days ago
时间复杂度O（n），再定义一个函数用于计算左子树，右子树
yuhaiyuwaseda
Created at a month ago
9/16: 看答案做出来的 2天后重做
yang651
Created at a month ago
Discuss
No topic

  
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