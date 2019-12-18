/*
1593. Construct Binary Tree from Preorder and Postorder Traversal

Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.

Example
Example 1:

Input：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
Output：[1,2,3,4,5,6,7]
Explanation：
     1
    / \
   2   3
  / \ / \
 4  5 6  7
Example 2:

Input：pre = [1,2,3,4], post = [3,2,4,1]
Output：[1,2,4,3]
Explanation：
   1
  / \
 2   4
 /
3
Notice
1 <= pre.length == post.length <= 30
pre[] and post[] are both permutations of 1, 2, ..., pre.length.
It is guaranteed an answer exists. If there exists multiple answers, you can return any of them.
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
    TreeNode * constructFromPrePost(vector<int> &pre, vector<int> &post) {
        unordered_map<int, int> preIdx;
        unordered_map<int, int> postIdx;
        for(int i = 0; i < pre.size(); i++)
        {
            preIdx[pre[i]] = i;
            postIdx[post[i]] = i;
        }
        
        return findRange(pre, post, preIdx, postIdx, 0, 0, pre.size());
    }
    
    TreeNode* findRange(vector<int> &pre, vector<int> &post, unordered_map<int, int> &preIdx, unordered_map<int, int> &postIdx, 
                        int preStart, int postStart, int len)
    {
        if (len == 0) return NULL;
        if (len == 1) return new TreeNode(pre[preStart]);
        
        int preEnd = preStart + len - 1;
        int postEnd = postStart + len - 1;
        
        int postRStart = postIdx[pre[preStart + 1]] + 1; // root of left subTree is the last element in the left subTree of post order
        
        TreeNode* leftChild = findRange(pre, post, preIdx, postIdx, preStart + 1, postStart, len - 1 - (postEnd - postRStart) );
        TreeNode* rightChild = NULL;
        
        // assuming there is always left sub tree 
        
        
        // empty right tree 
        if(postRStart != postEnd)
        {
            int preRStart = preIdx[post[postEnd - 1]]; // root of right subTree is the first element in the right subTree of pre order
            rightChild = findRange(pre, post, preIdx, postIdx, preRStart, postRStart, postEnd - postRStart);
        }
        
        TreeNode* root = new TreeNode(pre[preStart]);
        root->left = leftChild; 
        root->right = rightChild;
        
        return root;
    }
};

// for any node P with L subtree and R subtree
// preorder: [P, L[], R[]]
// postorder: [L'[], R'[], P]
// note that L' and L have the same nodes but in different order
// the order follows the same rule when the left child L is also a parent


// preStart + 1 is the root of left subTree
// postEnd - 1 is the root of right subTree 