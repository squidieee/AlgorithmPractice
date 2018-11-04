/*
86. Binary Search Tree Iterator
Design an iterator over a binary search tree with the following rules:

Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.
Example
For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]

   10
 /    \
1      11
 \       \
  6       12
Challenge
Extra memory usage O(h), h is the height of the tree.

Super Star: Extra memory usage O(1)
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
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */

// Solution 2: memory load O(h)
class BSTIterator {
public:
    /*
    * @param root: The root of binary tree.
    */
    
    BSTIterator(TreeNode * root) {
        TreeNode* node = root;
        
        while(node != NULL)
        {
            _nodes.push(node);
            node = node->left;
        }
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !_nodes.empty();
    }

    /*
     * @return: return next node O(1)
     */
    TreeNode * next() {
        if (_nodes.empty()) return NULL;
        
        TreeNode* cur = _nodes.top();
        TreeNode* result = cur;
        _nodes.pop();
        
        if (cur->right != NULL)
        {
            cur = cur->right;
            while(cur!=NULL)
            {
                _nodes.push(cur);
                cur = cur->left;
            }
        }
        
        return result;
    }
    
private:
    std::stack<TreeNode*> _nodes;
};

/*
class BSTIterator {
public:
    
    BSTIterator(TreeNode * root) {
        // do intialization if necessary
        _cur = 0;
        inOrderTraversal(root);
    }

    bool hasNext() {
        // write your code here
        if (_nodes.empty())
            return false;        
        return _cur <= _nodes.size() - 1;
    }


    TreeNode * next() {
        // write your code here
        if (_nodes.empty())
            return NULL;
        return _nodes[_cur++];
    }
    
private:
    void inOrderTraversal(TreeNode* root)
    {
        if (root==NULL) return;
        inOrderTraversal(root->left);
        _nodes.push_back(root);
        inOrderTraversal(root->right);
    }
    
    int _cur;
    std::vector<TreeNode*> _nodes;
};
*/
