//MY UNDERSTANDING FOR THIS QUESTION : 3 scenarios 
// 1. if s[i] == p[j] || s[i] = '?' simply do i-1, j-1
// 2. if s[i] == '*'  this represents sequence of characters that can be matched , first either we can skip the current character i.e (i-1, j) or take it i.e (i, j-1). Check out the recursive tree if forgot
// 3. if charcters does not match simply return false

//AMAZING QUESTION IT WAS. AS THIS IS THE LAST QUESTION FROM DP ON STRINGS. I CAN SAY HARD QUESTIONS NEEDS MODIFICATION ON RECURSIVE CALL VALA PART, ELSE IF IT IS MEDIUM LEVEL QUESTION, BARELY ANY CHANGES IN
//THE RECURSIVE PART, IT ONLY CHANGES IN BASE CASE PART

LEETCODE 44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

RECURSIVE CALL
TC: O(2^n * 2*m) and SC : O(n+m)

class Solution {
public:
    bool func(int i, int j, string &s, string &p){
        //base case
        if(i<0 && j <0) return true;
        if(i>= 0 && j < 0)  return false;
        if(i<0 && j>=0) {
            for(int temp = 0; temp <= j; temp++){
                if(p[temp] != '*') return false;
            }

            return true;
        }

        //recursive call
        //matches
        if(s[i] == p[j] || p[j] == '?'){
            return func(i-1, j-1, s, p);
        }

        //if having *
        if(p[j] == '*'){
            return func(i-1, j, s, p) || func(i, j-1, s, p);
        }

        //else case i.e s[i] != p[j]
        return false;
    }
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        return func(n-1, m-1, s, p);
        
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)

class Solution {
public:
    bool func(int i, int j, string &s, string &p,  vector<vector<int>>&dp){
        //base case
        if(i<0 && j <0) return true;
        if(i>= 0 && j < 0)  return false;
        if(i<0 && j>=0) {
            for(int temp = 0; temp <= j; temp++){
                if(p[temp] != '*') return false;
            }

            return true;
        }

        //overlapping subproblm
        if(dp[i][j] != -1)  return dp[i][j];

        //recursive call
        //matches
        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = func(i-1, j-1, s, p, dp);
        }

        //if having *
        if(p[j] == '*'){
            return dp[i][j] =  func(i-1, j, s, p, dp) || func(i, j-1, s, p, dp);
        }

        //ekse case i.e s[i] != p[j]
        return dp[i][j] =  false;
    }
    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>>dp(n, vector<int>(m, -1));
        return func(n-1, m-1, s, p, dp);
        
    }
};
