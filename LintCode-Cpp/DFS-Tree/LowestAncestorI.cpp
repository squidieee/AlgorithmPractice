/*
578. Lowest Common Ancestor III
Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Return null if LCA does not exist.

Example
For the following binary tree:

  4
 / \
3   7
   / \
  5   6
LCA(3, 5) = 4

LCA(5, 6) = 7

LCA(6, 7) = 7

Notice
node A or node B may not exist in tree.
*/

/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */


 class Solution {
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
     public:
    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        if (A==NULL) return B;
        if (B==NULL) return A;
        
        TreeNode* ancestor; // be careful on the "pointer-to-pointer"
        return helper(root, A, B, &ancestor)==2? ancestor:NULL;
    }
    
    // determine whether this node contains Node A and B from its left and right sub trees
    int helper(TreeNode* root, TreeNode * A, TreeNode * B, TreeNode** result)
    {
        if (root == NULL)  return 0;
        
        int resultL = helper(root->left, A, B, result);
        int resultR = helper(root->right, A, B, result);
        
        if (resultL == 2|| resultR ==2) return 2;
        
        if (resultL == 1 && resultR == 1)
        {
            // this node is a lowest ancestor
            *result = root;
            return 2;
        }
        
        if ((resultL == 1 || resultR == 1) && (root == A || root == B))
        {
            // this node is a lowest ancestor
            *result = root;
            return 2;
        }
        
        if (resultL == 1 || resultR == 1 || root == A || root == B)
        {
            if (A==B)
            {
                *result = root;
                return 2;
            }
            else
                return 1;
        }
        
        return 0;
    }
};