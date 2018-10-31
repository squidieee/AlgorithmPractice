/*
902. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Example
Given root = {1,#,2}, k = 2, return 2.

Challenge
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Notice
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
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
    struct ReturnType
    {
        int n;
        int val;
        ReturnType(int n, int val)
        {
            this->n = n;
            this->val = val;
        }
    };
    
    /**
     * @param root: the given BST
     * @param k: the given k
     * @return: the kth smallest element in BST
     */
    int kthSmallest(TreeNode * root, int k) {
        ReturnType result = divideConquor(root, k);
        return result.val;
    }
    
    // compare number of nodes in left sub-tree with k: 
    // return the number of nodes under root, and value at kth node
    ReturnType divideConquor(TreeNode* root, int k)
    {
        if (root == NULL)
            return ReturnType(0, -1);
        ReturnType resultL = divideConquor(root->left, k);
        
        if (resultL.n >= k)
        {
            return resultL; // result in left; have been recorded
        }
        if (resultL.n + 1 == k)
        {
            return ReturnType(resultL.n + 1, root->val);
        }
        // n + 1 < k : result in right
        ReturnType resultR = divideConquor(root->right, k - resultL.n - 1);
        
        return ReturnType(resultL.n + resultR.n + 1, resultR.val);
    }


};