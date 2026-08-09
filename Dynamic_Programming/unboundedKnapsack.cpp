GFG - Knapsack with Duplicate Items
Given a set of items, each with a weight and a value, represented by the array wt[] and val[] respectively. Also, a knapsack with a weight limit capacity.
Your task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.

Note: Each item can be taken any number of times.

Examples:

Input: val[] = [1, 1], wt[] = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
Input: val[] = [10, 40, 50, 70], wt[] = [1, 3, 4, 5], capacity = 8
Output: 110
Explanation: The optimal choice is to pick the 2nd element and the 4th element.
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element. Hence, total profit is 0.
Constraints:
1 ≤ val.size() = wt.size() ≤ 1000
1 ≤ capacity ≤ 1000
1 ≤ val[i], wt[i] ≤ 100

RECURSIVE APPROACH:
TC: Exponential or >> 2^n and SC : O(W)

class Solution {
  public:
    int func(int ind, int capacity, vector<int>&val, vector<int>&wt){
        
        //base case
        if(ind == 0){
            
            return (int)((capacity/wt[0])) * val[0];
        }
        
        //recursive call
        int not_take = 0 + func(ind -1, capacity, val, wt);
        
        int take = 0;
        if(wt[ind] <= capacity){
            
            take = val[ind] + func(ind, capacity - wt[ind], val, wt);
        }
        
        return max(take, not_take);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        
        return func(n-1, capacity, val, wt);
    }
};


MEMOIZATION APPROACH:
TC: O(N*W) and sc : O(N*W) + O(W)

class Solution {
  public:
    int func(int ind, int capacity, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        
        //base case
        if(ind == 0){
            
            return (int)((capacity/wt[0])) * val[0];
        }
        
        //overlapping subproblem
        if(dp[ind][capacity] != -1)  return dp[ind][capacity];
        
        //recursive call
        int not_take = 0 + func(ind -1, capacity, val, wt, dp);
        
        int take = 0;
        if(wt[ind] <= capacity){
            
            take = val[ind] + func(ind, capacity - wt[ind], val, wt, dp);
        }
        
        return dp[ind][capacity] = max(take, not_take);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>>dp(n, vector<int>(capacity + 1, -1));
        
        return func(n-1, capacity, val, wt, dp);
    }
};


TABULATION APPROACH:
TC : O(N*W) AND SC : O(N*W)

class Solution {
  public:

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        
        vector<vector<int>>dp(n, vector<int>(capacity + 1, 0));
        
        //base case
        for(int w =0; w<= capacity; w++){
            
            dp[0][w] = ((int)(w/wt[0])) * val[0];
        }
        
        //nested loop
        for(int i =1 ; i<n; i++){
            for(int w = 0; w <= capacity; w++){
                
                    int not_take = 0 + dp[i -1][w];
        
                    int take = 0;
                    if(wt[i] <= w){
                        
                        take = val[i] + dp[i][w - wt[i]];
                    }
                    
                    dp[i][w] = max(take, not_take);
            }
        }
        
        return dp[n-1][capacity];
    }
};
