/**
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        postorderHelper(root, vals);
        return vals;
    }
    void postorderHelper(TreeNode* root, vector<int>& vals){
        if(root==NULL) return;
        postorderHelper(root->left, vals);
        postorderHelper(root->right, vals);
        vals.push_back(root->val);
    }
    */
    // iterative1: preorder(root, left, right)->(root,right,left) then reverse = postorder(left, right, root)
    /*
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(root==NULL) return vals;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            TreeNode* n = nodes.top(); nodes.pop();
            vals.push_back(n->val);
            if(n->left!=NULL)
                nodes.push(n->left);
            if(n->right!=NULL)
                nodes.push(n->right);
        }
        return vector<int>(vals.rbegin(),vals.rend());
    } 
    // iterative2: stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(root==NULL) return vals;
        stack<TreeNode*> nodes;
        TreeNode* pre=NULL;
        TreeNode* n=root;
        while(!nodes.empty() || n!=NULL){
            while(n!=NULL){ // only push left child
                nodes.push(n);
                n = n->left;
            }            
            TreeNode* t = nodes.top();
            if(t->right!=NULL && t->right!=pre){
                n = t->right;
            }
            else{
                nodes.pop();
                vals.push_back(t->val);
                pre = t;
            }
        }
        return vals;
    }
     */
    // iterative3: stack
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vals;
        if(root==NULL) return vals;
        stack<TreeNode*> nodes;
        TreeNode* pre=NULL;
        TreeNode* n=root;
        while(!nodes.empty() || n!=NULL){
            if(n!=NULL){ // only push left child
                nodes.push(n);
                n = n->left;
            }
            else
            {
                TreeNode* t = nodes.top();
                if(t->right!=NULL && t->right!=pre){
                    n = t->right; // traversal to right
                }
                else
                {
                    nodes.pop();
                    vals.push_back(t->val);
                    pre = t;
                }
            }
        }
        return vals;
    }
};