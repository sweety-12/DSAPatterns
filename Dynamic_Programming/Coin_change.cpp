LEETCODE 322. Coin Change
Companies
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1

***IMPORTANT : IF THERE IS INFINITE SUPPLY OR MULTIPLE USE, TAKE WILL STAND AT THE SAME INDEX. ONLY, THE TARGET WILL BE REDUCED***

RECURSIVE APPROACH:
TC : >>> O(2^n) coz, we are not decreamenting the index on take      and SC: >> O(n) coz, we are not decreamenting the index on take

class Solution {
public:
    int func(int ind, int target, vector<int>&coins){
        
        //base case
        
        if(ind == 0){
            if(target % coins[ind] == 0) return target/coins[ind];

            else return 1e9;
        }

        //recusive call
        int not_take =  0 + func(ind -1, target, coins);

        int take = INT_MAX;
        if(coins[ind] <= target){
            
            take = 1 + func(ind, target - coins[ind], coins);
        }

        int mini = min(take, not_take);

        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int ans = func(n-1, amount , coins);

        if(ans == 1e9) return -1;

        return ans;
    }
};

MEMOIZATION APPROACH:
TC: O(n* Target) and SC : O(n*Target) + O(n)

class Solution {
  public:
    int func(int ind, int target, vector<int>&coins, vector<vector<int>>&dp){
        
        //base case
        if(ind == 0){
            if(target % coins[0] == 0) return target / coins[0];
            
            else return 1e9;
        }
        
        //overlapping subproblem
        if(dp[ind][target] != -1) return dp[ind][target];
        
        //recursive call
        int not_take = 0 + func(ind -1, target, coins, dp);
        
        int take = INT_MAX;
        if(coins[ind] <= target){
            
            take = 1 + func(ind, target - coins[ind], coins, dp);
        }
        
        return dp[ind][target] = min(take, not_take);
        
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        
        int ans = func(n-1, sum, coins, dp);
        
        if(ans == 1e9)  return -1;
        
        return ans;
    }
};

TABULATION APPROACH:
TC : O(n*Target) and SC : O(n* Target)

class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(sum + 1, 0));
        //base case
        for(int i = 0; i<= sum ; i++){
            if(i % coins[0] == 0) dp[0][i] = i/coins[0];
            
            else dp[0][i] = 1e9;
        }
        
        //nested loop
        
        for(int i= 1; i<n; i++){
            for(int j = 0 ; j<= sum ; j++){
                
                int not_take = 0 + dp[i -1][j];
        
                int take = INT_MAX;
                if(coins[i] <= j){
                    
                    take = 1 + dp[i][j - coins[i]];
                }
                
                dp[i][j] = min(take, not_take);
            }
        }
        if(dp[n-1][sum] == 1e9) return -1;
        
        return dp[n-1][sum];
    }
};
