/* 
108. Palindrome Partitioning II

Given a string s, cut s into some substrings such that every substring is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

Example
Example 1:

Input: "a"
Output: 0
Explanation: "a" is already a palindrome, no need to split.
Example 2:

Input: "aab"
Output: 1
Explanation: Split "aab" once, into "aa" and "b", both palindrome.
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        vector<vector<bool>> memoPalin(s.size(), vector<bool>(s.size(), false));
        
        for(int i = 0; i < s.size(); i++)
        {
            for(int j = i; j < s.size(); j++)
            {
                memoPalin[i][j] = isPalindrome(s, i, j);
            }
        }
        
        vector<int> dp(s.size(), 0);
        for(int i = 1; i < s.size(); i++)
        {
            if(!memoPalin[0][i])
            {
                dp[i] = dp[i-1] + 1;
                for(int j = 0; j < i; j++)
                {
                    if(memoPalin[j+1][i]) dp[i] = min(dp[i], dp[j] + 1);
                }
            }
            else
            {
                dp[i] = 0;
            }
        }
        
        return dp.back();
    }
    
    bool isPalindrome(string &s, int start, int end)
    {
        while(start <= end)
        {
            if(s[start] != s[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
};