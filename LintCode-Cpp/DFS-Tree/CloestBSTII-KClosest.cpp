/*
901. Closest Binary Search Tree Value II
Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.

Example
Given root = {1}, target = 0.000000, k = 1, return [1].

Challenge
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?

Notice
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
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

 // Optimal Solution (O(k) + O(logn))
class Solution {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        vector<int> result;
        if (k==0||root==NULL) return result;
        
        // record nodes in the path to find close value in the tree;
        // put nodes smaller than target into a stack
        // put nodes larger than target into a stack
        stack<TreeNode*> small;
        stack<TreeNode*> large;
        traverseClosestPath(root, target, small, large);
        
        // iterate through small and large stack to find k closest
        while(result.size() < k)
        {
            // compare the difference
            if (small.empty())
            {
                result.push_back(large.top()->val);
                largeMoveNext(root, large); // equivalent to large++
                continue;
            }
            
            if (large.empty())
            {
                result.push_back(small.top()->val);
                smallMoveNext(root, small);
                continue;
            }
            
            if (abs(small.top()->val - target) > abs(large.top()->val - target))
            {
                result.push_back(large.top()->val);
                largeMoveNext(root, large);
            }
            else
            {
                result.push_back(small.top()->val);
                smallMoveNext(root, small);            
                
            }

        }
        
        return result;
        
    }
    
    void traverseClosestPath(TreeNode*  root, double T, stack<TreeNode*>& smallerThanT, stack<TreeNode*>& largerThanT)
    {
        if (root==NULL) return;
        if (root->val < T)
        {
            smallerThanT.push(root);
            traverseClosestPath(root->right, T, smallerThanT, largerThanT);
        }
        else
        {
            largerThanT.push(root);
            traverseClosestPath(root->left, T, smallerThanT, largerThanT);
        }
    }
    
    void smallMoveNext(TreeNode* root, stack<TreeNode*>& small)
    {
        TreeNode* node = small.top()->left;
        small.pop();
        while(node!=NULL)
        {
            small.push(node);
            node = node->right;
        }
    }
    
    void largeMoveNext(TreeNode* root, stack<TreeNode*>& large)
    {
        TreeNode* node = large.top()->right;
        large.pop();
        while(node!=NULL)
        {
            large.push(node);
            node = node->left;
        }
    }
    
    
};

// O(n + logn + logk)
class Solution1 {
public:
    /**
     * @param root: the given BST
     * @param target: the given target
     * @param k: the given k
     * @return: k values in the BST that are closest to the target
     */
    vector<int> closestKValues(TreeNode * root, double target, int k) {
        vector<int> kclosest;
        if (root==NULL || k == 0) return kclosest;
        
        vector<int> A;
        dfs(root, A);
        
        int start = findClosest(A, target);
        
        int left(start), right(start + 1);
        
        // find k closest
        while(kclosest.size() < k)
        {
            if (right > A.size() - 1)
            {
                kclosest.push_back(A[left]);
                left--;
                continue;
            }
            
            if (left < 0)
            {
                kclosest.push_back(A[right]);
                right++;
                continue;
            }
            
            if (abs(A[left] - target) > abs(A[right] - target))
            {
                kclosest.push_back(A[right]);
                right++;
            }
            else
            {
                 kclosest.push_back(A[left]);
                 left--;
            }
        }
        
        return kclosest;
    }
    
    // in-order traversal O(n)
    void dfs(TreeNode* node,  vector<int>& inorder)
    {
        if (node==NULL) return;
        dfs(node->left, inorder);
        inorder.push_back(node->val);
        dfs(node->right, inorder);
    }
    
    // find closest, return index
    int findClosest(vector<int>& A, double target)
    {
        int start(0), end(A.size()-1);
        while(start + 1 < end)
        {
            int mid = start + (end-start)/2;
            if (target > A[mid])
            {
                start = mid;
            }
            else if (target < A[mid])
                end = mid;
            else
                return mid;
        }
        
        return std::abs(A[start] - target) > std::abs(A[end] - target)? end : start;
    }
    
    

};