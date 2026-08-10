1143. Longest Common Subsequence
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.

RECURSIVE APPROACH:
TC: O(2^n * 2^n) and SC : O(n+m)  

class Solution {
public:
    int func(int ind1, int ind2, string &text1, string &text2){
        //base case
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        //recursive call
        if(text1[ind1] == text2[ind2]){

            return 1 + func(ind1 -1, ind2 -1, text1, text2);
        }

        return 0 + max( func(ind1 -1, ind2, text1, text2), func(ind1, ind2-1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        return func(n-1, m-1, text1, text2);
        
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

class Solution {
public:
    int func(int ind1, int ind2, string &text1, string &text2,  vector<vector<int>>&dp){
        //base case
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        //overlapping subproblem
        if(dp[ind1][ind2] != -1)  return dp[ind1][ind2];

        //recursive call
        if(text1[ind1] == text2[ind2]){

            return dp[ind1][ind2] =  1 + func(ind1 -1, ind2 -1, text1, text2, dp);
        }

        return  dp[ind1][ind2] =  0 + max( func(ind1 -1, ind2, text1, text2, dp), func(ind1, ind2-1, text1, text2, dp));

    }
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return func(n-1, m-1, text1, text2, dp);
        
    }
};

TABULATION APPROACH:

BEFORE MOVING TO THE SOLUTION WE NEED TO TAKE CARE OF THIS 
  if(ind1 < 0 || ind2 < 0){
            return 0;
        }
THE BASE CASE, IF WE NOTICE THIS IS DP[-1] AND DP[-1]  DOES NOT EXIST , SO WE NEED TO LEARN INDEX SHIFTING, BASICALLY ONE INDEX TO THE RIGHT, -1 BECOMES 0, 0 BECOMES 1 ......
USING INDEX SHIFTING RECUSIVE APPROACH AND MEMOIZATION APPROACH CAN ALSO BE SOLVED. FOR NOW WE WILL SOLVE TABULATION. IN LEETCODE, MEMOIZATION SOLUTION WITH INDEX SHIFTING IS PRESENT.

TC: O(n*m) and SC : O(n*m)

//--------------------WITH INDEX SHIFTING------------------ 
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        //BASE CASE
        for(int i =0; i<=m; i++) dp[0][i] = 0;
        for(int i =0; i<=n; i++) dp[i][0] = 0;


        for(int ind1 = 1; ind1<= n; ind1++){
            for(int ind2 = 1; ind2<=m; ind2++){

                if(text1[ind1-1] == text2[ind2-1]){

                  dp[ind1][ind2] =  1 + dp[ind1 -1][ind2 -1];
                }

                else dp[ind1][ind2] =  0 + max( dp[ind1 -1][ind2], dp[ind1][ind2-1]);
            }
        }
        
        return dp[n][m];
    }
};
