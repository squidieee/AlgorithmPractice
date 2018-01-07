/**
 Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?


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
    // recursive
    /*
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        preorderHelper(root,  vals);
        return vals;
    }
    void preorderHelper(TreeNode* root, vector<int>& vals)
    {
        if(root==NULL)
            return;
        vals.push_back(root->val);
        preorderHelper(root->left, vals);
        preorderHelper(root->right, vals);
    }
    */
    // iterative
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(root==NULL) return vals;
        stack<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* n = root;
        while(!nodes.empty()){
            vals.push_back(n->val);
            if (n->right!=NULL) 
                 nodes.push(n->right);            
            if(n->left!=NULL){
                n = n->left;
            }
            else{
                n = nodes.top();
                nodes.pop();
            }
        }
        return vals;
    }    
};