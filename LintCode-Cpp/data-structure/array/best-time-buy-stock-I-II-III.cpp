/* 

149. Best Time to Buy and Sell Stock
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example
Given array [3,2,3,1,2], return 1.
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // [1] return 0
        // [2, 1] return 0
        // [..., prev, 3]: compare 3 with its prev, if increasing, keep the profit, if decreasing, see if it is time to buy
        if (prices.size() < 1) return 0;
        
        int profit = 0;
        int ibuy = 0;
        
        for(int i = 1; i < prices.size(); i++)
        {
            if (prices[i] >= prices[i-1])
            {
                profit = max(profit, prices[i] - prices[ibuy]);
            }
            else
            {
                ibuy = prices[i] > prices[ibuy] ? ibuy: i;
            }
        }
        
        return profit;
    }
};

/*
150. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example
Given an example [2,1,2,0,1], return 2
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;
        
        int profit(0);
        
        for(int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i-1])
                profit += prices[i] - prices[i-1];
        }
        
        return profit;
    }
};

/*
151. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Example
Given an example [4,4,6,1,1,4,2,5], return 6.

Notice
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // [] or [1] => 0
        // segment array into two halves:
        // [0, i] which contains the first transaction
        // [i+1, n-1] which contains the second transaction
        // our goal is to find:
        // for N intervals [0, i] N > i >= 0  
        // What is the best profit for each interval?
        // on the other hand for [i, N-1]
        // What is the best profit for each interval?
        // then we combine them together assuming segmented point i from 0 to N-1
        if (prices.size() < 2) return 0;
        
        int ibuy(0);
        vector<int> lprofit(prices.size(), 0);
        
        for(int i = 1; i < prices.size(); i++)
        {
            lprofit[i] = max(lprofit[i-1], prices[i] - prices[ibuy]);
            ibuy = prices[i] > prices[ibuy] ? ibuy: i;
        }
        
        int isell(prices.size() - 1);
        vector<int> rprofit(prices.size(), 0);
        
        for(int i = prices.size() - 2; i >=0; i--)
        {
            rprofit[i] = max(rprofit[i + 1], prices[isell] - prices[i]);
            isell = prices[i] > prices[isell] ? i: isell;
        }
        
        int profit(0);
        for (int i = 0; i < prices.size(); i++)
        {
            profit = max(profit, lprofit[i] + rprofit[i]);
        }
        
        return profit;

    }
};