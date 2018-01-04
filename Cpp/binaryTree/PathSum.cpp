/* 
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    // breadth first search, iterative method
    /*
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;

        queue<TreeNode*> nodes;
        queue<int> residue;
        nodes.push(root);
        residue.push(sum - root->val);
        while(!nodes.empty()){
            int len = nodes.size();
            for(int i=0; i<len;i++)
            {
                TreeNode* n = nodes.front();
                nodes.pop();
                int res = residue.front(); 
                residue.pop();
                
                if (n->right==NULL && n->left==NULL&& res==0)
                    return true;
                if(n->left!=NULL){
                    nodes.push(n->left);
                    residue.push(res-n->left->val);
                }                
                if(n->right!=NULL){
                    nodes.push(n->right);                
                    residue.push(res-n->right->val);
                }

            }
        }
        return false;
    }
    */
    // depth first search, recursive method
    /*
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL)  return false;
        int res = sum - root->val;
        if (root->left==NULL && root->right==NULL && res ==0)
            return true;        
        return hasPathSum(root->left, res) || hasPathSum(root->right, res);
    }
    */
    // depth first search, iterative method
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==NULL)
            return false;
        stack<TreeNode*> nodes;
        stack<int> residue;
        nodes.push(root);
        residue.push(sum - root->val);
        while(!nodes.empty()){
            TreeNode* n = nodes.top();
            nodes.pop();
            int res = residue.top();
            residue.pop();
            if (n->left==NULL && n->right==NULL && res==0)
                return true;
            if (n->right!=NULL)
            {
                nodes.push(n->right);
                residue.push(res - n->right->val);
            }
            if (n->left!=NULL)
            {
                nodes.push(n->left);
                residue.push(res - n->left->val);
            }            
        }
        return false;
    }
};