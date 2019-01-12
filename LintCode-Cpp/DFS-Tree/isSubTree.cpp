/*
1165. Subtree of Another Tree
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example
Example 1:

Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
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
     * @param s: the s' root
     * @param t: the t' root
     * @return: whether tree t has exactly the same structure and node values with a subtree of s
     */
    bool isSubtree(TreeNode * s, TreeNode * t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        
        if (isSameTree(s, t)) return true;
        bool isLeft = isSubtree(s->left, t);
        bool isRight = isSubtree(s->right, t);
        
        return isLeft || isRight;
    }
    
    bool isSameTree(TreeNode *root1, TreeNode* root2)
    {
        if (root1 == NULL && root2 == NULL) return true;
        if (root1 == NULL || root2 == NULL) return false;
        
        if (root1->val != root2->val) return false;
        
        bool isLeftSame = isSameTree(root1->left, root2->left);
        bool isRightSame = isSameTree(root1->right, root2->right);
        
        return isLeftSame && isRightSame;
    }
    
};

/// dfs to traverse each node in the tree
/// given a node in s
// if val == troot.val
// then we iterate through t's structure to find out whether there are corresponding node in s
/// Note there may be repeated computation when traversing the s tree if current node does not apply
/// it may be possible to use an approach similar to KMP to minimize computation
// this requires pre-processing t's structure with prefix to determine where to move