/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

 class Solution {
public:
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
    // DFS, recursive
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelVals;
        int height(0);
        levelOrderHelper(root, levelVals, height);
        return vector<vector<int>>(levelVals.rbegin(), levelVals.rend());
     }
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& vals, int height){
        if(root==NULL)
            return;
        if(height >= vals.size())
        {
            vals.push_back(vector<int>());
        }
        vals[height].push_back(root->val); // display current val
        height++;
        levelOrderHelper(root->left, vals, height); // traversal to left
        levelOrderHelper(root->right, vals, height);// traversal to right
    }    
};