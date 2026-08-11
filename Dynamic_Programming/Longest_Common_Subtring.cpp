Longest Common Substring
Given two strings s1 and s2, determine the length of the longest substring that appears in both strings.

Examples:

Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" with a length of 4.
Input: s1 = "abc", s2 = "acb"
Output: 1
Explanation: The longest common substrings are "a", "b", "c" all having length 1.
Input: s1 = "YZ", s2 = "yz"
Output: 0
Explanation: Comparison is case-sensitive, so 'Y' ≠ 'y' and 'Z' ≠ 'z'. Hence, no common substring exists.

RECURSIVE APPROACH:
TC: Exponential  AND SC : O(n+m)

class Solution {
  public:
    int func(int i, int j, string&s1, string&s2, int count, int &final_ans){
        
         // Base case
        if (i < 0 || j < 0) {
            final_ans = max(final_ans, count);
            return count;
        }

        if (s1[i] == s2[j]) {
            // Continue the current common substring
            func(i - 1, j - 1, s1, s2, count + 1, final_ans);
        }

        // Mismatch means the current substring ends.
        // But we still need to explore other alignments.
        func(i - 1, j, s1, s2, 0, final_ans);
        func(i, j - 1, s1, s2, 0, final_ans);

        final_ans = max(final_ans, count);
        return count;
        
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        
        int n = s1.length();
        int m = s2.length();
        
        int final_ans = 0;
        func(n-1, m-1, s1, s2, 0, final_ans);
        
        return final_ans;
    }
};

MEMOIZATION APPROACH:
TC: O(n*m) and SC : O(n*m) + O(n+m)
class Solution {
  public:
    int func(int i, int j, string&s1, string&s2, vector<vector<int>>&dp){
        
         // Base case
       if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j]) {
            dp[i][j] = 1 + func(i - 1, j - 1, s1, s2, dp);
        } 
        else {
            dp[i][j] = 0;
        }

        return dp[i][j];
        
    }
    int longCommSubstr(string& s1, string& s2) {
        // code here
        
          int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, func(i, j, s1, s2, dp));
            }
        }

        return ans;
    }
};

TABULATION APPROACH:
TC: O(n*m) and SC: O(n*m)

  int longCommSubstr(string& text1, string& text2) {
        // code here
        
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

        //BASE CASE
        for(int i =0; i<=m; i++) dp[0][i] = 0;
        for(int i =0; i<=n; i++) dp[i][0] = 0;
        
        int final_ans =0;

        for(int ind1 = 1; ind1<= n; ind1++){
            for(int ind2 = 1; ind2<=m; ind2++){

                if(text1[ind1-1] == text2[ind2-1]){
                  
                  dp[ind1][ind2] =  1 + dp[ind1 -1][ind2 -1];
                  final_ans = max(final_ans , dp[ind1][ind2]);
                }
                
                else dp[ind1][ind2] =  0 ;
            }
        }
        
        return final_ans;
     }
