//THIS IS EXACTLY THE SAME CODE OF BEST_TIME_TO_BUY_AND_SELL_STOCK_III 
188. Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

RECURSIVE APPROACH:
TC: O (2^n) and SC : O(n) <-ASS
class Solution {
public:
    int func(int ind, int buy, int cap, vector<int>&prices, int n){
        //base 
        if(cap == 0)  return 0;
        if(ind == n) return 0;

        //recursive calls
        if(buy == 1){
            return   max(-prices[ind] + func(ind + 1, 0, cap, prices, n), 
                            0 + func(ind +1, 1, cap, prices, n));  
        }

        return  max (prices[ind] + func(ind +1, 1, cap-1, prices, n), 
                    0 + func(ind +1, 0, cap, prices, n)); 
    }


    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        return func(0, 1, k, prices, n);
    }
};
