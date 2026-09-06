309. Best Time to Buy and Sell Stock with Cooldown
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0


RECURSIVE APPROACH:

class Solution {
public:
    int func(int ind, int buy, vector<int>& prices, int n){

        //base case
        if(ind >= n)  return 0;

        //recursive call
        if(buy == 1){
            return max(-prices[ind] + func(ind + 1, 0, prices, n), 
                            0    + func(ind + 1, 1, prices, n));
        }

         return max(prices[ind] + func(ind + 2, 1, prices, n), 
                         0      + func(ind + 1, 0, prices, n));
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return func(0, 1, prices, n);
        
    }
};
 
MEMOIZATION APPROACH:

class Solution {
public:
    int func(int ind, int buy, vector<int>& prices, int n, vector<vector<int>>&dp){

        //base case
        if(ind >= n)  return 0;

        //overlapping case
        if(dp[ind][buy] != -1 ) return dp[ind][buy];

        //recursive call
        if(buy == 1){
            return dp[ind][buy] = max(-prices[ind] + func(ind + 1, 0, prices, n, dp), 
                            0    + func(ind + 1, 1, prices, n, dp));
        }

         return dp[ind][buy] = max(prices[ind] + func(ind + 2, 1, prices, n, dp), 
                         0      + func(ind + 1, 0, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return func(0, 1, prices, n, dp);
        
    }
};

