/*
651. Binary Tree Vertical Order Traversal
Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Example
Given binary tree {3,9,20,#,#,15,7}

   3
  /\
 /  \
 9  20
    /\
   /  \
  15   7
Return its vertical order traversal as:
[[9],[3,15],[20],[7]]

Given binary tree {3,9,8,4,0,1,7}

     3
    /\
   /  \
   9   8
  /\  /\
 /  \/  \
 4  01   7
Return its vertical order traversal as:
[[4],[9],[3,0,1],[8],[7]]
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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode * root) {
        if (root == NULL) return vector<vector<int>>();
        
        unordered_map<int, vector<int>> map;
        queue<TreeNode*> myQue;
        queue<int> cols;
        
        myQue.push(root);
        cols.push(0);
        
        int minCol = 0;
        while(!myQue.empty())
        {
            int len = myQue.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* curr = myQue.front();
                myQue.pop();
                int col = cols.front(); 
                cols.pop();
                minCol = std::min(minCol, col);
                
                // check if col exists
                if (map.find(col) == map.end())
                {
                    vector<int> newcol(1, curr->val);
                    map.insert({col, newcol});
                }
                else
                {
                    map.at(col).push_back(curr->val);
                }
                
                // add new nodes
                if (curr->left != NULL)
                {
                    myQue.push(curr->left);
                    cols.push(col - 1);
                }
                if (curr->right != NULL)
                {
                    myQue.push(curr->right);
                    cols.push(col + 1);
                }
            }
        }
        
        // convert map to result
        vector<vector<int>> result(map.size(), vector<int>());
        for(auto it = map.begin(); it != map.end(); it++)
        {
            result[-minCol + (it->first)] = it->second;
        }
        
        return result;
    }
    
};

// row: level
// column: distance to leftmost node
// if left = 0, then parent = 1 and right = 2

// bfs
// compute row: level
// compute column: left - 1, right + 1
// how to store:
// use a hash map to store columnwise
// root is 0
