//THIS IS EXACTLY THE SAME CODE OF BEST_TIME_TO_BUY_AND_SELL_STOCK_III JUST THE QUESTION IS MODIFIED BY WORDS
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


MEMOIZATION APPROAACH :
TC : O(n*2*k) and SC : O(n*2*k) + O(n)

class Solution {
public:
    int func(int ind, int buy, int cap, vector<int>&prices, int n,  vector<vector<vector<int>>>&dp){
        //base 
        if(cap == 0)  return 0;
        if(ind == n) return 0;

        //overlapaping condition
        if(dp[ind][buy][cap] != -1)  return dp[ind][buy][cap];

        //recursive calls
        if(buy == 1){
            return dp[ind][buy][cap] =  max(-prices[ind] + func(ind + 1, 0, cap, prices, n, dp), 
                            0 + func(ind +1, 1, cap, prices, n, dp));  
        }

        return dp[ind][buy][cap] = max (prices[ind] + func(ind +1, 1, cap-1, prices, n, dp), 
                    0 + func(ind +1, 0, cap, prices, n, dp)); 
    }


    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        //memoization
        //TC : n*2*k
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

        return func(0, 1, k, prices, n, dp);
    }
};

TABULATION APPROACH:
TC: O (n*2*k) and SC : O(n *2*k)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        //Tabulation
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        //nested loops
        for(int ind = n-1; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1; buy ++){
                for(int cap = 1; cap <= k; cap++){
                     if(buy == 1){
                        dp[ind][buy][cap] =  max(-prices[ind] + dp[ind + 1][0][cap], 
                                        0 + dp[ind +1][1][cap]);  
                    }

                    else{
                        dp[ind][buy][cap] = max (prices[ind] + dp[ind +1][1][cap-1], 
                                0 + dp[ind +1][0][cap]); 
                    }  
                }
            }
        }

        return dp[0][1][k];
    }
};

Space Optimizatio Approach:
TC : O(n*2*k) and SC : O(1)

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();

        //Space optmization
        vector<vector<int>> after(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));


        //nested loops
        for(int ind = n-1; ind >= 0 ; ind--){
            for(int buy = 0 ; buy <= 1; buy ++){
                for(int cap = 1; cap <= k; cap++){
                     if(buy == 1){
                        curr[buy][cap] =  max(-prices[ind] + after[0][cap], 
                                        0 + after[1][cap]);  
                    }

                    else{
                        curr[buy][cap] = max (prices[ind] + after[1][cap-1], 
                                0 + after[0][cap]); 
                    }  
                }
            }

            after = curr;
        }

        return after[1][k];
    }
};
