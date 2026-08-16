LEETCODE 72. Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

//INTUTION BEHIND:  
  //func(i, j-1) <- INSERT 
  //func(i-1, j) <- DELETE
  //func(i-1, j-1) <- REPLACE
  

RECURSIVE APPROACH:
TC: O(2^n * 2^m) and SC : O(n+m)

class Solution {
public:
    int func(int i, int j, string &s1, string &s2){

        //base case
        if(i<0) return j+1;   //if i <0 then we need i+1 insertion to s1
        if(j<0) return i+1;   //if j <0 then we need i+1 deletion from s1

        //recursive call
        if(s1[i] == s2[j]){
            return 0 + func(i-1, j-1, s1, s2);
        }

        return 1 + min(func(i-1, j-1, s1, s2), min(func(i-1, j, s1, s2), func(i, j-1, s1, s2)));

    }
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();

        return func(n-1, m-1, s1, s2);
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

class Solution {
public:
    int func(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){

        //base case
        if(i<0) return j+1;   //if i <0 then we need i+1 insertion to s1
        if(j<0) return i+1;   //if j <0 then we need i+1 deletion from s1

        //overlapping sub problem
        if(dp[i][j] != -1)  return dp[i][j];


        //recursive call
        if(s1[i] == s2[j]){
            return dp[i][j] =  0 + func(i-1, j-1, s1, s2, dp);
        }

        return dp[i][j] = 1 + min(func(i-1, j-1, s1, s2, dp), min(func(i-1, j, s1, s2, dp), func(i, j-1, s1, s2, dp)));

    }
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return func(n-1, m-1, s1, s2, dp);
    }
};

TABULATION APPROACH:
TC: O(n*m) and SC : O(n*m)

class Solution {
public:
    int minDistance(string s1, string s2) {
        
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        //base case
        for(int i =0; i<=n ; i++){
            dp[i][0] = i;   //deleting i elements from s1 as j is exhausted
        }

        for(int j=0; j<=m ; j++){
            dp[0][j] = j;  //inserting j elements which matches which j as i is exhausted
        }

        //nested loop
        for(int i=1 ; i<=n; i++){
            for(int j =1; j<=m; j++){
                if(s1[i-1] == s2[j-1]){
                         dp[i][j] = dp[i-1][j-1];
                        }

                else {

                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                } 

            }
        }

        return dp[n][m];
    }
};
