GFG : Subset Sum Problem
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104

RECURSIVE APPROACH:
TC: O(2^n) and SC : O(n) <= Auxilary stack space

class Solution {
  public:
    bool func(int ind, int target, vector<int>&arr){
        
        //base case
        if(target == 0)  return true;
        
        if(ind == 0){
            if(arr[0] == target) return true;
            
            else return false;
        }
        
        //recursive call
        bool not_take = func(ind-1, target, arr);
        
        bool take = false;
        if(arr[ind] <= target){
            
            take = func(ind-1, target - arr[ind], arr);
        }
        
        
        return take | not_take;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        // code here
        int n = arr.size();
        
        //represent in terms of ind, target;
        return func(n-1, sum, arr);
    }
};


MEMOIZATION APPROACH:
TC: O(n*target) and SC : O(n* target) + O(n)

class Solution {
  public:
    bool func(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
        
        //base case
        if(target == 0)  return true;
        
        if(ind == 0){
            if(arr[0] == target) return true;
            
            else return false;
        }
        
        //overlapping subproblem 
        if(dp[ind][target] != -1)  return dp[ind][target];
        
        //recursive call
        bool not_take = func(ind-1, target, arr, dp);
        
        bool take = false;
        if(arr[ind] <= target){
            
            take = func(ind-1, target - arr[ind], arr, dp);
        }
        
        
        return dp[ind][target] = take | not_take;
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        // code here
        int n = arr.size();
        
        //converting to memoization
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        
        //represent in terms of ind, target;
        return func(n-1, sum, arr, dp);
    }
};

TABULATION APPROACH:
TC : O(n* target) and SC : O(n * target)

class Solution {
  public:
    
    bool isSubsetSum(vector<int>& arr, int target) {
        
        // code here
        int n = arr.size();
        
        //tabaulation approach
        vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));
        
        //base case - if target hits 0
        for(int i=0; i<n; i++){
            
            dp[i][0] = true;
        }
        
        //base case = if the index is 0 and target = arr[0]
        if(arr[0] <= target){
            dp[0][arr[0]] = true;
        }
        
        //fill the DP array iteratively
        for(int ind = 1; ind <n ; ind++){
            for(int tar = 1; tar <=  target ; tar++){
                
            bool not_taken = dp[ind -1][tar];
            
            bool taken = false;
            
            if(arr[ind] <= tar){
                taken = dp[ind - 1][tar - arr[ind]];
            }
            
             
            dp[ind][tar] = not_taken || taken;
            
           }
        }
        
        return dp[n-1][target];
    
    }
};
