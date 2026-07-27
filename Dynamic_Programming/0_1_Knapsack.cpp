GFG - 0 - 1 Knapsack Problem
Given two arrays, val[] and wt[], where each element represents the value and weight of an item respectively, and an integer W representing the maximum capacity of the knapsack (the total weight it can hold).

The task is to put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

Note: You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

RECURSIVE APPROACH:
TC : O(2^n) and SC : O(n)

class Solution {
  public:
    int func(int ind, int W, vector<int>&val, vector<int>&wt){
        
        //base case
        if(ind == 0){
            if(wt[0] <= W)  return val[0];
            
            return 0;
        }
        
        //recursive call
        
        int not_take = 0 + func(ind-1, W, val, wt);
        
        int take = 0;
        if(wt[ind] <= W){
            take = val[ind] + func(ind -1, W - wt[ind], val, wt);
        }
        
        int maxi = max(take, not_take);
        
        return maxi;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        return func(n-1, W, val, wt);
    }
};

MEMOIZATION APPROACH:
TC: O(n*W) and SC : O(n*W) + O(n)

class Solution {
  public:
    int func(int ind, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        
        //base case
        if(ind == 0){
            if(wt[0] <= W)  return val[0];
            
            return 0;
        }
        
        //overlapping subproblem
        if(dp[ind][W] != -1) return dp[ind][W] ;
        
        //recursive call
        
        int not_take = 0 + func(ind-1, W, val, wt, dp);
        
        int take = 0;
        if(wt[ind] <= W){
            take = val[ind] + func(ind -1, W - wt[ind], val, wt, dp);
        }
        
        int maxi = max(take, not_take);
        dp[ind][W] = maxi;
        
        return maxi;
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        
        vector<vector<int>>dp(n, vector<int>(W+1, -1));
        return func(n-1, W, val, wt, dp);
    }
};

TABULATION APPROACH:
TC " O(n*W) and SC : O(n*W)

class Solution {
  public:

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        
        vector<vector<int>>dp(n, vector<int>(W+1, 0));
        
        //base case
        for(int i=wt[0] ; i<= W; i++){
            
           dp[0][i] = val[0];
        }
        
        //nested loop
        for(int i=1; i<n; i++){
            for(int j = 0; j <= W; j++){
                
                int not_take = 0 + dp[i-1][j];
                
                int take =0;
                if(wt[i] <= j){
                    
                    take = val[i] + dp[i-1][j - wt[i]];
                    
                }
                
                dp[i][j] = max(take, not_take);
                
            }
        }
        
        return dp[n-1][W];
    }
};
