/*
72. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Example
Example 1:

Input：[],[]
Output：{}
Explanation:
The binary tree is null
Example 2:

Input：[1,2,3],[1,3,2]
Output：{2,1,3}
Explanation:
The binary tree is as follows
  2
 / \
1   3

Notice
You may assume that duplicates do not exist in the tree.
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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    
    // return the current node
    // postEnd is the parent node 
    TreeNode* dfs(vector<int> &inorder, vector<int> &postorder, 
            int inStart, int inEnd, int postStart, int postEnd)
    {
        if(inEnd < inStart || postEnd < postStart) return NULL;
        if(postStart == postEnd) return new TreeNode(postorder[postEnd]);
        
        int i1;
        for(i1 = inStart; i1 <= inEnd; i1++)
        {
            if(inorder[i1] == postorder[postEnd]) break;
        }
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        root->left = dfs(inorder, postorder, inStart, i1-1, postStart, postStart+i1-inStart-1);
        root->right = dfs(inorder, postorder, i1+1, inEnd, postStart+i1-inStart, postEnd-1);
        
        return root;
    }
};

// in-order: L-P-R
// post-order: L-R-P

// root will be the last element in post-order
// find it in inorder 
// then left sub tree will be things on the left of root, right will be things on the right 
