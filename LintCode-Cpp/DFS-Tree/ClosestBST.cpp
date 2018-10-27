/*
900. Closest Binary Search Tree Value
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Example
Given root = {1}, target = 4.428571, return 1.

Notice
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
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
     * @param root: the given BST
     * @param target: the given target
     * @return: the value in the BST that is closest to the target
     */
     
    int closestValue(TreeNode * root, double target) {
        return (int)(helper(root, target) + target);
    }
    
    // compare root->val with target, if >, compare further with leftsubtree; if <, compare further with right; if =, this is the one
    // return difference with sign
    // O(h), h is the height of Tree
    double helper(TreeNode * root, double target)
    {
        if (root == NULL) return numeric_limits<double>::max();
        
        double diff = root->val - target;
        
        if (diff > 0) // compare with left sub
        {
            double ldiff = helper(root->left, target);
            if (abs(diff) > abs(ldiff)) return ldiff;
        }
        else if (diff < 0)
        {
            double rdiff = helper(root->right, target);
            if (abs(diff) > abs(rdiff)) return rdiff;            
        }
        
        return diff;
    }
    
    /* Version0: Not optimized for Binary Search Tree. This is for general binary trees O(n)*/
/*
    struct ReturnValue
    {
        double diff;
        int val;
        ReturnValue(double diff, int val){ this->diff = diff; this->val = val; }
    };
    
    int closestValue(TreeNode * root, double target) {
        ReturnValue result = divideConquer(root, target);
        return result.val;
    }
    
    // compare subleft vs subright vs root: which has the smallest difference with target
    ReturnValue divideConquer(TreeNode* root, double target)
    {
        if (root == NULL) return ReturnValue(numeric_limits<int>::max(), 0);
        
        ReturnValue rleft = divideConquer(root->left, target);
        ReturnValue rright = divideConquer(root->right, target);
        
        double diff = abs(root->val - target);
        
        if (rleft.diff > rright.diff)
        {
            if (diff > rright.diff)
                return rright;
        }
        else
        {
            if (diff > rleft.diff)
                return rleft;            
        }
        
        return ReturnValue(diff, root->val);
    }
    */
};