/* 
192. Wildcard Matching
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: is Match?
     */
    bool isMatch(string &s, string &p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> visited (m + 1, vector<bool>(n + 1, false));
        vector<vector<bool>> memo (m + 1, vector<bool>(n + 1, false));
        
        return dfs(s, p, 0, 0, visited, memo);
    }
    
    // divide and conquer: compare string s and p 
    // take a char in s and p as s[i] and p[j], if p[j] != '*', compare s[i] and p[j]
    // if s[i] == p[j], i++, j++ and re-call this function, if not, return false
    // if p[j] == '*' -> assume '*' represents NULL -> j++, re-call this function; 
    // assume '*' is not NULL -> i++, re-call this function

    bool dfs(string &s, string &p, int si, int pi, vector<vector<bool>>& pvisited, vector<vector<bool>>& pmemo)
    {
        // if visited
        if (pvisited[si][pi])
            return pmemo[si][pi];
        
        // both reach the end
        if (si > (int) s.size() - 1 && pi > (int) p.size() - 1)
        {
            pmemo[si][pi] = true;
            pvisited[si][pi] = true;
            return true;
        }
            
        
        // one reaches the end
        if (si > (int) s.size() - 1 || pi > (int) p.size() - 1)
        {
            pvisited[si][pi] = true;
            if (pi <= (int) p.size() - 1 && p[pi] == '*')
            {
                pmemo[si][pi] = dfs(s, p, si, pi + 1, pvisited, pmemo);
                return pmemo[si][pi];
            }
            return false;
        }

        // both not reach the end: not visited
        bool result = false;
        if (s[si] == p[pi] || p[pi] == '?')
        {    
            result = dfs(s, p, si + 1, pi + 1, pvisited, pmemo);
        }
        else if (p[pi] == '*')
        {
            bool r1 = dfs(s, p, si + 1, pi, pvisited, pmemo);  // assuming '*' is not NULL string
            bool r2 = dfs(s, p, si, pi + 1, pvisited, pmemo);  // assuming '*' is a NULL string
            result = (r1 != 0) || (r2 != 0);
        }
        
        pvisited[si][pi] = true;
        pmemo[si][pi] = result;
        
        return result;
    }
    
};