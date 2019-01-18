/*
242. Convert Binary Tree to Linked Lists by Depth
Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

Example
Given binary tree:

    1
   / \
  2   3
 /
4
return

[
  1->null,
  2->3->null,
  4->null
]

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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        vector<ListNode*> result;
        if (root == nullptr) return result;
        dfs(root, 0, result);
        return result;
    }
    
    /* BFS */
    vector<ListNode*> bfs(TreeNode* root) {
        vector<ListNode*> result;
        if (root == nullptr) return result;
        
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int len = que.size();
            ListNode dummy;
            ListNode* prevListNode = &dummy;
            
            for(int i = 0; i < len; i++)
            {
                TreeNode* cTreeNode = que.front();
                que.pop();
                
                /* convert to ListNode */
                prevListNode->next = new ListNode(cTreeNode->val);
                prevListNode = prevListNode->next;

                /* prepare next level */
                if (cTreeNode->left != nullptr) que.push(cTreeNode->left);
                if (cTreeNode->right != nullptr) que.push(cTreeNode->right);
            }
            result.push_back(dummy.next);
        }
        return result;
    }    
    // make sure line 89 can not be written as: ListNode node(cTreeNode->val);
    // because the initialized instance will be released in the next iteration!
    
    /* DFS */
    // record the depth of current node, add the node to result using depth as index
    // go left, go right if not null
    void dfs(TreeNode* root, int depth, vector<ListNode*>& result)
    {
        if (root == NULL) return;
        
        ListNode* listNode = new ListNode(root->val);
        if (result.size() <= depth) 
            result.push_back(listNode);
        else
        {
            listNode->next = result[depth];
            result[depth] = listNode;
        }
        
        dfs(root->right, depth + 1, result);
        dfs(root->left, depth + 1, result);
    }
};