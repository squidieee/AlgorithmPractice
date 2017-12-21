/* 
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
    /* 
    // post-order depth-first search: recursive
    int maxDepth(TreeNode* root) {
        if (root ==NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    
    // breath-first search: iterative
    int maxDepth(TreeNode* root)
    {
        if (root==NULL)
            return 0;
        
        queue<TreeNode*> q; // stores all nodes on a level
        q.push(root); // level 0
        int dep(0);
        while(!q.empty()){ // for each level
            int len = q.size(); // number of nodes on this level
            for(int i = 0; i < len; i++){ // for each node on this level
                TreeNode* node = q.front(); 
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
            }
            dep++;
        }
        return dep;
    }
    */
    
    // depth-first search: iterative
    int maxDepth(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        stack<TreeNode*> s;
        stack<int> dep;
        s.push(root);
        dep.push(1);
        int maxdep(0);
        while(!s.empty())
        {
            TreeNode* node = s.top();
            s.pop(); 
            int level = dep.top(); 
            dep.pop();
            maxdep = max(maxdep, level);

            if(node->right != NULL)
            {
                s.push(node->right); 
                dep.push(level+1);
            }
            if(node->left != NULL)
            {
                s.push(node->left);
                dep.push(level+1);
            }    
        }
        return maxdep;
    }
};