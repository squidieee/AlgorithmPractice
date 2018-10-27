/*
480. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.

Example
Given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
]
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
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode * root) {
        vector<string> paths;
        if (root==NULL) return paths;
        traversal(root, to_string(root->val), paths);
        return paths;
        
        //return divideConquer(root);
    }
    
    
    // Top-Down: carry pathToAdd and paths all the way until meeting leaf
    void traversal(TreeNode* root, string pathToAdd, vector<string>& paths)
    {
         if (root == NULL) return;
         
         if (root->left == NULL && root->right == NULL)
             paths.push_back(pathToAdd);
         
         if (root->left !=NULL)
             traversal(root->left, pathToAdd + "->" + to_string(root->left->val), paths);
         if (root->right !=NULL)
             traversal(root->right, pathToAdd + "->" + to_string(root->right->val), paths);
             
         return;
    }
    
    //Bottom-Up: merge result from left sub and right sub
    vector<string> divideConquer(TreeNode* root)
    {
        vector<string> paths;
        if (root==NULL) return paths;
        
        // divide
        vector<string> lpaths = divideConquer(root->left);
        vector<string> rpaths = divideConquer(root->right);
        
        // merge
        if (lpaths.empty() && rpaths.empty()) // this is a leaf
            paths.push_back(to_string(root->val));
        
        for(auto p: lpaths)
        {
            string s = to_string(root->val) + "->" + p;
            paths.push_back(s);
        }
        
        for(auto p: rpaths)
        {
            string s = to_string(root->val) + "->" + p;
            paths.push_back(s);
        }
        
        return paths;
    }

};