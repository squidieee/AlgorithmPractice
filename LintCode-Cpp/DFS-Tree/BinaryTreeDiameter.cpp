/*
1181. Diameter of Binary Tree
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
Notice
The length of path between two nodes is represented by the number of edges between them.
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

 struct ReturnVal
 {
     int diameter;
     int height;
     ReturnVal(int d, int h)
     {
         diameter = d;
         height = h;    
     }
 };
 
 class Solution {
 public:
     /**
      * @param root: a root of binary tree
      * @return: return a integer
      */
     int diameterOfBinaryTree(TreeNode * root) {
         ReturnVal result = dfs(root);
         return result.diameter;
     }
     
     ReturnVal dfs(TreeNode* node)
     {
         if (node == NULL) return ReturnVal(0, -1);
         if (node->left == NULL && node->right == NULL)  return ReturnVal(0, 0);
         
         ReturnVal leftVal = dfs(node->left);
         ReturnVal rightVal = dfs(node->right);
         
         int height = max(leftVal.height, rightVal.height) + 1;
         int diameter = leftVal.height + rightVal.height + 2;
         
         diameter = max( max( leftVal.diameter, rightVal.diameter), diameter); 
         
         return ReturnVal(diameter, height);
     }
 };
 
 // it has to be a leaf or root itself; otherwise always larger diameter
 // given a certain node
 // it has two choices: the path goes through it, or not
 // our goal is to get the max of them
 // if not go through it, there will be two answers from left and right sub trees
 // if go through it, the answer will be l_height + r_height: we need to record height