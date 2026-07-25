GFG : Count Subsets with Sum
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:

Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.
Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

IMPORTANT:  BASE CASE IS DIFFERENT SO MUST READ IT.

//base case
if(ind == 0){ 
if(target == 0 && arr[0] == 0) return 2;
  // basically this is handling the 0's case. 
//This means if target == 0 and arr[0] == 0 means then i ll count this in both pick and not pick and both will be 
//giving my ans hence return = 2;

if(target == 0)   return 1;  //this is same if becomes target ==0 at any index then i got my ans return 1 but i ll still traverse, 
//if i can find any 0's in the left side which is handled by first base case. 
 
if(arr[0] == target) return 1; //this says, if i have reached the last index i.e 0th and if my target == arr[0] 
  //then this will contribute to my ans by picking hence return 1.
  return 0;
}

RECURSIVE APPROACH:
TC: O(2^n) and SC : (n)  <- only auxilary recursive stack.

class Solution {
  public:
    int func(int ind, vector<int>&arr, int target){
        
        //base case
        // if(target == 0)  return 1;
        
        if(ind == 0){
          if(target == 0 && arr[0] == 0)
                   return 2;
            
                if(target == 0)
                    return 1;
            
                if(arr[0] == target)
                    return 1;
            
                return 0;
         }
        
        //recursive call
        int not_pick = func(ind -1, arr, target);
        
        int pick = 0;
        if(arr[ind] <= target){
            pick = func(ind -1, arr, target - arr[ind]);
        }
        
        int ans = pick + not_pick;
        
        return ans;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
         int n = arr.size();

        //if target is 0
        // if(target == 0)  return 0;
        // if(n == 0)  return 0;
        
        return func(n-1, arr, target);
    }
};

MEMOIZATION APPROACH:
TC: O(n*k) and SC : O(n*k) + O(n)

  int func(int ind, vector<int>&arr, int target, vector<vector<int>>&dp){
        
        //base case
        if(ind == 0){
          if(target == 0 && arr[0] == 0)
                   return 2;
            
                if(target == 0)
                    return 1;
            
                if(arr[0] == target)
                    return 1;
            
                return 0;
         }
         
         //overlapping sub problem
         if(dp[ind][target] != -1)  return dp[ind][target];
        
        //recursive call
        int not_pick = func(ind -1, arr, target, dp);
        
        int pick = 0;
        if(arr[ind] <= target){
            pick = func(ind -1, arr, target - arr[ind], dp);
        }
        
        int ans = pick + not_pick;
        
        return dp[ind][target] = ans;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();

        if(n == 0)  return 0;
        
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));
        
        return func(n-1, arr, target, dp);
    }

TABULATION APPROACH:
TC  : O(n*k) and SC : O(n*k)
 //TABULATION ME PANGA HO RHA HAI THODA, BUT KOI N SIKH JAEGI TU.....  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();

        if(n == 0)  return 0;
        
        vector<vector<int>>dp(n, vector<int>(target + 1, 0));
        
        //BASE CASE  
        if(arr[0] == 0)  dp[0][0] = 2;
        else dp[0][0] =1;
        
        if(arr[0] != 0 && arr[0] <= target)  dp[0][arr[0]] = 1;
        
        //nested loop
        for(int i=1; i <n; i++){
            for(int j =0 ; j<= target ; j++){
                
                int not_pick = dp[i-1][j];
                
                int pick = 0;
                if(arr[i] <= j){
                    pick = dp[i-1][j - arr[i]];
                }
                
                dp[i][j] = pick + not_pick;
                
            }
        }
        
        return dp[n-1][target];
    }
