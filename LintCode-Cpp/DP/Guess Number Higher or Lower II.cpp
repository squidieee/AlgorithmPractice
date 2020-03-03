/* 
666. Guess Number Higher or Lower II

We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.
Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.

Example
Example1

Input: 10
Output: 16
Explanation:
Given n = 10, I pick 2.
First round:  You guess 7, I tell you that it's lower. You pay $7.
Second round: You guess 3, I tell you that it's lower. You pay $3.
Third round:  You guess 1, I tell you that it's higher. You pay $1.
Game over. 1 is the number I picked.
You end up paying $7 + $3 + $1 = $11.

Given n = 10, I pick 4.
First round:  You guess 7, I tell you that it's lower. You pay $7.
Second round: You guess 3, I tell you that it's higher. You pay $3.
Third round:  You guess 5, I tell you that it's lower. You pay $5.
Game over. 4 is the number I picked.
You end up paying $7 + $3 + $5 = $15.

Given n = 10, I pick 8.
First round:  You guess 7, I tell you that it's higher. You pay $7.
Second round: You guess 9, I tell you that it's lower. You pay $9.
Game over. 8 is the number I picked.
You end up paying $7 + $7 + $9 = $16.

So given n = 10, the answer is 16.
Example2

Input: 5
Output: 6
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: how much money you need to have to guarantee a win
     */
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int len = 2; len <= n; len++)
        {
            for(int start = 1; start <= n - len + 1; start++)
            {
                int end = start + len - 1;
                dp[start][end] = INT_MAX;
                for(int k = start; k < end; k++)
                {
                    dp[start][end] = min(dp[start][end], 
                                k + max(dp[start][k-1], dp[k+1][end]));
                }
            }
        }
        return dp[1][n];
    }
};

// dp[i][j] is the Min cost for worst case (a number picked causing max cost)
// in the range from i to j
// if we pick a number k >= i && <= j
// dp[i][j] = min (k + max(dp[i][k-1], dp[k+1][j])) among k

// need to fill in the table around the diagonal line first  