LEETCODE 115: Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

RECURSIVE APPROACH:
TC: O(2^n * 2^m) and SC : O(n+m)

class Solution {
public:
    int func(int i, int j, string &s, string &t ){

        //base case
        if(j<0)  return 1;
        if(i<0)  return 0;

        //recursive call
        if(s[i] == t[j]){
            //take
            return func(i-1, j-1, s, t) + func(i-1, j, s, t);
        }
        //not take
        return func(i-1, j, s, t);


        //find best
    }
    int numDistinct(string s, string t) {
        
        int n = s.length();
        int m = t.length();

        return func(n-1, m-1, s, t);
    }
};
