494. Target Sum
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1

RECURSIVE APPROACH:
TC : O(2^n) and SC : O(n)

class Solution {
public:
    int func(int ind, int target, vector<int>&nums){

        //base case
        if(ind == 0){

                if (target == 0 && nums[0] == 0)
                return 2;

            if (target == nums[0] || target == -nums[0])
                return 1;

            return 0;
        }

        //recursive call
        int add = func(ind -1, target + nums[ind], nums);

        int sub = func(ind -1, target - nums[ind], nums);

        return add + sub;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        return func(n-1, target, nums);
    }
};

MEMOIZATION APPROACH:
TC : O(N*Target + Sum) and SC : O( n*Target + Sum) + O(n)

class Solution {
public:
    int func(int ind, int target, int sum, vector<int>&nums, vector<vector<int>>&dp){
        //base case
        if(ind == 0){
                if (target == 0 && nums[0] == 0)
                return 2;

            if (target == nums[0] || target == -nums[0])
                return 1;

            return 0;
        }

        if(target > sum || target < -sum)
         return 0;

        //overlapping subproblem
        if(dp[ind][target + sum] != -1) return dp[ind][target + sum];

        //recursive call
        int add = func(ind -1, target + nums[ind], sum, nums, dp);

        int sub = func(ind -1, target - nums[ind], sum, nums, dp);

        return dp[ind][target + sum] = add + sub;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<int>>dp(n, vector<int>(2*sum + 1, -1));

        return func(n-1, target, sum, nums, dp);
    }
};


****PATTERN RECOGNITION****

IMPORTANT : ALTHOUGH THIS QUESTION IS SOLVED ABOVE USING RECUSION AND MEMOIZATION WITH DIFFERENT APPROACH BUT IF WE CHECK CAREFULLY THIS IS THE EXACT QUESTION "SUBSET SUM", divide the array in 2 subset (S1 - S2 = D)
QUESTION REFERENCE -> GFG : Partitions with Given Difference

BETTER TO SOLVE THIS QUESTION IN PATTERN RECOGNITION WAY TO STICK WITH THE PATTERN.

TABULATION APPROACH WITH THE PATTERN RECORGNITION
TC : O(N*Target) and SC : O(n*Target)

class Solution {
public:
    int tabulationApproach(vector<int>&arr, int n, int diff, int target,  vector<vector<int>>&dp){
        //base case
        
        if(arr[0] == 0)  dp[0][0] = 2;
        else dp[0][0] =1;
        
        if(arr[0] != 0 && arr[0] <= target)  dp[0][arr[0]] = 1;
        
        //nested loop
        for(int i = 1; i<n; i++){
            for (int j = 0 ; j<= target ; j++){
                
                int not_pick = dp[i-1][j];
                
                int pick = 0;
                if(arr[i] <= j){
                    pick = dp[i-1][j- arr[i]];
                }
                
                dp[i][j] = pick + not_pick;
                
            }
        }
        
        return dp[n-1][target];
    }

    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int target =0;
        int n = arr.size();
        
        int sum =0;
        for(int i=0; i<n ; i++){
            sum += arr[i];
        }
        
        //edge case -- OK THIS IS ONE OF THE EDGE CASE 
        //WE NEED TO TAKE CARE OF COZ (SUM - DIFF) /2 MUST NOT BE A DECIMAL VALUE 
        //AND BE AN POSITIVE INTERGER AS THIS NEEDS TO BE IN THE ARRAY
        
        if((sum - diff) %2 != 0 || (sum - diff) < 0) return 0; 
        
        target = (sum-diff)/2;   //THE TARGET WE ARE CALCULATING MUST ALSO BE POSITIVE
        
        vector<vector<int>>dp(n, vector<int>(target + 1, 0));
        
        return tabulationApproach(arr, n, diff, target, dp);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return countPartitions(nums, target);
    }
};
