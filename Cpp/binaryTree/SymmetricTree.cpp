/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively. 

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
    
    // iterative
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        deque<TreeNode*> nodes;
        nodes.push_back(root->left);
        nodes.push_back(root->right);        
        while(!nodes.empty()){
            TreeNode* nf = nodes.front();
            TreeNode* nb = nodes.back();        
            nodes.pop_front(); 
            nodes.pop_back();
            if(nf==NULL&&nb==NULL)
                continue;
            if (nb==NULL || nf==NULL )
                return false;
            if(nf->val != nb->val)
                return false;       
            nodes.push_front(nf->right);
            nodes.push_back(nb->left);               
            nodes.push_front(nf->left);
            nodes.push_back(nb->right);                  
    
        }
        return true;
    }
   /* // recursive
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return symetricHelper(root->left, root->right);
    }
    
    bool symetricHelper(TreeNode* left, TreeNode* right){
        if (left==NULL||right==NULL) return left==right; // two NULL: true; one NULL: false
        if (left->val!=right->val) return false; //no NULLs
        return symetricHelper(left->left, right->right) && symetricHelper(left->right, right->left);
    }
     */
};