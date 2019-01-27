/*
107. Word Break
Given a string s and a dictionary of words dict, determine if s can be break into a space-separated sequence of one or more dictionary words.

Example
Given s = "lintcode", dict = ["lint", "code"].

Return true because "lintcode" can be break as "lint code".
*/

class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        if (s.size() < 1)
            return true;
        
        int max_len = 0;
        for(auto word: dict)
        {
            max_len = std::max(max_len, (int) word.size());
        }
        
        vector<int> found(s.size(), 0);
        return dfs(s, dict, 0, found, max_len);
    }
    
    bool dfs(string &s, unordered_set<string> &dict, int start, vector<int>& found, int max_len)
    {
        if (start > s.size() - 1) return true;
        
        for(int i = start; i < start + max_len; i++)
        {
            if ( dict.find(s.substr(start, i - start + 1)) != dict.end())
            {
                bool subResult;
                if (i >= s.size() - 1 || found[i + 1] == 0)
                    subResult= dfs(s, dict, i + 1, found, max_len);
                else
                    subResult = (found[i + 1] == 1);
                    
                if (subResult) 
                {
                    found[start] = 1;
                    return true;
                }
                else
                    found[i + 1] = -1;
            }
        }
        
        return false;
    }
};