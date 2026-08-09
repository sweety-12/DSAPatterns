GFG - Rod Cutting
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i (1-based Index). Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: The value of n is equal to the size of price array.

Example:

Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.
Input: price[] = [3]
Output: 3
Explanation: There is only 1 way to pick a piece of length 1.

Constraints:

1 ≤ price.size() ≤ 103
1 ≤ price[i] ≤ 106

RECURSIVE SOLUTION
TC:      SC :

class Solution {
  public:
    int func(int ind, int N, vector<int>&price){
        
        //base case
        if(ind == 0){
            return price[0] * N;
        }
        
        //recusive call
        int not_take = 0 + func(ind -1, N, price);
        
        int take =0;
        int rod_len = ind + 1;
        if(rod_len <= N){
            take = price[ind] + func(ind, N - rod_len, price);
        }
        
        return max(take, not_take);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        
        return func(n-1, n, price);
        
    }
};

MEMOIZATION SOLUTION
TC:      SC:

class Solution {
  public:
    int func(int ind, int N, vector<int>&price, vector<vector<int>>&dp){
        
        //base case
        if(ind == 0){
            return price[0] * N;
        }
        
        //overlapping subproblem
        if(dp[ind][N] != -1) return dp[ind][N];
        
        //recusive call
        int not_take = 0 + func(ind -1, N, price, dp);
        
        int take =0;
        int rod_len = ind + 1;
        if(rod_len <= N){
            take = price[ind] + func(ind, N - rod_len, price, dp);
        }
        
        return dp[ind][N] = max(take, not_take);
    }
    
    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        
        return func(n-1, n, price, dp);
        
    }
};

TABULATION APPROACH
TC:      SC:  

class Solution {
  public:

    int cutRod(vector<int> &price) {
        // code here
        
        int n = price.size();
        
        vector<vector<int>>dp(n, vector<int>(n+1, 0));
        
        //base case
        for(int i=0; i<=n; i++){
            
            dp[0][i] = price[0] * i;
        }
        
        //nested loop
        for(int ind = 1; ind<n; ind++){
            for(int N=0; N<=n ; N++ ){
                
                int not_take = 0 + dp[ind -1][N];
        
                int take =0;
                int rod_len = ind + 1;
                if(rod_len <= N){
                    take = price[ind] + dp[ind][N - rod_len];
                }
                
             dp[ind][N] = max(take, not_take);
            }
        }
        
        return dp[n-1][n];
    }
};
