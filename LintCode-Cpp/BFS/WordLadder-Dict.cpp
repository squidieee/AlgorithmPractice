/*
120. Word Ladder
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Notice
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters. */

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
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        if (start == end) return 1;
        if (start.size()!=end.size()) return 0;
        
        // bfs
        queue<string> que;
        que.push(start);
        
        int len = 0;
        while(!que.empty())
        {
            int sz = que.size(); // nodes in this level
            len++;
            
            for (int i = 0; i < sz;i++) // each level
            {
                string s1 = que.front();
                que.pop();

                //O(26L * L)
                
                for (char c = 'a';c <= 'z';c++)
                {
                    for(int j = 0; j < start.size(); j++)
                    {
                        string s2 = s1;
                        s2[j] = c;
                        if (s2 == s1) continue;
                        
                        if (s2 == end) // O(L)
                            return ++len;
                        
                        if (dict.find(s2) == dict.end()) // O(1)
                            continue;

                        que.push(s2);
                        dict.erase(s2);
                    }
                }
                
                //O(L*N + L) L is length of word, N is size of dict
                /*
                if (isSimilar(s1, end) == 1) {len++;  return len;}
                
                unordered_set<string>::iterator it=dict.begin();
                while(it != dict.end()) // O(N)
                {
                    int result = isSimilar(s1, *it); O(L)
                    if(result == -1) // 
                        {
                            it++;
                            continue;
                        }

                    if(result == 1)
                        que.push(*it);
                    
                    it = dict.erase(it); // if allowed
                }
                */
            }
        }
        
        return 0;
    }
    
    int isSimilar(string s1, string s2)
    {
        int sameLetter(0);
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == s2[i]) sameLetter++;
        }
        
        if (sameLetter ==  s1.size()) return 0;
        if (sameLetter ==  s1.size()-1) return 1;
        return -1;
    }
};