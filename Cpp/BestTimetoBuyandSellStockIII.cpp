/* 
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        if(N<2)
            return 0;
        vector<int> profitL(N), profitR(N);
        
        int minL = prices[0];
        int maxR = prices[N-1];
        for (int i = 1; i < N; i++)
        {
            /// from left to right
            minL = min(minL, prices[i]);
            profitL[i] = max(profitL[i-1], prices[i] - minL);
            /// from right to left
            int j = N - 1 - i;
            maxR = max(maxR, prices[j]);
            profitR[j] = max(profitR[j+1], maxR - prices[j]);         
        }
        
        int maxsum(0);
        for (int i = 0; i < N;i++)
        { maxsum = max(maxsum, profitL[i] + profitR[i]);}
        return  maxsum;
    }
    

};