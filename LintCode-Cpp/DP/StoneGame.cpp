/* 
476. Stone Game

There is a stone game.At the beginning of the game the player picks n piles of stones in a line.

The goal is to merge the stones in one pile observing the following rules:

At each step of the game,the player can merge two adjacent piles to a new pile.
The score is the number of stones in the new pile.
You are to determine the minimum of the total score.

Example
Example 1:

Input: [3, 4, 3]
Output: 17
Example 2:

Input: [4, 1, 1, 4]
Output: 18
Explanation:
  1. Merge second and third piles => [4, 2, 4], score = 2
  2. Merge the first two piles => [6, 4]，score = 8
  3. Merge the last two piles => [10], score = 18
*/

class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        int N = A.size();
        if(N <= 1) return 0;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

        for(int i = N - 1; i >= 1; i--)
        {
            for(int j = i + 1; j <= N; j++)
            {
                int sumij = A[j-1];
                dp[i][j] = INT_MAX;
                for(int k = i; k < j; k++)
                {
                    sumij += A[k-1];
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
                dp[i][j] +=  sumij;
            }
        }
        
        return dp[1][N];
    }
};

// f[i][j] = min{f[i][k] + f[k+1][j]} + sum[i][j]
// f[i][j] represents subarray from i to j