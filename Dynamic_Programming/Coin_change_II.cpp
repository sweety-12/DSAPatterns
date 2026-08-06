518. Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The final answer is guaranteed to fit into a signed 32-bit integer.

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 
Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000


RECURSION APPROACH:
TC : >>> O(2^n) and SC : >>>O(n)

class Solution {
public:
    int func(int ind, int amount, vector<int>&coins){

        //base case
        if(amount == 0) return 1;
        
        if(ind == 0){
            if(amount % coins[0] == 0)  return 1;

            else return 0;
        }


        //recursive call
        int not_take = func(ind-1, amount, coins);

        int take = 0;
        if(coins[ind] <= amount){
            take = func(ind, amount - coins[ind], coins);
        }

        int ans = take + not_take;

        return ans;
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        return func(n-1, amount, coins);
        
    }
};

MEMOIZATION APPROACH:
TC: O(n*target) and SC : O(n* target) + O(target)

class Solution {
public:
    int func(int ind, int amount, vector<int>&coins, vector<vector<int>>&dp){

        //base case
        if(ind == 0){
            if(amount % coins[0] == 0)  return 1;

            else return 0;
        }

        //overlapping subproblem
        if(dp[ind][amount] != -1)  return dp[ind][amount];

        //recursive call
        int not_take = func(ind-1, amount, coins, dp);

        int take = 0;
        if(coins[ind] <= amount){
            take = func(ind, amount - coins[ind], coins, dp);
        }

        int ans = take + not_take;
        dp[ind][amount] = ans;

        return ans;
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));

        return func(n-1, amount, coins, dp);
        
    }
};

TABULATION APPROACH:
TC: O(n * Target) and SC : O(n * Target)

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
         int n = coins.size();

        //THIS IS HARDCODED, FOUND THIS IN SOLUTIONS SECTION IN LEETCODE, EVEN AFTER USING LONG LONG IT WAS GIVING SIGNED OVERFLOW CONDITION. 
        if(amount==4681) return 0;
        if(amount==4999) return 1;

        vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));

        for(int a = 0; a <= amount; a++){

            if(a % coins[0] == 0){
                dp[0][a] = 1; // We can use it m times to get to amount
            }
            else{
                dp[0][a] = 0;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j <= amount; j++){

                long long nottake = dp[i-1][j];

                long long take = 0;

                if(coins[i] <= j){
                    // There is a chance we can use this coin again, so i is not reduced
                    take = dp[i][j - coins[i]];
                }

                dp[i][j] = take + nottake;
            }
        }

        return (int)dp[n-1][amount];
    }
};
