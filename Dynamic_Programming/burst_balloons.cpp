312. Burst Balloons
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10

RECURSIVE APPROACH:
TC: exponential and SC : O(1)

class Solution {
public:
    int func(int i, int j, vector<int>& nums){

        //base case
        if(i > j) return 0;

        int maxi = INT_MIN;

        //recursive call
        for(int ind = i; ind <= j; ind++){

            int cost = (nums[i-1] * nums[ind] * nums[j+1]) + 
                       func(i, ind -1, nums) + func(ind+1, j, nums);

            maxi = max(maxi, cost);
        }
       return maxi;
    }
    
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        return func(1, n, nums);
        
    }
};


MEMOIZATION APPROACH:
TC: O(n^3) and SC : O(n^2)

class Solution {
public:
    int func(int i, int j, vector<int>& nums,  vector<vector<int>>&dp){

        //base case
        if(i > j) return 0;

        int maxi = INT_MIN;

        //overlapping subproblem
        if(dp[i][j] != -1)  return dp[i][j];

        //recursive call
        for(int ind = i; ind <= j; ind++){

            int cost = (nums[i-1] * nums[ind] * nums[j+1]) + 
                       func(i, ind -1, nums, dp) + func(ind+1, j, nums, dp);

            maxi = max(maxi, cost);
        }
       return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return func(1, n, nums, dp);
        
    }
};
