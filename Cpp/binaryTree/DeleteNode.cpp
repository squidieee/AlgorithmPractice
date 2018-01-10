/**
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode* n = root;
        TreeNode* pre = &dummy;
        // search for the key
        while(n!=NULL){
            if(key==n->val) break;
            pre = n;
            n = key > n->val ? n->right:n->left; 
        }
        if (n==NULL) return dummy.left;
        // key found
        bool isLeft = (pre->left == n);
        if(n->right==NULL) {
            if(isLeft) pre->left = n->left;
            else pre->right =n->left;
            return dummy.left;
        }
        if(n->left==NULL) {
            if(isLeft) pre->left = n->right;
            else pre->right =n->right;
            return dummy.left;
        }
        // find the leftmost node of the right subtree (or rightmost node of the left subtree)
        TreeNode* sub = n->right;
        TreeNode* subpre = n;
        while(sub->left!=NULL){
            subpre = sub;
            sub = sub->left;
        }
        if(subpre!=n) subpre->left = sub->right;
        sub->left = (n->left==sub)? NULL: n->left;
        sub->right = (n->right==sub)? sub->right: n->right;
        if(isLeft) pre->left = sub;
        else pre->right =sub;
        return dummy.left;
    }
};