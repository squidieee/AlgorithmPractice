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
    // BFS, iterative
    /*
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> vals;
        if (root==NULL) return vals;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            int len = q.size();
            vector<int> level;
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left!=NULL) q.push(node->left);
                if (node->right!=NULL) q.push(node->right);
            }
            vals.push_back(level);
        }
        return vals;
    }
    */
    //DFS, recursive, preorder
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelVals;
        int height(0);
        levelOrderHelper(root, levelVals, height);
        return levelVals;
     }
    void levelOrderHelper(TreeNode* root, vector<vector<int>>& vals, int height){
        if(root==NULL)
            return;
        if(height >= vals.size())
        {
            vector<int> newLevel;
            vals.push_back(newLevel);
        }
        vals[height].push_back(root->val); // display current val
        height++;
        levelOrderHelper(root->left, vals, height); // traversal to left
        levelOrderHelper(root->right, vals, height);// traversal to right
    }
};