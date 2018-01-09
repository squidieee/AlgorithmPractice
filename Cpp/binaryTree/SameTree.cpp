/**
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.


Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false 

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL||q==NULL) return p==q;
        queue<TreeNode*> queP, queQ;
        queP.push(p);
        queQ.push(q);
        while(!queP.empty() && !queQ.empty()){
            int len = queP.size();
            for(int i = 0; i < len; i++){
                TreeNode* nodeP = queP.front(); queP.pop();
                TreeNode* nodeQ = queQ.front(); queQ.pop();
                if (nodeP==NULL&&nodeQ==NULL) continue;
                if (nodeP==NULL||nodeQ==NULL) return false;
                if (nodeP->val != nodeQ->val) return false;
                queP.push(nodeP->left);
                queQ.push(nodeQ->left);
                queP.push(nodeP->right);
                queQ.push(nodeQ->right);                
            }
        }
        return true;
    }
    
    // DFS, recursive, preOrder
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL||q==NULL) return p==q;
        if (p->val!=q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    } 
    */
    // DFS, preorder, recursive
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL||q==NULL) return p==q;
        stack<TreeNode*> queP, queQ;
        queP.push(p);
        queQ.push(q);      
         while(!queP.empty() && ! queQ.empty()){
            TreeNode* nodeP = queP.top(); queP.pop();
            TreeNode* nodeQ = queQ.top(); queQ.pop();      
            if(nodeP==NULL&&nodeQ==NULL) continue;
            if (nodeP==NULL||nodeQ==NULL) return false;
            if (nodeP->val != nodeQ->val) return false;
            queP.push(nodeP->right);
            queQ.push(nodeQ->right);
            queP.push(nodeP->left);
            queQ.push(nodeQ->left);               
         }
         return true;
     }
    
};