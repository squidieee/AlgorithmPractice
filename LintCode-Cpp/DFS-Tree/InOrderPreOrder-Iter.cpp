/*
67. Binary Tree Inorder Traversal
Given a binary tree, return the inorder traversal of its nodes' values.

Example
Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3
 

return [1,3,2].

Challenge
Can you do it without recursion?
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        vector<int> vals;
        stack<TreeNode*> nodes;
        
        while(root!=NULL)
        {
            nodes.push(root);
            root = root->left;
        }        
        
        while(!nodes.empty())
        {
            TreeNode* node = nodes.top();
            vals.push_back(node->val);
            nodes.pop();
            
            if (node->right != NULL)
            {
                node = node->right;
                while(node != NULL)
                {
                    nodes.push(node);
                    node = node->left;
                }
            }
        }
        
        return vals;
    }
};

/*
66. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.

Example
Example 1:

Input：{1,2,3}
Output：[1,2,3]
Explanation:
   1
  / \
 2   3
it will be serialized {1,2,3}
Preorder traversal
Example 2:

Input：{1,#,2,3}
Output：[1,2,3]
Explanation:
1
 \
  2
 /
3
it will be serialized {1,#,2,3}
Preorder traversal
Challenge
Can you do it without recursion?

Notice
The first data is the root node, followed by the value of the left and right son nodes, and "#" indicates that there is no child node.
The number of nodes does not exceed 20.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Preorder in ArrayList which contains node values.
     */
     
    vector<int> preorderTraversal(TreeNode * root) {
        stack<TreeNode*> stk;
        vector<int> result;
    
        TreeNode* node = root;
        while(node != NULL)
        {
            stk.push(node);
            result.push_back(node->val);
            node = node->left;
        }
        
        while(!stk.empty())
        {
            node = stk.top();
            stk.pop();
            
            if(node->right != NULL)
            {
                node = node->right;
                while(node != NULL)
                {
                    stk.push(node);
                    result.push_back(node->val);
                    node = node->left;                    
                }
            }
        }
        
        return result;
    }
    
    /*  // recursion
    vector<int> preorderTraversal(TreeNode * root) {
        vector<int> result;
        dfs(root, result);
        return result;
    }
    
    void dfs(TreeNode * node, vector<int>& result)
    {
        if (node == NULL) return;
        
        result.push_back(node->val);
        dfs(node->left, result);
        dfs(node->right, result);
    }
    */
};