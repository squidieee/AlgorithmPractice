/* 
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 class Solution {
public:
    // depth first search, recursive, top-down
    /*
    bool isValidBST(TreeNode* root) {
        return isBSTHelper(root, NULL, NULL);
    }
    
    bool isBSTHelper(TreeNode* root, TreeNode* min, TreeNode* max){
        if (root==NULL)
            return true;
        if ((min!=NULL && root->val <= min->val) || (max!=NULL&&root->val >= max->val)) return false;
            
        return isBSTHelper(root->left, min, root) && isBSTHelper(root->right, root, max);
    }
    
    // depth first search, recursive, in order traversal
    bool isValidBST(TreeNode* root){
        TreeNode* prev = NULL;
        return inOrderTraversal(root, prev);
    }
    bool inOrderTraversal(TreeNode* root, TreeNode* &prev){
        if (root==NULL)  return true; //Check if the current node is empty / null.
        if(!inOrderTraversal(root->left, prev)) return false; // Traverse the left subtree by recursively calling the in-order function.
        if(prev!=NULL && root->val <= prev->val) return false; //Display the data part of the root (or current node).
        prev = root;        
        return inOrderTraversal(root->right, prev); //Traverse the right subtree by recursively calling the in-order function.
    }
    */
    
    // depth first search, iterative
    bool isValidBST(TreeNode* root){
        if (root==NULL)
            return true;
        stack<TreeNode*> nodes;
        TreeNode* prev = NULL;
        TreeNode* node = root;
        while(!nodes.empty() || node!=NULL){
            while (node!=NULL) // traversal to the left
            {
                nodes.push(node);
                node = node->left;
            }
            node = nodes.top(); 
            nodes.pop();
            if (prev!=NULL && node->val <= prev->val) return false; // display current
            prev = node;
            node = node->right; // traversal to the right
        }
        return true;
    }
    
};