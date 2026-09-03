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
