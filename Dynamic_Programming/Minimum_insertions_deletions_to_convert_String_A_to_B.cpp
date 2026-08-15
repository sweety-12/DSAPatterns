APPROACH : THIS IS THE EXACT QUESTION - LONGEST COMMON SUBSEQUENCE. APPROACH IS FIND THE COMMON SUBSEQUENCES BETWEEN THE STRINGS AND SUBSTRACT WITH N + M

ONLY CHANGE IS:  return (N+M) - 2*longestCommonSubsequence(string s1, string s2) 

LEETCODE 583. Delete Operation for Two Strings
Attempted
Medium
Topics
premium lock icon
Companies
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:

Input: word1 = "leetcode", word2 = "etco"
Output: 4

RECURSIVE APPROACH:
TC: O(2^(n+m)) and SC : O(n+m)

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
    int minDistance(string word1, string word2) {
        
       int n = word1.length();
       int m = word2.length();

       return (n + m) - 2*longestCommonSubsequence(word1, word2);
    }

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

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
    int minDistance(string word1, string word2) {
        
       int n = word1.length();
       int m = word2.length();

       return (n + m) - 2*longestCommonSubsequence(word1, word2);
    }
