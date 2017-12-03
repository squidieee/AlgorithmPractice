/* 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int N = prices.size();
        if (N < 2 || k < 1)
            return 0;
        int profit(0);
        
        /// Best Time to Buy and Sell Stock II
        if (k >= N-1)
        {
            for (int i = 1; i < N;i++)
            {
                if (prices[i] - prices[i-1] > 0)
                {
                    profit += prices[i] - prices[i-1];
                }
            }
            return profit;
        }
        
        /// if not sufficient transaction times
        vector<vector<int>> global(N); // global[i][j]: at ith day, transact j times
        vector<vector<int>> local(N); // local[i][j]: at ith day, transact j times, must sell at ith day
        
        global[0].resize(k+1,0); // you can always conduct zero transaction at any day, so has value from 0 to k
        local[0].resize(k+1,0);
       
        for(int i = 1; i < N; i++)
        {
            int diff = prices[i] - prices[i-1];

            global[i].resize(k+1,0);
            local[i].resize(k+1,0);
            
            for(int j = 1; j <= k; j++)
            {
                local[i][j] = max(local[i-1][j] + diff, global[i-1][j-1] + diff); 
                global[i][j] = max(local[i][j], global[i-1][j]); 
                
            }
        }
        return global[N-1][k];
    }
};