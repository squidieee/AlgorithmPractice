/*
67. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
 

return [1,3,2].

Challenge
Can you do it without recursion?
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
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> vals;
        stack<TreeNode*> nodes;
        
        while(root!=NULL)
        {
            nodes.push(root);
            root = root->left;
        }        
        
        while(!nodes.empty())
        {
            TreeNode* node = nodes.top();
            vals.push_back(node->val);
            nodes.pop();
            
            if (node->right != NULL)
            {
                node = node->right;
                while(node != NULL)
                {
                    nodes.push(node);
                    node = node->left;
                }
            }
        }
        
        return vals;
    }
};