LEETCODE 122. Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

RECURSIVE APPROACH:
TC: O(2^n) and SC : O(n)

class Solution {
public:
    int func(int ind, int buy, vector<int>&prices, int n){

        //base case

        if(ind == n) return 0;    //if i have reached end then i have nothing to buy not sell hence 0. Also even if i am holding any stock then i don't have any day to sell hence 0;

        int profit = 0;
        //recursive call
        if(buy == 1){    //means i can buy

            profit = max(-prices[ind] + func(ind +1 , 0, prices, n),
                         0 + func(ind + 1, 1, prices, n));
        }

        else {    //means i am currently holding one stock and i can only sell

            profit = max(prices[ind] + func(ind + 1, 1, prices, n), 0 + func(ind + 1, 0, prices, n));
        }


        //find best
        return profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        return func(0, 1, prices, n);
        
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

class Solution {
public:
    int func(int ind, int buy, vector<int>&prices, int n, vector<vector<long>>&dp){

        //base case

        if(ind == n) return 0;    //if i have reached end then i have nothing to buy not sell hence 0. Also even if i am holding any stock then i don't have any day to sell hence 0;

        //overlapping subproblem
        if(dp[ind][buy] != -1)  return dp[ind][buy];

        long profit = 0;
        //recursive call
        if(buy == 1){    //means i can buy

            profit = max(-prices[ind] + func(ind +1 , 0, prices, n, dp),
                         0 + func(ind + 1, 1, prices, n, dp));
        }

        else {    //means i am currently holding one stock and i can only sell

            profit = max(prices[ind] + func(ind + 1, 1, prices, n, dp), 0 + func(ind + 1, 0, prices, n, dp));
        }


        //find best
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<long>>dp(n, vector<long>(2, -1));

        return func(0, 1, prices, n, dp);
        
    }
};

TABULATION APPROACH:
TC: O(n*2) and SC : O(n*2)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<long>>dp(n+1, vector<long>(2, 0));

        dp[n][0] = dp[n][1] = 0;

        for( int ind= n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){

                long profit = 0;

                if(buy){
                    profit = max(- prices[ind] + dp[ind+1][0] , 0 + dp[ind+1][1]);
                }

                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }

                dp[ind][buy] = profit;
            }
        }

            return dp[0][1];        
    }
};

SPACE OPTIMIZATION
TC: O(n*2) and SC : O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

         // Create two arrays to store the profits ahead of the current position (0 for not holding, 1 for holding)
        vector<long> ahead(2, 0);
        vector<long> cur(2, 0);

        ahead[0] = ahead[1] = 0;

        long profit;

        for(int ind = n-1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){

                if(buy == 0){   //we caan buy stock

                    profit = max( 0 + ahead[0], -prices[ind] + ahead[1]);
                }

                if(buy == 1){   //we can sell the stock

                    profit = max(0 + ahead[1], prices[ind] + ahead[0]);
                }

                cur[buy] = profit;
            }

            ahead = cur;
        }

        return cur[0];
          
    }
};
