LEETCODE 70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

TRICK TO SOLVE:
1. TRY TO REPRESENT PROBLEM IN TERMS OF INDEX.
2. DO ALL POSSIBLE STUFFS ON THAT INDEX ACCORDING TO THE PROBLEM STATEMENT.
3. SUM ALL STUFFS -> COUNT ALL WAYS <-MOST IMPORTANT
4. MIN(OF ALL STUFFS) -> IF THE QUESTION SAYS FIND MIN OF ALL STUFFS.
5. MAX(OF ALL STUFFS) -> IF THE QUESTION SAYS FIND MAX OF ALL STUFFS.
 
RECURSIVE APPROACH:
TC : O(2^n) and SC : O(1)
int climbStairs(int n) {

        //base case
        if(n <= 2)  return n;

        //recursive call
        return climbStairs(n-1) + climbStairs(n-2);
        
    }

DYNAMIC PROGRAMMING APPROACH:
TC : O(n) and SC : O(n)

     int climbStairs(int n) {

        vector<int>dp(n+1, -1);

        //base case
        dp[0] = 1;
        dp[1] = 1;

        //fill the dp array using bottom-up approach

        for(int i=2; i<= n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

