LEETCODE 509: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Approach 1: Can be solved using recursion

Approach 2: Solved using memoization
TC : O(n) and SC : O(n)+ O(n) {recursion stack + dp array}

int fib_using_dp(int n, vector<int>& dp){
        //base case
        if(n == 1) return 1;
        if(n == 0)  return 0;

        //sub problem
        if(dp[n] != -1)  return dp[n];

        return dp[n] = fib_using_dp(n-1, dp) + fib_using_dp(n-2, dp);

    }
    int fib(int n) {
        vector<int>dp(n+1, -1);

       return fib_using_dp(n, dp);
    }
};

OPTIMAL APPOACH :
TC : O(n) and SC : O(1)

 int fib(int n) {

       //edge case 
       if(n<= 1)  return n;

       int prev2 =0;
       int prev = 1;

       for(int i=2; i<= n; i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;

       }

       return prev;
    }
