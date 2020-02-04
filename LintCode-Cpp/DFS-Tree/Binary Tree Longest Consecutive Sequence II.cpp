/*
614. Binary Tree Longest Consecutive Sequence II
中文English
Given a binary tree, find the length(number of nodes) of the longest consecutive sequence(Monotonic and adjacent node values differ by 1) path.
The path could be start and end at any node in the tree

Example
Example 1:

Input:
{1,2,0,3}
Output:
4
Explanation:
    1
   / \
  2   0
 /
3
0-1-2-3
Example 2:

Input:
{3,2,2}
Output:
2
Explanation:
    3
   / \
  2   2
2-3
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

 struct TreeInfo{
    int maxLen;
    int maxLenUp;
    int maxLenDown;
    TreeInfo(int len, int up, int down) { maxLen = len; maxLenUp = up; maxLenDown = down; }
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive2(TreeNode * root) {
        TreeInfo* res = longestConsecutiveHelper(root);
        return res->maxLen;
    }
    
    TreeInfo* longestConsecutiveHelper(TreeNode* root)
    {
        if (root == NULL) return new TreeInfo(0, 0, 0);
        
        TreeInfo* leftTree = longestConsecutiveHelper(root->left);
        TreeInfo* rightTree = longestConsecutiveHelper(root->right);
        
        TreeInfo* rootTree = new TreeInfo(1, 1, 1);
        rootTree->maxLen = max(max(leftTree->maxLen, rightTree->maxLen), 
                               rootTree->maxLen);
        
        if(root->left != NULL)
        {
            if (root->val == root->left->val + 1)
            {
                rootTree->maxLenUp = max(rootTree->maxLenUp, leftTree->maxLenUp + 1);
            }
            else if(root->val == root->left->val - 1)
            {
                rootTree->maxLenDown = max(rootTree->maxLenDown, leftTree->maxLenDown + 1);
            }
        }
        
        if(root->right != NULL)
        {
            if (root->val == root->right->val + 1)
            {
                rootTree->maxLenUp = max(rootTree->maxLenUp, rightTree->maxLenUp + 1);
            }
            else if(root->val == root->right->val - 1)
            {
                rootTree->maxLenDown = max(rootTree->maxLenDown, rightTree->maxLenDown + 1);
            }
        }    
        
        if(root->left != NULL && root->right != NULL)
        {
            if(root->val == root->left->val + 1 && root->val == root->right->val - 1)
            {
                rootTree->maxLen = max(rootTree->maxLen, 
                                      leftTree->maxLenUp + rightTree->maxLenDown + 1);
            }
            else if(root->val == root->right->val + 1 && root->val == root->left->val - 1)
            {
                rootTree->maxLen = max(rootTree->maxLen, 
                                      leftTree->maxLenDown + rightTree->maxLenUp + 1);
            }
        }
        
        rootTree->maxLen = max(max(rootTree->maxLenUp, rootTree->maxLenDown), rootTree->maxLen);
        
        return rootTree;
    }
};

// divide and conquer