/* 
154. Regular Expression Matching
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).


The function prototype should be:

bool isMatch(string s, string p)

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string &s, string &p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> memo (m+1, vector<bool>(n+1, false));
        vector<vector<bool>> visited (m+1, vector<bool>(n+1, false));
        
        return dfs(s, p, s.size() - 1, p.size() - 1, memo, visited);
    }
    // take a char from s and p at si and pi
    // if pi is not a '*' -> see if si == pi, si--, pi--
    // if pi is a '*' -> assume p* is NULL, pi - 2; assume p* is not NULL, si - 1
    bool dfs(string& s, string& p, int si, int pi, vector<vector<bool>>& memo, vector<vector<bool>>& visited)
    {
        if (visited[si+1][pi+1])
        {
            return memo[si+1][pi+1];
        }
        
        // both reach the end
        if (pi < 0)
            return si < 0;
            
        // source reach the end
        if (si < 0)
        {
            if (p[pi] == '*')
            {
                return dfs(s, p, si, pi - 2, memo, visited);
            }
            else
                return false;
        }
        
        bool result = false;
        
        // both not end
        if ( p[pi] == '*' ) // meet a '*'
        {
            if (pi < 1) // invalid input
                return false;
            bool result_notZero = compareChar(s[si], p[pi - 1]) && dfs(s, p, si - 1, pi, memo, visited);
            bool result_isZero = dfs(s, p, si, pi - 2, memo, visited);
            result = result_notZero || result_isZero;
        }
        else // not a star
        {
            result = compareChar(s[si], p[pi]) && dfs(s, p, si - 1, pi - 1, memo, visited);
        }
        
        visited[si+1][pi+1] = true;
        memo[si+1][pi+1] = result;
        return result;
    }
    
    bool compareChar(char s, char p)
    {
        return s==p || p == '.';
    }

    
};