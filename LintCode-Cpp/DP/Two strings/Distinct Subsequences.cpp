/* 
118. Distinct Subsequences

Given two strings S and T. Count the number of distinct subsequences of S which equals T.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not)

Example
Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation: You could remove any 'b' in S, so there are 3 ways to get T.
Example 2:

Input: S = "abcd", T = ""
Output: 1
Explanation: There is only 1 way to get T - remove all chars in S.
Challenge
Do it in O(n^2n
​2
​​ ) time and O(n) memory.

O(n^2n
​2
​​ ) memory is also acceptable if you do not know how to optimize memory.



*/

class Solution {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        if(T.empty()) return 1;
        vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));
        
        for(int i = 1; i <= S.size(); i++)
        {
            dp[i][1] = dp[i-1][1];
            if(S[i-1] == T[0]) dp[i][1] += 1;
        }
        
        for(int i = 1; i <= S.size(); i++)
        {
            for(int j = 2; j <= T.size(); j++)
            {
                dp[i][j] = dp[i-1][j];
                if(S[i-1] == T[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[S.size()][T.size()];
    }
};

// brutal force: 
// find all combination of subseq of S 
// and record num of combination equal to T 
// O(2^n), n is S's size

// TWO STRING DP PROBLEM:
// dp[i][j] is the answer of substr of S end at i and substring of T end at j
// i >= j

// if S[i] != T[j]: S[i] is not in subseq, so dp[i][j] = dp[i-1][j]
// else S[i] can appear in subseq, 
// so dp[i][j] = dp[i-1][j] (if we decide not to put it in subseq)
//               + dp[i-1][j-1] (if we decide to put it in subseq)