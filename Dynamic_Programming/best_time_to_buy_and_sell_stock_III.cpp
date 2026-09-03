123. Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.


RECURSIVE APPROACH:
TC : O(2*n) and SC : O(n)<- ASS

class Solution {
public:
    int func(int ind, int buy, int cap, vector<int>& prices, int n){
         //base case 
        if(cap == 0)  return 0;
        if(ind == n)  return 0;

         //recurrsive calls
         if(buy == 0){
            return max( prices[ind] + func(ind+1, 1, cap-1, prices, n), 
                         0 + func(ind +1, 0, cap, prices, n));
         }

         return max (-prices[ind] + func(ind +1, 0, cap, prices,  n),
                        0 + func(ind +1, 1, cap, prices, n));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return func(0, 1, 2, prices, n);
    }
};

MEMOIZATION APPROACH :
TC : O(n * 2 * 3) and SC : O (n* 2* 3) + O(n) <- ASS

class Solution {
public:
    int func(int ind, int buy, int cap, vector<int>& prices, int n,  vector<vector<vector<int>>>&dp){
         //base case 
        if(cap == 0)  return 0;
        if(ind == n)  return 0;

        //overlapping sub problem
        if(dp[ind][buy][cap] != -1)  return dp[ind][buy][cap];

         //recurrsive calls
         if(buy == 0){
            return dp[ind][buy][cap] = max( prices[ind] + func(ind+1, 1, cap-1, prices, n, dp), 
                         0 + func(ind +1, 0, cap, prices, n, dp));
         }

         return dp[ind][buy][cap] = max (-prices[ind] + func(ind +1, 0, cap, prices,  n, dp),
                        0 + func(ind +1, 1, cap, prices, n, dp));
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        //memoization
        //dp of size n*2*3
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return func(0, 1, 2, prices, n, dp);
    }
};

TABULATION APPROACH :
TC : O(n * 2 * 3) and SC : O (n* 2* 3)
    
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //TABULATION

        int n = prices.size();
        
        //memoization
        //dp of size n*2*3
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
        //BASE CASE     <- WE CAN OMIT THESE BASE CASES COZ BOTH ARE RETURNING 0 AND DP VECTOR IS INITIALIZED WITH 0 SO ANYWAYS IT IS GOING TO RETURN 0
        // for(int ind = n ; ind >= 0; ind--){
        //     for(int buy = 0; buy <= 1; buy++){

        //         dp[ind][buy][0] = 0;

        //     }
        // }

        //  for(int buy = 0; buy <= 1; buy++){
        //     for(int cap = 1; cap <= 2; cap++){

        //         dp[n][buy][cap] = 0;

        //     }
        // }

        //NESTED LOOPS
        for(int ind = n-1 ; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){


                     if(buy == 0){
                        dp[ind][buy][cap] = max( prices[ind] + dp[ind+1][1][cap-1], 0 + dp[ind +1][0][cap]);
                    }

                    else {
                        dp[ind][buy][cap] = max (-prices[ind] + dp[ind +1][0][cap], 0 + dp[ind +1][1][cap]);

                       } 
                }
            }
        }


        return dp[0][1][2];
    }
};
