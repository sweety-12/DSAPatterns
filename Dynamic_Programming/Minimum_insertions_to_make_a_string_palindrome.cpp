APPROACH : THIS IS LITERALLY THE EXACT QUESTION - LONGEST PALINDROMIC SUBSEQUENCE. SO THE APPROACH IS WE NEED TO FIND MINIMUM NUMBER OF ELEMENTS TO MAKE A STRING A PALINDROME RIGHT? 
FOR THAT WE FIRST TO NEED TO HOW MANY CHARACTERS ARE THEIR WHICH ARE ALREADY IN PALINDROME. FOR REST WE NEED TO ADD THAT MUCH NUMBER OF ELEMENTS TO MAKE STRING PALINDROME. THAT'S IT.

ONLY CHANGE WE NEED IS : return n - longest_palindrome_subsequence(s)

RECURSIVE APPRAOCH:
TC: O(2^n) and SC : O(n)

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

    int minInsertions(string s) {
        
       int n = s.length();
       

       return n - longestPalindromeSubseq(s);
    }
};

MEMOIZATION APPROACH:
TC: O(n*n) and SC: O(n*n) + O(n+n)

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
    int minInsertions(string s) {
        
       int n = s.length();
       
       
       return n - longestPalindromeSubseq(s);
    }
};


TABULATION APPRAOCH:
TC: O(n*n) and SC : O(n*n)
    
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
    
    int minInsertions(string s) {
        
       int n = s.length();
       

       return n - longestPalindromeSubseq(s);
    }
};





