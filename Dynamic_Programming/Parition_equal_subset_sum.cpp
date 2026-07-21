416. Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

RECURSIVE APPROACH:
TC : O(2^n) and SC : O(n)

class Solution {
public:
    bool func(int ind, int target, vector<int>&nums){

        //base case
        if(target == 0) return true;

        if(ind == 0){
            if(nums[0] == target) return true;

            else return false;
        }

        //recursive function
        bool not_taken = func(ind -1, target, nums);

        bool taken = false;
        if(nums[ind] <= target){
            taken = func(ind-1, target - nums[ind], nums);
        }

        return taken | not_taken;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int target =0;
        int sum =0;

        for(int i=0; i<n; i++){
             sum += nums[i];
        }

        if(sum % 2 != 0)  return false; // odd summation can never be divided equally

        target = sum/2;

        return func(n-1, target, nums);

        
    }
};

MEMOIZATION APPROACH:
TC: O(n* target) and SC : O(n * target) + O(n)

class Solution {
public:
    bool func(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){

        //base case
        if(target == 0) return true;

        if(ind == 0){
            if(nums[0] == target) return true;

            else return false;
        }

        //checking for overlapping subproblem
        if(dp[ind][target] != -1)  return dp[ind][target];

        //recursive function
        bool not_taken = func(ind -1, target, nums, dp);

        bool taken = false;
        if(nums[ind] <= target){
            taken = func(ind-1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = taken | not_taken;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int target =0;
        int sum =0;

        for(int i=0; i<n; i++){
             sum += nums[i];
        }

        if(sum % 2 != 0)  return false; // odd summation can never be divided equally

        target = sum/2;


        //converting into memoization
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));

        return func(n-1, target, nums, dp);

        
    }
};


TABULATION APPROACH:
TC : O(n*target) and SC : O(n*target)

class Solution {
public:
    bool tabulation_func(int ind, int target, vector<int>&nums,  int n , vector<vector<bool>>&dp){

        //base case
        for(int i=0; i<n; i++){
            
            dp[i][0] = true;
        }

        if(nums[0] <= target){

            dp[0][nums[0]] = true;
        }

        //nested loop
        for(int i=1; i<n; i++){
            for(int tar = 1; tar <= target ; tar++){

                bool not_taken = dp[i-1][tar];

                bool taken = false;
                if(nums[i] <= tar){
                    taken = dp[i-1][tar - nums[i]];
                }

                dp[i][tar] = taken | not_taken;

            }
        }

        return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int target =0;
        int sum =0;

        for(int i=0; i<n; i++){
             sum += nums[i];
        }

        if(sum % 2 != 0)  return false; // odd summation can never be divided equally

        target = sum/2;


        //converting into memoization
        vector<vector<bool>>dp(n, vector<bool>(target + 1, 0));

        return tabulation_func(n-1, target, nums, n, dp);

    }
};
    
