300. Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.
Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104


Recursive approach:
TC: O(2^n) and SC : O(n)

class Solution {
public:
    int func(int ind, int prev, int n, vector<int>&nums){
        //base case
        if(ind == n) return 0;

        //recursive calls
        // not take
        int len =  0 + func(ind + 1, prev, n, nums);

        //take 
        if(prev == -1 || nums[ind] > nums[prev]){
            
            len =  max(len,  1 + func(ind + 1, ind, n, nums));
        }

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        return func(0, -1, n, nums);
    }
};

Memoization Approach:
TC : O(n*n) and SC: o(n*n) + O(n)

class Solution {
public:
    int func(int ind, int prev, int n, vector<int>&nums, vector<vector<int>>&dp){
        //base case
        if(ind == n) return 0;

        //overlapping case
        if(dp[ind][prev+1] != -1)   return dp[ind][prev+1];

        //recursive calls
        // not take
        int len =  0 + func(ind + 1, prev, n, nums, dp);

        //take 
        if(prev == -1 || nums[ind] > nums[prev]){
            
            len =  max(len,  1 + func(ind + 1, ind, n, nums, dp));
        }

        return dp[ind][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return func(0, -1, n, nums, dp);
    }
};

Tabulation Approach:
TC : O(n*n) and SC : O(n*n)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        //base case not needed coz dp array anyways returning 0
        
        //nested loop
        for(int ind = n-1; ind >=0; ind--){
            for(int prev = ind -1; prev >= -1; prev--){

                //not take
                 int len =  0 + dp[ind + 1][prev+1];

                //take 
                if(prev == -1 || nums[ind] > nums[prev]){
                    
                    len =  max(len,  1 + dp[ind + 1][ind+1]);
                }

                 dp[ind][prev + 1] = len;
            }
        }

        return dp[0][-1+1];
    }
};
