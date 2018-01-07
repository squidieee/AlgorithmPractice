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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelVals;
        if (root==NULL) return levelVals;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int len = nodes.size();
            vector<int> vals;
            for(int i =0;i<len;i++){
                TreeNode* n = nodes.front();
                nodes.pop();
                vals.push_back(n->val);
                if (n->left!=NULL)
                    nodes.push(n->left);
                if (n->right!=NULL)
                    nodes.push(n->right);
            }
            levelVals.push_back(vals);
        }
        return levelVals;
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