//// THIS IS THE EXACT QUESTION OF LONGEST COMMON SUBSEQUENCE, THE ONLY DIFFERENCE IF IN COMMON SUBSEQUENCE WE GOT 2 STRINGS AND HERE WE HAVE ONLY ONE STRING. 
//SO WHAT WE ARE DOING IS, STORING THE STRING IN ANOTHER STRING AND REVERSING IT. NOW EXACT SAME CODE

LEETCODE 516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".


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
    int longestPalindromeSubseq(string s1) {
        
        int n = s1.length();

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        return func(n-1, n-1, s1, s2);
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

class Solution {
public:
        int func(int ind1, int ind2, string &text1, string &text2, vector<vector<int>>&dp){
        //base case
        if(ind1 < 0 || ind2 < 0){
            return 0;
        }

        //overlapping subproblem
        if(dp[ind1][ind2] != -1)  return dp[ind1][ind2];

        //recursive call
        if(text1[ind1] == text2[ind2]){

            return  dp[ind1][ind2] = 1 + func(ind1 -1, ind2 -1, text1, text2, dp);
        }

        return dp[ind1][ind2] = 0 + max( func(ind1 -1, ind2, text1, text2, dp), func(ind1, ind2-1, text1, text2, dp));
    }
    int longestPalindromeSubseq(string s1) {
        
        int n = s1.length();

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<vector<int>>dp(n, vector<int>(n, -1));

        return func(n-1, n-1, s1, s2, dp);
    }
};

TABULATION APPROACH:
TC: O(n*m) and SC : O(n*m)

class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        
        int n = s1.length();

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));

        //base case
        for(int i =0; i<=n; i++) dp[0][i] = 0;
        for(int j =0; j<=n; j++) dp[j][0] = 0;

        //nested loop

        for(int i=1; i<=n; i++){
            for(int j =1; j<=n; j++){

                if(s1[i-1] == s2[j-1]){

                  dp[i][j] = 1 + dp[i -1][j -1];
                }

                  else dp[i][j] = 0 + max(dp[i -1][j], dp[i][j-1]);

                }
             }

             return dp[n][n];
    }
};
