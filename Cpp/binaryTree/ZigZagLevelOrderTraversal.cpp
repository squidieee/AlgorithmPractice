/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vals;
        if(root==NULL) return vals;
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool l2r(true);
        while(!nodes.empty()){
            int len = nodes.size();
            vector<int> oneLevelVals(len);
            for(int i = 0; i < len; i++){
                TreeNode* n = nodes.front();
                nodes.pop();
                int idx = l2r? i:len-i-1;
                oneLevelVals[idx] = n->val;
                if(n->left!=NULL)
                    nodes.push(n->left);
                if(n->right!=NULL)
                    nodes.push(n->right);
            }
            vals.push_back(oneLevelVals);
            l2r = !l2r;
        }
        return vals;
    }

};