/*

7. Serialize and Deserialize Binary Tree
Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.

Example
An example of testdata: Binary tree {3,9,20,#,#,15,7}, denote the following structure:

  3
 / \
9  20
  /  \
 15   7
Our data serialization use bfs traversal. This is just for when you got wrong answer and want to debug the input.

You can use other method to do serializaiton and deserialization.

Notice
There is no limit of how you deserialize or serialize a binary tree, LintCode will take your output of serialize as the input of deserialize, it won't check the result of serialize.
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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        string s;
        if (root==NULL) return s;
        
        queue<TreeNode*> que;
        que.push(root);
        s.append(to_string(root->val));
        
        while(!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            
            s.append(",");
            if (node->left!=NULL)
            {
                que.push(node->left);
                s.append(to_string(node->left->val));
            }
            else
                s+='#';
            s.append(",");     
            if (node->right!=NULL)
            {
                que.push(node->right);
                s.append(to_string(node->right->val));
            }
            else
                s+='#'; 
        }
        
        return s;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        if (data.empty()) return NULL;
        
        vector<string> vals = split(data, ',');
        TreeNode* root = new TreeNode(stoi(vals[0]));
        
        queue<TreeNode*> que;

        TreeNode* parent = root;
        
         
        for(int i = 1; i < vals.size(); i++)
        {
            TreeNode* node;

            if (vals[i]!="#")
            {
                node = new TreeNode(stoi(vals[i]));
                que.push(node);
            }
            else
            {
                node = NULL;
            }
                
            
            if (i%2!=0) // left child
            {
                parent->left = node;
            }
            else // right child
            {
                parent->right = node;
                
                if (que.empty())
                    break;

                parent = que.front();
                que.pop();
            }
        }
        
        return root;
    }

private: 
    vector<string> split(string& s, char delimiter)
    {
        vector<string> vals(1);
        int index(0);
        for(int i = 0; i < s.size(); i++)
        {
            if (s[i] == delimiter)
            {
                vals.push_back("");
                index++;
            }
            else
            {
                vals[index]+=s[i];
            }
        }
        return vals;
    }
};