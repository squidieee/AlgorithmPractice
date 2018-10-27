/*
453. Flatten Binary Tree to Linked List
Flatten a binary tree to a fake "linked list" in pre-order traversal.

Here we use the right pointer in TreeNode as the next pointer in ListNode.

Example
              1
               \
     1          2
    / \          \
   2   5    =>    3
  / \   \          \
 3   4   6          4
                     \
                      5
                       \
                        6
Challenge
Do it in-place without any extra memory.

Notice
Don't forget to mark the left child of each node to null. Or you will get Time Limit Exceeded or Memory Limit Exceeded.
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode * root) {
        //if (root==NULL) return;
        //traversal(root);
        
        divideConquer(root);
    }
    
    void traversal(TreeNode *root)
    {
        if (root == NULL) return;
        
        lastNode = root; // lastNode is the last non-NULL node!
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        traversal(root->right);
        lastNode->right = temp;
        traversal(temp);
    }
    
    TreeNode* divideConquer(TreeNode *root)
    {
        if (root==NULL) return NULL; //????
        
        // divide
        TreeNode* lLastNode = divideConquer(root->left);
        TreeNode* rLastNode = divideConquer(root->right);
        
        // reconnect
        if (lLastNode != NULL)
        {
            lLastNode->right = root->right;
            root->right = root->left;
            root->left = NULL;               
        }
        
        if (rLastNode != NULL) return rLastNode;
        if (lLastNode != NULL) return lLastNode;
        return root;
    
    }
    
private:
    TreeNode* lastNode;
};