/* 
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
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
    // DFS, iterative Space O(n)
    /*
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(root==NULL)
            return vals;
        stack<TreeNode*> nodes;
        TreeNode* node = root;
        while(!nodes.empty() || node!=NULL){
            // traversal to left nodes
            while(node!=NULL)
            {
                nodes.push(node);
                node = node->left;
            }
            // get current node val
            node = nodes.top();
            nodes.pop();
            vals.push_back(node->val);
            // traversal to right child, if any
            node = node->right;
        }
        return vals;
    }
    
    // DFS, recursive Space O(n)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorderHelper(root, vals);
        return vals;
    }
    void inorderHelper(TreeNode* root, vector<int>& vals){
        if (root==NULL)
            return;
        inorderHelper(root->left, vals);
        vals.push_back(root->val);
        inorderHelper(root->right, vals);
    }
    */
    // Morris Traversal:  Space O(1); It uses the child storage (normally NULL) on the leaves; Threaded Binary Tree
     vector<int> inorderTraversal(TreeNode* root) {
         vector<int> vals;
         TreeNode* node = root;
         while(node!=NULL){
             if(node->left==NULL){ 
                 vals.push_back(node->val);
                 node = node->right;
             }
             else
             {
                 // make current node as the right child of rightmost node in the left substree
                 TreeNode* predecessor = node->left;
                 while(predecessor->right!=NULL && predecessor->right!=node){ // second condition: node has been traversed
                     predecessor = predecessor->right;
                 }
                 
                 if(predecessor->right==NULL) // rightmost node
                 {
                     predecessor->right = node;
                     node = node->left;
                 } 
                 else // predecessor node: just restore the predecessor and print this + move to the right node
                 {
                     predecessor->right = NULL;
                     vals.push_back(node->val);
                     node = node->right;
                 }
             }
         }
         return vals;
     }
    
};