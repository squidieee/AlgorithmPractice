/* 
752. Rogue Knight Sven

In material plane "reality", there are n + 1 planets, namely planet 0, planet 1, ..., planet n.
Each planet has a portal through which we can reach the target planet directly without passing through other planets.
But portal has two shortcomings.
First, planet i can only reach the planet whose number is greater than i, and the difference between i can not exceed the limit.
Second, it takes cost[j] gold coins to reach the planet j through the portal.
Now, Rogue Knight Sven arrives at the planet 0 with m gold coins, how many ways does he reach the planet n through the portal?

Example
Example 1:

Input:
n = 1
m = 1
limit = 1
cost = [0, 1]
Output:
1
Explanation:
Plan 1: planet 0 → planet 1
Example 2:

Input:
n = 1
m = 1
limit = 1
cost = [0,2]
Output:
0
Explanation:
He can not reach the target planet.
Notice
1 <= n <= 50, 0 <= m <= 100, 1 <= limit <= 50,0 <= cost[i] <= 100。
The problem guarantees cost [0] = 0, cause cost[0] does not make sense
*/

class Solution {
public:
    /**
     * @param n: the max identifier of planet.
     * @param m: gold coins that Sven has.
     * @param limit: the max difference.
     * @param cost: the number of gold coins that reaching the planet j through the portal costs.
     * @return: return the number of ways he can reach the planet n through the portal.
     */
    long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
        vector<vector<long long>> dp(n + 1, vector<long long>(m+1, 0));
        dp[0][m] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int k = 0; k <= m; k++)
            {
                for(int j = i - 1; j >= max(0, i - limit); j--)
                {
                    if(k + cost[i] <= m)  dp[i][k] += dp[j][k + cost[i]];
                }                
            }
        }
        
        long long ans = 0;
        for(int k = 0; k <= m; k++) ans += dp[n][k];
        return ans;
    }
    
    // dp[i][k]: num of ways of getting to portal i with k coins *after* paying for cost[i]
    // note ans = sum(dp[n][k])
};